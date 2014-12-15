using System;

namespace task8
{
    [Serializable]
    class Valve : Device
    {
        private static int _nextid;
        private bool _state;
        public void Turn()
        {
            _state = !_state;
        }

        public Valve()
        {
            Classname = "Valve";
            Id = _nextid;
            _nextid++;
        }

        static Valve()
        {
            _nextid = 1;
        }
    }
}
