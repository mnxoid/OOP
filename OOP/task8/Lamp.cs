using System;

namespace task8
{
    [Serializable]
    class Lamp : Device
    {
        private static int _nextid = 1;
        
        public int Luminosity;
        public Lamp(int st)
        {
            Classname = "Lamp";
            Id = _nextid;
            _nextid++;
            Luminosity = st;
        }
    }
}
