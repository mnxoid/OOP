using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task8
{
    class Valve : Device
    {
        private bool state = false;
        public void turn()
        {
            if (state) state = true; else state = false;
        }
        public override string ToString()
        {
            return "";
        }
    }
}
