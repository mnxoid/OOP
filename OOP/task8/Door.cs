using System;

namespace task8
{
    [Serializable]
    class Door : ITickable
    {
        private static int _nextid = 1;
        private  readonly int _id;
        public Room Parent { get; private set; }

        public void GotTick()
        {
            if (CommandPoint.Rnd.Next(1, 11) == 4 && DoorEvent != null ) DoorEvent(); //Chosen by fair dice roll, guaranteed to be random
        }
        public delegate void DoorSignal();
        public event DoorSignal DoorEvent;
        public Door(Room parent)
        {
            _id = _nextid;
            _nextid++;
            CommandPoint.Tck.TickEvent += GotTick;
            Parent = parent;
        }
        public override string ToString()
        {
            return "MnxoidCorp. Door: ID=" + _id + "\n";
        }
    }
}
