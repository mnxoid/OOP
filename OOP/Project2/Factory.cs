namespace Project2
{

    abstract class GiftFactory
    {
        public abstract Eatable CreateEatableGift();
        public abstract Uneatable CreateUneatableGift();
    }



    class GoodGiftFactory : GiftFactory
    {
        public override Eatable CreateEatableGift()
        {
            return new Sweet();
        }
        public override Uneatable CreateUneatableGift()
        {
            return new Toy();
        }
    }


    class BadGiftFactory : GiftFactory
    {
        public override Eatable CreateEatableGift()
        {
            return new BitterPill();
        }
        public override Uneatable CreateUneatableGift()
        {
            return new Stitch();
        }
    }

    public abstract class Gift
    {
        
    }

    public abstract class Eatable : Gift
    {
    }


    public abstract class Uneatable : Gift
    {
    }



    class Sweet : Eatable
    {
        public override string ToString()
        {
            return "Sweet";
        }
    }

    class Toy : Uneatable
    {
        public override string ToString()
        {
            return "Toy";
        }
    }


    class BitterPill : Eatable
    {
        public override string ToString()
        {
            return "Bitter pill";
        }
    }


    class Stitch : Uneatable
    {
        public override string ToString()
        {
            return "Stitch";
        }
    }
}
