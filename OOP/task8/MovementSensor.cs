namespace task8
{
    class MovementSensor : Sensor
    {
        
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
        public override string ToString()
        {
            return "";
        }
        public MovementSensor(Room parent, int bV, int hV) :  base(bV, hV)
        {
            this.Parent = parent;
        }
    }
}
