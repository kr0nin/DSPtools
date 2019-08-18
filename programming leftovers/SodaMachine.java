
/**
 * Write a description of class SodaMachine here.
 * 
 * Erich Kroneberger
 * 03 September 2009
 */
public class SodaMachine
{
    private int price, sodas, deposit;
    public SodaMachine()
    {
        price = 50;
        sodas = 3;
        deposit = 0;
        System.out.println("New soda machine.");
        }
    public void insertQuarter()
    {
        if (sodas > 0)
        {
            deposit += 25;
            System.out.println("Current deposit is " + deposit + " cents.");
            }
        else
            System.out.println("Sold out");
        }
    public void insertDime()
    {
        if (sodas > 0)
        {
            deposit += 10;
            System.out.println("Current deposit is " + deposit + " cents.");
            }
        else
            System.out.println("Sold out");
        }
    public void insertNickel()
    {
        if (sodas > 0)
        {
            deposit += 5;
            System.out.println("Current deposit is " + deposit + " cents.");
            }
        else
            System.out.println("Sold out");
        }
    public void setPrice(int cents)
    {
        if (cents < 0)
            System.out.println("Invalid price.");
        else
        {
            price = cents;
            System.out.println("Price set to " + price + " cents.");
            }
        }
    public void vend()
    {
        if (sodas > 0)
        {
            if (deposit >= price)
            {
                System.out.println("A soda rolls out.");
                if (deposit > price)
                    System.out.println("You receive " + (deposit - price) + " cents in change.");
                deposit = 0;
                sodas--;
                }
            else
                System.out.println("The price is " + price + " cents.");
            }
        else
            System.out.println("Sold out");
        }
    }
