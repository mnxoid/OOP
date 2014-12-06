using System.Linq;

namespace task8
{
    class Floor
    {
        static int _nextNum = 1;
        readonly int _number;
        public Room[] Rooms;
        public override string ToString()
        {
            var ret = "Floor " + _number + " :\n";
            return Rooms.Aggregate(ret, (current, r) => current + (r.ToString() + "\n"));
        }
        public Floor(int n) 
        {
            _number = _nextNum;
            _nextNum++;
            Rooms = new Room[n];
            for(var i=0; i<Rooms.Length;i++)
            {
                Rooms[i] = new Room(
                    CommandPoint.Rnd.Next(3,10),
                    CommandPoint.Rnd.Next(3,10),
                    CommandPoint.Rnd.Next(0, 100),
                    CommandPoint.Rnd.Next(0, 100),
                    CommandPoint.Rnd.Next(1,5),
                    CommandPoint.Rnd.Next(1,5),
                    CommandPoint.Rnd.Next(10,100)
                    );
            }
        }
    }
}
