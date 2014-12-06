namespace task8
{
    class TemperatureSensor : Sensor
    {
        
        public override string ToString()
        {
            return "";
        }
        public override void InvBad(string s)
        {
            
        }
        public TemperatureSensor(Room parent ,int bV, int hV) :  base(bV, hV)
        {
            Parent = parent;
        }
    }
}
