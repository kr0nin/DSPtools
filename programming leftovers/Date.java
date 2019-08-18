
/**
 * Write a description of class Date here.
 * 
 * @ Z Ellett
 * @ 17 Sep 2009
 */
public class Date
{
    private TimeField day, month, year;
    public Date(int d, int m, int y)
    {
        day = new TimeField(d, 1, getDays(m, y), true);
        month = new TimeField(m, 1, 12, true);
        year = new TimeField(y, 0000, 9999, false);
        }
    public void advance()
    {
        day.increment();
        if (day.rollOver())
        {
            month.increment();
            day.max = getDays(month.value, year.value);
     //       day = TimeField(day.value, 1, getDays(month.value, year.value), true);
            if (month.rollOver())
                year.increment();
            }
        }
    public void advanceW(int n)
    {
        for (int i = 0; i < (7*n); i++)
            advance();
        }
    public void advanceD(int n)
    {
        for (int i = 0; i < n; i++)
            advance();
        }
    public int getDays(int month, int year)
    {
        int lastDay = 0;
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: lastDay = 31; break;
            case 4:
            case 6:
            case 9:
            case 11: lastDay = 30; break;
            case 2:
                if ( ((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0) )
                    lastDay = 29;
                else
                    lastDay = 28;
                break;
            }
        return lastDay;
        }
    public String toString()
    {
        return month + "-" + day + "-" + year;
        }
    public void output()
    {
        System.out.println(month + "-" + day + "-" + year);
        }
}
