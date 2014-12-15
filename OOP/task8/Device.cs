using System;

namespace task8
{
    [Serializable]
    class Device
    {
        protected int Id;
        protected string Classname;
        public override string ToString()
        {
            return "MnxoidCorp. "+ Classname +": ID=" + Id + "\n";
        }
    }
}
