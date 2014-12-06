using System.Threading;

namespace task8
{
    class Room
    {
        private static int _nextnum = 1;
        public readonly int Number;
        //Room state:
        private int _temperature;
        //Room parameters:
        private Door[] Entrances;
        private readonly int _width;
        private readonly int _length;
        private int _windowCount;
        private readonly Valve[] _valves;
        private readonly Camera[] _cams;
        public Lamp Lamp;
        private TemperatureSensor[] tsensors;
        private LightSensor[] lsensors;
        private MovementSensor[] msensors;
        private int _fillPercentage;

        public int Area() { return _width * _length; }
        public delegate void Notification(string s);
        public event Notification OnBad;
        private void AlertHandler(int level)
        {
            OnBad("Room " + Number + " alert level : " + level);
            switch (level)
            {
                case 0:
                {
                    OnBad(Number + " : Lights on");
                    var temp = Lamp.Luminosity;
                    Lamp.Luminosity = 100;
                    Thread.Sleep(200);
                    OnBad(Number + " : Camshot");
                    foreach (var c in _cams) c.Shoot();
                    Lamp.Luminosity = temp;
                }
                    break;
                case 1:
                    OnBad(Number + " : Lights off");
                    Lamp.Luminosity = 0;
                    OnBad(Number + " : Valves activated");
                    foreach (var v in _valves) v.turn();
                    Thread.Sleep(200);
                    OnBad(Number + " : Valves deactivated");
                    foreach (var v in _valves) v.turn();
                    break;
                default:
                    OnBad(Number + " : Lights on");
                    Lamp.Luminosity = 100;
                    OnBad(Number + " : Camshot");
                    foreach (var c in _cams) c.Shoot();
                    Thread.Sleep(200);
                    OnBad(Number + " : Lights off");
                    Lamp.Luminosity = 0;
                    break;
            }
        }

        public static Room operator+(Room r, Sensor s)
        {
            s.EvAlert += r.AlertHandler;
            return r;
        }
        public static Room operator -(Room r, Sensor s)
        {
            s.EvAlert -= r.AlertHandler;
            return r;
        }
        public static Room operator +(Room r, Device s)
        {
            return r;
        }
        public static Room operator -(Room r, Device s)
        {
            return r;
        }
        public override string ToString()
        {
            return "";
        }
        public Room()
        {
            OnBad += CommandPoint.Message;
            Number = _nextnum;
            _nextnum++;
        }
        public Room(int w,int l, int light, int t, int wc, int dc, int fp) : this()
        {
            _width = w;
            _length = l;
            var ar = w * l;
            if (ar > 9) 
            {
                tsensors = new TemperatureSensor[ar / 9];
                for (var i = 0; i < tsensors.Length; i++) 
                {
                	tsensors[i] = new TemperatureSensor(this,80, 95);
                    object shit = this + tsensors[i];
                }
            } else {
                tsensors = new TemperatureSensor[1];
                tsensors[0] = new TemperatureSensor(this,90, 95);
                object shit = this + tsensors[0];
            }
            if (ar > 4)
            {
                _valves = new Valve[ar / 4];
                for (var i = 0; i < _valves.Length; i++) 
                {
                    _valves[i] = new Valve();
                }
            }
            else
            {
                _valves = new Valve[1];
                _valves[0] = new Valve();
            }
            if (ar > 16) 
            {
            	_cams = new Camera[ar / 16];
                for (var i = 0; i < _cams.Length; i++) _cams[i] = new Camera(this);
            }
            else 
            {
             	_cams = new Camera[1];
                _cams[0] = new Camera(this);
            }
            if (ar > 16)
            {
            	lsensors = new LightSensor[ar / 16];
                for (var i = 0; i < lsensors.Length; i++)
                {
                    lsensors[i] = new LightSensor(this, 200, 200);
                    object shit = this + lsensors[i];
                }
            }
            else
            {
	            lsensors = new LightSensor[1];
                lsensors[0] = new LightSensor(this,200,200);
                object shit = this + lsensors[0];
            }
            _temperature = t;
            _windowCount = wc;
            Entrances = new Door[dc];
            for (var i = 0; i < Entrances.Length; i++) Entrances[i] = new Door(this);
            msensors = new MovementSensor[dc];
            for (var i = 0; i < msensors.Length; i++) 
            {
            	msensors[i] = new MovementSensor(this,200, 200);
                object shit = this + msensors[i];
            }
            for (var i = 0; i < dc; i++) Entrances[i].DoorEvent += msensors[i].DoorOpened;
            Lamp = new Lamp(light);
            _fillPercentage = fp;
        }
    }
}
