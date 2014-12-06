namespace task8
{
    class Camera : Device
    {
        private readonly Room _parent;
        public delegate void Snap(string s);
        public event Snap OnShoot;
        public void Shoot()
        {
            OnShoot(_parent.Number + " : Snapshot acquired!");
        }
        public override string ToString()
        {
            return "";
        }
        public Camera(Room parent)
        {
            _parent = parent;
            OnShoot += CommandPoint.Message;
        }
    }
}
