// Matthew Robinson
//  Price Database
//  Class used to store and eventually get prices for food items

package the_final_program;

public class PriceDatabase
{

    // Initalize price variables
    private double sandwichHam          = 0.00d;
    private double sandwichTurkey       = 0.00d;
    private double sandwichChicken      = 0.00d;
    private double sandwichTuna         = 0.00d;
    private double sandwichBologna      = 0.00d;
    private double sandwichRoastBeef    = 0.00d;
    private double breadWhite           = 0.00d;
    private double breadWheat           = 0.00d;
    private double breadRye             = 0.00d;
    private double breadPretzel         = 0.00d;
    private double breadPita            = 0.00d;
    private double breadItalian         = 0.00d;
    private double sideFries            = 0.00d;
    private double sideOnionRings       = 0.00d;
    private double sideColeSlaw         = 0.00d;
    private double sidePotatoSalad      = 0.00d;
    private double sideMacaroniSalad    = 0.00d;
    private double drinkChild           = 0.00d;
    private double drinkSmall           = 0.00d;
    private double drinkMedium          = 0.00d;
    private double drinkLarge           = 0.00d;
    private double drinkExtraLarge      = 0.00d;
    private double drinkJumbo           = 0.00d;

    public String camelType(String itemName)
    {
        // Convert an itemName in title format to camelType
        String newItemName = "";
        for (int i = 0;  i < itemName.length(); i++)
        {
            char character = itemName.toCharArray()[i];
            if (character == ' ')
            {
                i++;
                char nextcharacter = itemName.toCharArray()[i];
                newItemName =
                        newItemName.concat(
                        String.valueOf(nextcharacter).toUpperCase());
            }
            else
                newItemName =
                        newItemName.concat(
                        String.valueOf(character).toLowerCase());
        }
        return newItemName;
    }

    private enum priceCategory
    {
        sandwich,
        bread,
        side,
        drink,
    }
    private enum priceItem
    {
        ham,
        turkey,
        chicken,
        tuna,
        bologna,
        roastBeef,
        white,
        wheat,
        rye,
        pretzel,
        pita,
        italian,
        fries,
        onionRings,
        coleSlaw,
        potatoSalad,
        macaroniSalad,
        child,
        small,
        medium,
        large,
        extraLarge,
        jumbo,
    }

    private String[] convertStringToCategory(String food)
    {
        // pass in the form "sandwich ham"
        int separatorIndex = 0;
        for (int i = 0; i < food.length(); i++)
        {
            if (food.charAt(i) == ' ')
                separatorIndex = i;
        }
        
        String category = food.substring(0, separatorIndex);
        String item = food.substring(separatorIndex + 1, food.length());

        String[] array = new String[2];

        array[0] = category.toLowerCase();
        array[1] = item;

        return array;
    }

    public void setPrice(String foodItem, double price)
    {
        // Take a string containing both category and itemName and
        //   convert it to two separate values
        String[] data;
        data = convertStringToCategory(foodItem);

        this.setPrice(data[0], data[1], price);
    }
    public void setPrice(String category, String item, double price)
    {
        switch (priceCategory.valueOf(category))
        {
            case sandwich:
                switch (priceItem.valueOf(item))
                {
                    case ham:
                        sandwichHam = price;
                        break;
                    case turkey:
                        sandwichTurkey = price;
                        break;
                    case chicken:
                        sandwichChicken = price;
                        break;
                    case tuna:
                        sandwichTuna = price;
                        break;
                    case bologna:
                        sandwichBologna = price;
                        break;
                    case roastBeef:
                        sandwichRoastBeef = price;
                        break;
                    default:
                        ;
                }
            break;
            case bread:
                switch (priceItem.valueOf(item))
                {
                    case white:
                        breadWhite = price;
                        break;
                    case wheat:
                        breadWheat = price;
                        break;
                    case rye:
                        breadRye = price;
                        break;
                    case pretzel:
                        breadPretzel = price;
                        break;
                    case pita:
                        breadPita = price;
                        break;
                    case italian:
                        breadItalian = price;
                        break;
                    default:
                        ;
                }
            break;
            case side:
                switch (priceItem.valueOf(item))
                {
                    case fries:
                        sideFries = price;
                        break;
                    case onionRings:
                        sideOnionRings = price;
                        break;
                    case coleSlaw:
                        sideColeSlaw = price;
                        break;
                    case potatoSalad:
                        sidePotatoSalad = price;
                        break;
                    case macaroniSalad:
                        sideMacaroniSalad = price;
                        break;
                    default:
                        ;
                }
            break;
            case drink:
                switch (priceItem.valueOf(item))
                {
                    case child:
                        drinkChild = price;
                    case small:
                        drinkSmall = price;
                    case medium:
                        drinkMedium = price;
                    case large:
                        drinkLarge = price;
                    case extraLarge:
                        drinkExtraLarge = price;
                    case jumbo:
                        drinkJumbo = price;
                    default:
                        ;
                }
            break;
        }
    }

    public double getPrice(String foodItem)
    {
        String[] data;
        data = convertStringToCategory(foodItem);

        return this.getPrice(data[0], data[1]);
    }
    public double getPrice(String category, String item)
    {

        item = camelType(item);

        // declare return variable in case something goes wrong
        double price = 0.00d;
        
        switch (priceCategory.valueOf(category))
        {
            case sandwich:
                switch (priceItem.valueOf(item))
                {
                    case ham:
                        return sandwichHam;
                    case turkey:
                        return sandwichTurkey;
                    case chicken:
                        return sandwichChicken;
                    case tuna:
                        return sandwichTuna;
                    case bologna:
                        return sandwichBologna;
                    case roastBeef:
                        return sandwichRoastBeef;
                    default:
                        return 0.00f;
                }
            case bread:
                switch (priceItem.valueOf(item))
                {
                    case white:
                        return breadWhite;
                    case wheat:
                        return breadWheat;
                    case rye:
                        return breadRye;
                    case pretzel:
                        return breadPretzel;
                    case pita:
                        return breadPita;
                    case italian:
                        return breadItalian;
                    default:
                        return 0.00f;
                }
            case side:
                switch (priceItem.valueOf(item))
                {
                    case fries:
                        return sideFries;
                    case onionRings:
                        return sideOnionRings;
                    case coleSlaw:
                        return sideColeSlaw;
                    case potatoSalad:
                        return sidePotatoSalad;
                    case macaroniSalad:
                        return sideMacaroniSalad;
                    default:
                        return 0.00f;
                }
            case drink:
                switch (priceItem.valueOf(item))
                {
                    case child:
                        return drinkChild;
                    case small:
                        return drinkSmall;
                    case medium:
                        return drinkMedium;
                    case large:
                        return drinkLarge;
                    case extraLarge:
                        return drinkExtraLarge;
                    case jumbo:
                        return drinkJumbo;
                    default:
                        return 0.00f;
                }
        }
        return price;
    }

    public PriceDatabase()
    {
        
    }
}
