using System;

namespace Project2
{
    class MainClass
    {
        static void Main()
        {
            Console.Write("Welcome, how many children do you need? ");
            int n = Int32.Parse(Console.ReadLine());
            Children cc = new Children(n);
            Mykolay.GiveGifts(cc);
            foreach (var child in cc)
            {
                Console.WriteLine(child);
            }
            Console.ReadKey();
        }
    }
}
