using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4Lily
{
    class A
    {
        public string Name;

        public void F()
        {
            Program.PrintA(this);
        }
        public A(string s)
        {
            Name = s;
        }
    }
}
