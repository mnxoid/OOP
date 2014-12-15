using System;
using System.Linq;

namespace task8
{
    [Serializable]
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

        public Building(Building b)
        {
            Floors = new Floor[b.Floors.Length];
            for (var i = 0; i < Floors.Length; i++)
            {
                Floors[i] = new Floor();
                Floors[i].Rooms = new Room[b[i].Rooms.Length];
                for (var j = 0; j < Floors[i].Rooms.Length; j++)
                {
                    Floors[i].Rooms[j] = new Room(b[i][j]);
                }
            }
        }

        public Floor this[int i]
        {
            get { return Floors[i]; }
            set { Floors[i] = value; }
        }
    }
}
