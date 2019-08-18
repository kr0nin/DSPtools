
/**
 * Write a description of class TimeField here.
 * 
 * @ Z Ellett
 * @ 17 Sep 2009
 */
public class TimeField
{
    public int value, min, max;
    private boolean lead_zero;
    public TimeField(int n, int min, int max, boolean lead_zero)
    {
        value = n;
        this.min = min;
        this.max = max;
        this.lead_zero = lead_zero;
        }
    public void increment()
    {
        value++;
        if (value == (max+1))
            value = min;
        }
    public int getValue()   {  return value;  }
    public boolean rollOver()   {  return (value == min);  }
    public String toString()
    {
        String result = "";
        result += value;
        if (value < 10 && lead_zero)
            result = "0" + result;
        return result;
        }
}
