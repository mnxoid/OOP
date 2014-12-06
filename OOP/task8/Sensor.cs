namespace task8
{
    class Sensor
    {
        protected Room Parent;
        public readonly int BadValue;
        public readonly int HorribleValue;
        public override string ToString()
        {
            return "";
        }
        protected int Sense()
        {
            return CommandPoint.Rnd.Next(0, 100);
        }
        public delegate void Notification(string s);
        public delegate void MyAlert(int level);
        public event Notification OnBad;
        public virtual void InvBad(string s)
        {
            OnBad(s);
        }
        public virtual void InvAlert(int i)
        {
            EvAlert(i);
        }
        public event MyAlert EvAlert;
        public void Run()
        {
            var val = Sense();
            if (val > HorribleValue) 
            {
                if (OnBad != null)
                {
                    OnBad(Parent.Number + " : Horrible value detected! : " + val);
                }
                if (EvAlert!=null)
                {
                	EvAlert(1);
                }
            }
            else if (val > BadValue) 
            {
                if (OnBad != null)
                {
                    OnBad(Parent.Number + " : Bad value detected! : " + val);
                }
                if (EvAlert!=null)
                {
                	EvAlert(0);
                }
            }
        }
        public Sensor()
        {
            OnBad += CommandPoint.Message;
            CommandPoint.Tck.TickEvent += Run;
        }
        public Sensor(int bV, int hV)
            : this()
        {
            HorribleValue = hV;
            BadValue = bV;
        }
        public Sensor(Room parent, int bV, int hV) : this()
        {
            HorribleValue = hV;
            BadValue = bV;
            Parent = parent;
        }
    }
}
