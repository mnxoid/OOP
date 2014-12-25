namespace Project2
{
    public class Child
    {
        private readonly string _name;
        private readonly string _surname;
        public Child(string n, string s, int badDeeds, int goodDeeds)
        {
            _name = n;
            _surname = s;
            GoodDeeds = goodDeeds;
            BadDeeds = badDeeds;
        }

        public string Name
        {
            get { return _name; }
        }

        public string Surname
        {
            get { return _surname; }
        }

        public int GoodDeeds { get; private set; }
        public int BadDeeds { get; private set; }
        public Eatable EatGift { get; set; }
        public Uneatable UneatGift { get; set; }
        public override string ToString()
        {
            return Name + " " + Surname + " : " + GoodDeeds + " good deeds, " + BadDeeds + " bad deeds. Gifts: " +
                   EatGift + ", " + UneatGift;
        }
    }
}