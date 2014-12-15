using System;

namespace task8
{
    [Serializable]
    class Camera : Device
    {
        private static int _nextid = 1;
        private readonly Room _parent;
        public delegate void Snap(string s);
        public event Snap OnShoot;
        public void Shoot()
        {
            OnShoot(_parent.Number + " : Snapshot acquired!");
        }
        public override string ToString()
        {
            return "MnxoidCorp. Camera: ID="+Id+"\n";
        }
        public Camera(Room parent)
        {
            Id = _nextid;
            _nextid++;
            _parent = parent;
            OnShoot += CommandPoint.Message;
        }
    }
}
