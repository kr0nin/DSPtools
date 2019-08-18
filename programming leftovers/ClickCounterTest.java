
/**
 * Write a description of class ClickCounterTest here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

public class ClickCounterTest
{
   public void test()
   {
       ClickCounter cl;
       c1 = new ClickCounter();
       ClickCounter c2 = new ClickCounter();
       c1.click();
       c1.click();
       c2.click();
       c2.click();
       c2.click();
       c2.click();
       System.out.println(c1.count);
       System.out.println(c2.count);
    }
    
}
