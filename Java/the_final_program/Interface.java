// Matthew Robinson
//  Ordering Food - Interface
//   Submit and Calculate receipts for food ordering at a restaurant

package the_final_program;

import javax.swing.*;
import BreezySwing.*;
import java.awt.Font;
import java.text.DecimalFormat;

import the_final_program.PriceDatabase;

public class Interface extends GBFrame
{

    Font font = new Font("MONOSPACED", Font.PLAIN, 12);

    private JLabel sandwichLabel;
    private JLabel breadLabel;
    private JLabel sidesLabel;
    private JLabel drinksLabel;
    private JLabel drinkSize;
    private JLabel individualOrderLabel;
    private JLabel totalOrderLabel;

    private JButton sandwichHamButton;
    private JButton sandwichTurkeyButton;
    private JButton sandwichChickenButton;
    private JButton sandwichTunaButton;
    private JButton sandwichBolognaButton;
    private JButton sandwichRoastBeefButton;

    private JButton breadWhiteButton;
    private JButton breadWheatButton;
    private JButton breadRyeButton;
    private JButton breadPretzelButton;
    private JButton breadPitaButton;
    private JButton breadItalianButton;

    private JButton sidesNoneButton;
    private JButton sidesFriesButton;
    private JButton sidesOnionRingsButton;
    private JButton sidesColeSlawButton;
    private JButton sidesPotatoSaladButton;
    private JButton sidesMacaroniSaladButton;

    private JButton drinksNoneButton;
    private JButton drinksColaButton;
    private JButton drinksLemonLimeButton;
    private JButton drinksRootBeerButton;
    private JButton drinksDietColaButton;
    private JButton drinksIcedTeaButton;

    private JButton drinksSizeChildButton;
    private JButton drinksSizeSmallButton;
    private JButton drinksSizeMediumButton;
    private JButton drinksSizeLargeButton;
    private JButton drinksSizeExtraLargeButton;
    private JButton drinksSizeJumboButton;

    private JButton submitButton;
    private JButton calculateButton;
    private JButton clearButton;

    private JTextArea outputArea;

    private JButton[] sandwichButtons = new JButton[6];
    private JButton[] breadButtons = new JButton[6];
    private JButton[] sidesButtons = new JButton[6];
    private JButton[] drinksButtons = new JButton[6];
    private JButton[] drinkSizeButtons = new JButton[6];

    private String[] orderedItems;
    private double[] orderedPrices;

    private String[][] totalOrderedItems = new String[5][6];
    private double[][] totalOrderedPrices= new double[5][6];

    private int numberOfOrders = 0;

    private PriceDatabase priceDatabase;

    // Setup formatting for rounding
    private DecimalFormat df = new DecimalFormat("0.00");

