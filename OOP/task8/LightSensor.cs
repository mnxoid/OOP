using System;

namespace task8
{
    [Serializable]
    sealed class LightSensor : Sensor
    {
        private static int _nextid = 1;
        
        public LightSensor(Room parent,int bV, int hV) :  base(bV, hV)
        {
            Classname = "Light sensor";
            Id = _nextid;
            _nextid++;
            Parent = parent;
        }

        public override void InvBad(string s)
        {
            
        }
    }
}
