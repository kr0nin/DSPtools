
/**
 * Write a description of class DateTest here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class DateTest
{
    static public void test()
    {
        Date dt = new Date(1, 1, 2010);
        int i = 0;
        while (i < 800)
        {
            dt.advance();
            System.out.println(dt);
            i++;
            }
        }
}