    public Interface()
    {
        // Add all window elements
        
        sandwichLabel           = addLabel("Sandwich", 1, 1, 1, 1);
        sandwichHamButton       = addButton("Ham",    2, 1, 1, 1);
        sandwichTurkeyButton    = addButton("Turkey", 2, 2, 1, 1);
        sandwichChickenButton   = addButton("Chicken",2, 3, 1, 1);
        sandwichTunaButton      = addButton("Tuna",   2, 4, 1, 1);
        sandwichBolognaButton   = addButton("Bologna",2, 5, 1, 1);
        sandwichRoastBeefButton = addButton("Roast Beef", 2, 6, 1, 1);

        breadLabel              = addLabel("Bread", 3, 1, 1, 1);
        breadWhiteButton        = addButton("White",  4, 1, 1, 1);
        breadWheatButton        = addButton("Wheat",  4, 2, 1, 1);
        breadRyeButton          = addButton("Rye",    4, 3, 1, 1);
        breadPretzelButton      = addButton("Pretzel",4, 4, 1, 1);
        breadPitaButton         = addButton("Pita",   4, 5, 1, 1);
        breadItalianButton      = addButton("Italian",4, 6, 1, 1);

        sidesLabel              = addLabel("Sides (pick 2)", 5, 1, 1, 1);
        sidesNoneButton         = addButton("None",           6, 1, 1, 1);
        sidesFriesButton        = addButton("Fries",          6, 2, 1, 1);
        sidesOnionRingsButton   = addButton("Onion Rings",    6, 3, 1, 1);
        sidesColeSlawButton     = addButton("Cole Slaw",      6, 4, 1, 1);
        sidesPotatoSaladButton  = addButton("Potato Salad",   6, 5, 1, 1);
        sidesMacaroniSaladButton= addButton("Macaronia Salad",6, 6, 1, 1);

        drinksLabel             = addLabel("Drinks", 7, 1, 1, 1);
        drinksNoneButton        = addButton("None",     8, 1, 1, 1);
        drinksColaButton        = addButton("Cola",     8, 2, 1, 1);
        drinksLemonLimeButton   = addButton("Lemon/Lime",8, 3, 1, 1);
        drinksRootBeerButton    = addButton("Root Beer", 8, 4, 1, 1);
        drinksDietColaButton    = addButton("Diet Cola", 8, 5, 1, 1);
        drinksIcedTeaButton     = addButton("Iced Tea",  8, 6, 1, 1);

        drinkSize               = addLabel("Drink Size", 9, 1, 1, 1);
        drinksSizeChildButton   = addButton("Child",    10, 1, 1, 1);
        drinksSizeSmallButton   = addButton("Small",    10, 2, 1, 1);
        drinksSizeMediumButton  = addButton("Medium",   10, 3, 1, 1);
        drinksSizeLargeButton   = addButton("Large",    10, 4, 1, 1);
        drinksSizeExtraLargeButton = addButton("Extra Large", 10, 5, 1, 1);
        drinksSizeJumboButton   = addButton("Jumbo",    10, 6, 1, 1);

        individualOrderLabel = addLabel("Individual Order", 11,1, 1, 1);
        submitButton = addButton("Submit", 12, 1, 1, 1);
        totalOrderLabel = addLabel("Total Order", 11, 2, 1, 1);
        calculateButton = addButton("Calculate", 12, 2, 1, 1);
        clearButton = addButton("Clear", 12, 3, 1, 1);

        outputArea = addTextArea("", 13, 1, 6, 1);
        outputArea.setFont(font);

        JButton[] _sandwichButtons = {
            sandwichHamButton,
            sandwichTurkeyButton,
            sandwichChickenButton,
            sandwichTunaButton,
            sandwichBolognaButton,
            sandwichRoastBeefButton
        };
        JButton[] _breadButtons = {
            breadWhiteButton,
            breadWheatButton,
            breadRyeButton,
            breadPretzelButton,
            breadPitaButton,
            breadItalianButton
        };
        JButton[] _sidesButtons = {
            sidesNoneButton,
            sidesFriesButton,
            sidesOnionRingsButton,
            sidesColeSlawButton,
            sidesPotatoSaladButton,
            sidesMacaroniSaladButton
        };
        JButton[] _drinksButtons = {
            drinksNoneButton,
            drinksColaButton,
            drinksLemonLimeButton,
            drinksRootBeerButton,
            drinksDietColaButton,
            drinksIcedTeaButton
        };
        JButton[] _drinkSizeButtons = {
            drinksSizeChildButton,
            drinksSizeSmallButton,
            drinksSizeMediumButton,
            drinksSizeLargeButton,
            drinksSizeExtraLargeButton,
            drinksSizeJumboButton
        };

        // Add sets of buttons to our button groups using foreach statements

        int i = 0;
        for (JButton button : _sandwichButtons)
        {
            sandwichButtons[i] = button;
            i++;
        }
        i = 0;
        for (JButton button : _breadButtons)
        {
            breadButtons[i] = button;
            i++;
        }
        i = 0;
        for (JButton button : _sidesButtons)
        {
            sidesButtons[i] = button;
            i++;
        }
        i = 0;
        for (JButton button : _drinksButtons)
        {
            drinksButtons[i] = button;
            i++;
        }
        i = 0;
        for (JButton button : _drinkSizeButtons)
        {
            drinkSizeButtons[i] = button;
            i++;
        }

        // Will store each individual order
        orderedItems = new String[6];
        orderedPrices= new double[6];

        // Instantiate our price database class
        priceDatabase = new PriceDatabase();

        // Set all specified prices provided
        PriceDatabase db = priceDatabase;
        db.setPrice("sandwich", "ham",      4.00d);
        db.setPrice("sandwich", "turkey",   4.50d);
        db.setPrice("sandwich", "chicken",  4.00d);
        db.setPrice("sandwich", "tuna",     4.25d);
        db.setPrice("sandwich", "bologna",  3.50d);
        db.setPrice("sandwich", "roastBeef",4.75d);

        db.setPrice("bread", "white",       1.00d);
        db.setPrice("bread", "wheat",       1.50d);
        db.setPrice("bread", "rye",         1.75d);
        db.setPrice("bread", "pretzel",     1.25d);
        db.setPrice("bread", "pita",        1.25d);
        db.setPrice("bread", "italian",     1.25d);

        db.setPrice("side", "fries",        2.55d);
        db.setPrice("side", "onionRings",   2.65d);
        db.setPrice("side", "coleSlaw",     2.00d);
        db.setPrice("side", "potatoSalad",  1.75d);
        db.setPrice("side", "macaroniSalad",1.75d);

        db.setPrice("drink", "child",       1.00d);
        db.setPrice("drink", "small",       2.00d);
        db.setPrice("drink", "medium",      2.25d);
        db.setPrice("drink", "large",       2.50d);
        db.setPrice("drink", "extraLarge",  2.75d);
        db.setPrice("drink", "jumbo",       3.00d);
    }

