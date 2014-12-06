using System;

namespace _4Lily
{
    class Program
    {
        public static void PrintA(A obj)
        {
            Console.WriteLine(obj.Name);
        }
        static void Main()
        {
            A a1 = new A("A1");
            A a2 = new A("A2");
            a1.F();
            a2.F();
            Console.ReadKey();
        }
    }
}
