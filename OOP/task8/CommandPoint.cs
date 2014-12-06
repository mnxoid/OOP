using System;

namespace task8
{
    class CommandPoint
    {
        public static readonly Random Rnd = new Random();
        public static readonly Ticker Tck = new Ticker();
        public static void Message(string s)
        {
            Console.WriteLine(s+" - "+DateTime.Now);
        }
        static void Main()
        {
            Console.WriteLine("Welcome to MnxoidSecurity 0.0.1-pre-alpha!");
            Console.WriteLine("Press any key to create a building");
            Console.ReadKey();
            var b = new Building(Rnd.Next(1, 4));
            Console.WriteLine("Building created:");
            Console.WriteLine(b.ToString());
            Console.WriteLine("Press any key to start");
            Console.ReadKey();
            Tck.Enable();
            Console.ReadKey();
            Tck.Disable();
        }
        public override string ToString()
        {
            return "";
        }
    }
}
