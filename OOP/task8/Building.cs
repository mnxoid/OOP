using System.Linq;

namespace task8
{
    class Building
    {
        public Floor[] Floors;
        public override string ToString()
        {
            var ret =  "Floor number: "+Floors.Length+"\n";
            return Floors.Aggregate(ret, (current, f) => current + (f.ToString() + "\n"));
        }
        public Building(int k)
        {
            Floors = new Floor[k];
            for(var i = 0;i<Floors.Length;i++)
            {
                Floors[i] = new Floor(CommandPoint.Rnd.Next(2, 6));
            }
        }
    }
}
