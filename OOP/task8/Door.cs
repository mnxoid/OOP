namespace task8
{
    class Door : Tickable
    {
        private Room _parent;
        public void gotTick()
        {
            if (CommandPoint.Rnd.Next(1, 11) == 4 && DoorEvent != null ) DoorEvent(); //Chosen by fair dice roll, guaranteed to be random
        }
        public delegate void DoorSignal();
        public event DoorSignal DoorEvent;
        public Door(Room parent)
        {
            CommandPoint.Tck.TickEvent += gotTick;
            _parent = parent;
        }
    }
}
