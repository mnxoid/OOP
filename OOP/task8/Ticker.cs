using System.Threading;

namespace task8
{
    class Ticker
    {
        private bool _active;

        public bool Active
        {
            get { return _active; }
            set
            {
                _active = value;
                if (!value)
                {
                    if (_tickThread != null) _tickThread.Abort();
                }
                else
                {
                    if (_tickThread != null) _tickThread.Start();
                    else
                    {
                        _tickThread = new Thread(ThrFun);
                    }
                }
            }
        }
        private Thread _tickThread;
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
        
    }
}
