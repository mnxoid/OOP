using System;

namespace task8
{
    [Serializable]
    sealed class TemperatureSensor : Sensor
    {
        private static int _nextid = 1;
        public override void InvBad(string s)
        {
            
        }
        public TemperatureSensor(Room parent ,int bV, int hV) :  base(bV, hV)
        {
            Classname = "Temperature sensor";
            Id = _nextid;
            _nextid++;
            Parent = parent;
        }
    }
}
