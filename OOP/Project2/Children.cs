using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Project2
{
    public class Children : IEnumerable<Child>
    {
        private static readonly string[] Names =
        {
            "Michael",
            "Lily",
            "Paul",
            "Nazar",
            "Mary",
            "Ann",
            "Kate",
            "George",
            "Oliver",
            "Carl",
            "Kenny",
            "Jason",
            "Joe",
            "Stacy",
            "David",
            "Sam",
            "Dean",
            "Barney",
            "Ted"
        };

        private static readonly string[] Surnames =
        {
            "Jackson",
            "Jobs",
            "Gates",
            "Torvalds",
            "Smith",
            "Holmes",
            "Winchester",
            "Cumberbatch",
            "Mosby"
        };

        public Children(int n)
        {
            var rnd = new Random();
            for (var i = 0; i < n; i++)
            {
                _children.Add(new Child(Names[rnd.Next(0,Names.Length)],Surnames[rnd.Next(0,Surnames.Length)],rnd.Next(0,100),rnd.Next(0,100)));
            }
        }

        private readonly List<Child> _children = new List<Child>();
        public IEnumerator<Child> GetEnumerator()
        {
            return _children.TakeWhile(o => o != null).GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