    public void OrderItem(String category, String itemName)
    {
        // Add a certain item and category to the current order
        // Categories include: sandwich, bread, drink, drink type, and side
        
        if (category.equals("sandwich")  ||
                category.equals("bread") ||
                category.equals("drink"))
        {
            int number = 0;
            double price = priceDatabase.getPrice(category, itemName);
            if (category.equals("sandwich"))     number = 0;
            if (category.equals("bread"))        number = 1;
            if (category.equals("drink"))        number = 5;

            orderedItems[number] = itemName;
            orderedPrices[number]= price;
        }
        else if (category.equals("drink type"))
        {
            orderedItems[4] = itemName;
            orderedPrices[4] = 0.00d;
        }
        else if (category.equals("side"))
        {
            if (!itemName.equals("None"))
            {
                double price = priceDatabase.getPrice(category, itemName);
                if (orderedItems[2] == null)
                {
                    orderedItems[2] = itemName;
                    orderedPrices[2] = price;
                }
                else
                {
                    orderedItems[3] = itemName;
                    orderedPrices[3] = price;
                }
            }
        }
    }

    public String[] CopyArray(String[] array)
    {
        // Duplicate an array.  This prevents arrays from
        // being referenced in memory in the incorrect way when we
        // add the individual order arrays to the total order arrays
        
        String[] newArray = new String[array.length];
        System.arraycopy(array, 0, newArray, 0, array.length);
        return newArray;
    }
    public double[] CopyArray(double[] array)
    {
        // Duplicate an array of double type
        
        double[] newArray = new double[array.length];
        System.arraycopy(array, 0, newArray, 0, array.length);
        return newArray;
    }

    public void SubmitOrder()
    {
        // Submit the current order

        // Create new instances using CopyArray to prevent a logical
        //  error caused by a mismatch in reference memory.  This was
        //  a bad error when I got it!  FIXED
        totalOrderedItems[numberOfOrders] = CopyArray(orderedItems);
        totalOrderedPrices[numberOfOrders]= CopyArray(orderedPrices);
        ClearCurrentOrder();
        numberOfOrders++;
        // Rest all buttons to default
        EnableButtons();

        // Display a friendly message to confirm the order was submitted
        ClearTextArea();
        outputArea.append("Submitted order #" + numberOfOrders);

        // We cannot all more than five orders
        if (numberOfOrders == 5)
            submitButton.setEnabled(false);
    }

