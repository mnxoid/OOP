using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task8
{
    class Lamp : Device
    {
        public int Luminosity;
        public override string ToString()
        {
            return "";
        }
        public Lamp(int st) : base()
        {
            Luminosity = st;
        }
    }
}
