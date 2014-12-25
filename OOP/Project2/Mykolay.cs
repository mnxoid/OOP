namespace Project2
{
   public sealed class Mykolay
{
    static readonly Mykolay MyInstance = new Mykolay();

    static Mykolay() { }

    Mykolay() { }

    public static Mykolay Instance
    {
        get
        {
            return MyInstance;
        }
    }

    public static void GiveGifts(Children cc)
    {
        GiftFactory ggf = new GoodGiftFactory();
        GiftFactory bgf = new BadGiftFactory();
        foreach (var child in cc)
        {
            if (child.GoodDeeds > child.BadDeeds)
            {
                child.EatGift = ggf.CreateEatableGift();
                child.UneatGift = ggf.CreateUneatableGift();
            }
            else
            {
                child.EatGift = bgf.CreateEatableGift();
                child.UneatGift = bgf.CreateUneatableGift();
            }
        }
    }
}

}
