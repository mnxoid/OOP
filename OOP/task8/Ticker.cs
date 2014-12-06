using System.Threading;

namespace task8
{
    class Ticker
    {
        private bool _active;
        private readonly Thread _tickThread;
        public delegate void Tick();
        public event Tick TickEvent;
        private void ThrFun()
        {
            while (_active)
            {
                if (TickEvent!=null) TickEvent();
                Thread.Sleep(3000);
            }
        }
        public Ticker()
        {
            _tickThread = new Thread(ThrFun);
        }
        public void Disable()
        {
            _active = false;
        }
        public void Enable()
        {
            _active = true;
            _tickThread.Start();
        }
    }
}
