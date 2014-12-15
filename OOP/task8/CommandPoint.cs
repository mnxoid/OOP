using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace task8
{
    class CommandPoint
    {
        public static readonly Random Rnd;
        public static readonly Ticker Tck;
        public static readonly StreamWriter LogStream;
        public static void Message(string s)
        {
            Console.WriteLine(s+" - "+DateTime.Now);
            LogStream.WriteLine(s + " - " + DateTime.Now);
        }

        static CommandPoint()
        {
            Rnd = new Random();
            Tck = new Ticker();
            LogStream = File.CreateText(@".\log.txt");
        }
        static void Main()
        {
            Console.WriteLine("Welcome to MnxoidSecurity 0.0.1-pre-alpha!");
            Console.WriteLine("Press any key to create a building");
            Console.ReadKey();
            var b = new Building(Rnd.Next(1, 4));
            Console.WriteLine("Building created:");
            Console.WriteLine(b);
            Console.WriteLine("Press any key to start");
            Console.ReadKey();
            Tck.Active = true;
            Console.ReadKey();
            Tck.Active = false;
            //-------------------------------------
            const string path = @".\myfile.bin";
            Stream fs;
            try
            {
                fs = File.Create(path);
                var serializer = new BinaryFormatter();
                serializer.Serialize(fs, b);
                fs.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            try
             {
	            fs = File.OpenRead(path);
	            var deserializer = new BinaryFormatter();
	            var b1 = (Building)deserializer.Deserialize(fs);
                Console.WriteLine(b1);
                fs.Close();
             }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            Console.ReadKey();
        }
        public override string ToString()
        {
            return "MnxoidCorp. CommandPoint v0.0.1-pre-alpha";
        }
    }
}
