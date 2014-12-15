using System;
using System.Linq;
using System.Threading;

namespace task8
{
    [Serializable]
    class Room
    {
        private static int _nextnum = 1;
        public readonly int Number;
        //Room state:
        private readonly int _temperature;
        //Room parameters:
        private readonly Door[] Entrances;
        private readonly int _width;
        private readonly int _length;
        private readonly int _windowCount;
        private readonly Valve[] _valves;
        private readonly Camera[] _cams;
        public Lamp Lamp;
        private readonly TemperatureSensor[] tsensors;
        private readonly LightSensor[] lsensors;
        private readonly MovementSensor[] msensors;
        private readonly int _fillPercentage;

        public int Area
        {
            get { return _width*_length; }
        }
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
                    foreach (var v in _valves) v.Turn();
                    Thread.Sleep(200);
                    OnBad(Number + " : Valves deactivated");
                    foreach (var v in _valves) v.Turn();
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

        public static Room operator !(Room r)
        {
            var rr = new Room(r._length,r._width,r.Lamp.Luminosity,r._temperature,r._windowCount,r.Entrances.Length,r._fillPercentage);
            return rr;
        }
        public override string ToString()
        {
            var ret = "Room " + Number + " :\n";
            ret += "Width: " + _width + "\n";
            ret += "Length: " + _length + "\n";
            ret += "Area: " + Area + "\n";
            ret += "Fill percentage: " + _fillPercentage + "\n";
            ret += "Temperature: " + _temperature + "\n";
            ret += "Luminosity: " + Lamp.Luminosity + "\n";
            ret += "Windows: " + _windowCount + "\n";
            ret += "Doors: " + Entrances.Length + "\n";
            ret = Entrances.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            ret += "Cameras: " + _cams.Length + "\n";
            ret = _cams.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            ret += "Valves: " + _valves.Length + "\n";
            ret = _valves.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            ret += "Temperature sensors: " + tsensors.Length + "\n";
            ret = tsensors.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            ret += "Light sensors: " + lsensors.Length + "\n";
            ret = lsensors.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            ret += "Movement sensors: " + msensors.Length + "\n";
            ret = msensors.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
            return ret;
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

        public Room(Room room) : 
            this(room._width,
            room._length,
            room.Lamp.Luminosity,
            room._temperature,
            room._windowCount,
            room.Entrances.Length,
            room._fillPercentage)
        {
        }
    }
}
