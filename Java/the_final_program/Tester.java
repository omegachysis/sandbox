// Matthew Robinson
//   Food Order - Tester
//   Test the Price Database class we designed

package the_final_program;

import TerminalIO.KeyboardReader;

public class Tester
{

    public static void main(String[] args)
    {

        KeyboardReader reader = new KeyboardReader();
        PriceDatabase database = new PriceDatabase();

        // All of these values should be 0.00 to start
        System.out.println(database.getPrice("sandwich", "ham"));
        System.out.println(database.getPrice("sandwich", "turkey"));
        System.out.println(database.getPrice("sandwich", "roastBeef"));
        System.out.println(database.getPrice("bread", "white"));
        System.out.println(database.getPrice("side", "fries"));
        System.out.println(database.getPrice("drink", "jumbo"));

        System.out.println("-------------------------------------");

        // Try many different categories and first and last items
        //  (this is where we might have problems if any)
        database.setPrice("sandwich", "ham", 2.00d);
        database.setPrice("sandwich", "turkey", 3.00d);
        database.setPrice("sandwich", "roastBeef", 1.00d);
        database.setPrice("bread", "white", 0.50d);
        database.setPrice("side", "fries", 3.50d);
        database.setPrice("drink", "jumbo", 5.99d);

        // Make usre all prices coorespond the proper way
        System.out.println(database.getPrice("sandwich", "ham"));
        System.out.println(database.getPrice("sandwich", "turkey"));
        
          // this one should still be zero:
        System.out.println(database.getPrice("sandwich", "bologna"));

        System.out.println(database.getPrice("sandwich", "roastBeef"));
        System.out.println(database.getPrice("bread", "white"));
        System.out.println(database.getPrice("side", "fries"));
        System.out.println(database.getPrice("drink", "jumbo"));

        database.setPrice("sandwich", "chicken", 2.40d);
        database.setPrice("sandwich", "tuna", 1.50d);
        database.setPrice("sandwich", "bologna", 5.00d);
        database.setPrice("bread", "wheat", 0.99d);
        database.setPrice("bread", "rye", 0.89d);
        database.setPrice("bread", "pretzel", 1.20d);
        database.setPrice("bread", "pita", 1.99d);
        database.setPrice("bread", "italian", 2.50d);
        database.setPrice("side", "onionRings", 2.80d);
        database.setPrice("side", "coleSlaw", 3.90d);
        database.setPrice("side", "potatoSalad", 4.50d);
        database.setPrice("side", "macaroniSalad", 5.99d);
        database.setPrice("drink", "child", 1.25d);
        database.setPrice("drink", "small", 1.75d);
        database.setPrice("drink", "medium", 1.99d);
        database.setPrice("drink", "large", 2.25d);
        database.setPrice("drink", "extraLarge", 2.75d);
        // Reset jumbo to something else to make sure resetting
        // works as well
        database.setPrice("drink", "jumbo", 3.99d);

        String[] testingList = {
        "Sandwich ham",
        "Sandwich turkey",
        "Sandwich chicken",
	"Sandwich tuna",
	"Sandwich bologna",
	"Sandwich roastBeef",
	"Bread white",
	"Bread wheat",
	"Bread rye",
	"Bread pretzel",
	"Bread pita",
	"Bread italian",
	"Side fries",
	"Side onionRings",
	"Side coleSlaw",
	"Side potatoSalad",
	"Side macaroniSalad",
	"Drink child",
	"Drink small",
	"Drink medium",
	"Drink large",
	"Drink extraLarge",
	"Drink jumbo",
        };

        System.out.println("-----------------------------------");
        System.out.println("COMPLETE TEST RUN:");
        System.out.println("-----------------------------------");

        for (int i = 0; i < testingList.length; i++)
        {
            System.out.println(database.getPrice(testingList[i]));
        }
        
    }

}