    public int Count(String[] array, String value)
    {
        // Count the number of times a value occurs in an array
        int count = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == null ? value == null : array[i].equals(value))
                count++;
        }

        return count;
    }
    
    public void CalculateOrder()
    {
        ClearCurrentOrder();
        ClearTextArea();

        String[] itemsShown = new String[30];
        int numberOfItemsShown = 0;

        String itemName;
        int totalQuantity;
        double price;

        // Loop through all orders in the total array
        for (int orderNumber = 0; orderNumber < 5; orderNumber++)
        {
            // Loop through the elements of the sub-arrays as categories
            // These have been placed specifically to match to certain
            // category orders to the price array
            for (int categoryNumber = 0; categoryNumber < 6; categoryNumber++)
            {
                itemName = totalOrderedItems[orderNumber][categoryNumber];
                // Make sure we don't show the same item more than once
                if (!isValueInArray(itemName, itemsShown))
                {
                    // Count ALL the times this item is ordered
                    totalQuantity =
                            Count(totalOrderedItems[0], itemName) +
                            Count(totalOrderedItems[1], itemName) +
                            Count(totalOrderedItems[2], itemName) +
                            Count(totalOrderedItems[3], itemName) +
                            Count(totalOrderedItems[4], itemName);

                    // append itemName to itemsShown
                    itemsShown[numberOfItemsShown] = itemName;
                    numberOfItemsShown++;

                    // Access the parallel price array
                    price = totalOrderedPrices[orderNumber][categoryNumber] *
                            totalQuantity;

                    // Don't display items that were omitted in the orders,
                    //   like second sides for example
                    if (!itemName.equals("None"))
                    {
                        outputArea.append(
                            Format.justify('l', itemName, 20) +
                            Format.justify('l', totalQuantity, 10) +
                            Format.justify('r', df.format(price), 5) +
                            "\n");
                    }
                }
            }
        }
    }

    public void ClearTextArea()
    {
        outputArea.setText(null);
    }
    
    public void ClearCurrentOrder()
    {
        for (int i = 0; i < 6; i++)
        {
            orderedItems[i] = null;
            orderedPrices[i]= 0.00d;
        }
    }
    public void Reset()
    {
        // Reset EVERYTHING to a default state
        
        numberOfOrders = 0;
        EnableButtons();
        ClearCurrentOrder();
        for (int i = 0; i < 5; i++)
        {
            totalOrderedItems[i] = orderedItems;
            totalOrderedPrices[i]= orderedPrices;
        }
        ClearTextArea();
        outputArea.setText("All orders cleared!");
    }

    public static boolean isValueInArray(String value, String[] array)
    {
        // Simple check if a value is in the array
        //  Return true or false
        boolean condition;
        condition = false;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == null ? value == null : array[i].equals(value))
                condition = true;
        }

        return condition;
    }
    public static boolean isValueInArray(JButton value, JButton[] array)
    {
        boolean condition;
        condition = false;
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == value)
                condition = true;
        }

        return condition;
    }

    public static void SetEnabledButtonGroup(JButton[] array, boolean enabled)
    {
        // Set all the buttons to a certain enabled state in a certain group
        for (JButton button : array)
            button.setEnabled(enabled);
    }

    public void EnableButtons()
    {
        // Enabled all the buttons on the screen that could have been
        //   possibly disabled.
        SetEnabledButtonGroup(sandwichButtons, true);
        SetEnabledButtonGroup(breadButtons, true);
        SetEnabledButtonGroup(sidesButtons, true);
        SetEnabledButtonGroup(drinksButtons, true);
        SetEnabledButtonGroup(drinkSizeButtons, true);

        submitButton.setEnabled(true);
    }

    @Override
    public void buttonClicked(JButton button)
    {
        if (button == submitButton)
            SubmitOrder();
        else if (button == calculateButton)
            CalculateOrder();
        else if (button == clearButton)
            Reset();
        else
        {
            // Based on the button group containing the button,
            //   append orders of that certain category type
            if (isValueInArray(button, sandwichButtons))
            {
                SetEnabledButtonGroup(sandwichButtons, false);
                OrderItem("sandwich", button.getText());
            }
            if (isValueInArray(button, breadButtons))
            {
                SetEnabledButtonGroup(breadButtons, false);
                OrderItem("bread", button.getText());
            }
            if (isValueInArray(button, sidesButtons))
            {
                if (button.getText().equals("None"))
                {
                    SetEnabledButtonGroup(sidesButtons, false);
                    orderedItems[2] = "None";
                    orderedItems[3] = "None";
                    orderedPrices[2] = 0.00d;
                    orderedPrices[3] = 0.00d;
                }
                if (orderedItems[2] == null)
                {
                    OrderItem("side", button.getText());
                }
                else
                {
                    OrderItem("side", button.getText());
                    SetEnabledButtonGroup(sidesButtons, false);
                }
            }
            if (isValueInArray(button, drinksButtons))
            {

                SetEnabledButtonGroup(drinksButtons, false);
                if (button.getText().equals("None"))
                    SetEnabledButtonGroup(drinkSizeButtons, false);
                OrderItem("drink type", button.getText());
            }
            if (isValueInArray(button, drinkSizeButtons))
            {
                SetEnabledButtonGroup(drinkSizeButtons, false);
                OrderItem("drink", button.getText());
            }
        }
    }

    public static void main(String[] args)
    {
        // Create GUI and run program
        Interface GUI = new Interface();
        GUI.setLookAndFeel("METAL");
        GUI.setSize (800, 700);
        GUI.setVisible (true);
    }

}
