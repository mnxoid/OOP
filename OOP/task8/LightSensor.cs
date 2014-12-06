namespace task8
{
    class LightSensor : Sensor
    {
        
        public override string ToString()
        {
            return "";
        }
        public LightSensor(Room parent,int bV, int hV) :  base(bV, hV)
        {
            Parent = parent;
        }

        public override void InvBad(string s)
        {
            
        }
    }
}
