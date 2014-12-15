using System;

namespace task8
{
    [Serializable]
    sealed class MovementSensor : Sensor
    {
        private static int _nextid = 1;
        public void DoorOpened()
        {
            InvBad(Parent.Number + " : A door was opened");
            if (Parent.Lamp.Luminosity == 0) InvAlert(2);
        }
        public override void InvAlert(int i)
        {
            base.InvAlert(i);
        }
        public override void InvBad(string s)
        {
            base.InvBad(s);
        }
        public MovementSensor(Room parent, int bV, int hV) :  base(bV, hV)
        {
            Classname = "Movement sensor";
            Id = _nextid;
            _nextid++;
            Parent = parent;
        }
    }
}
