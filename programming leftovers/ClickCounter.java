
/**
 * Write a description of class ClickCounter here.
 * 
 * @author (Erich Kroneberger) 
 * @version (a version number or a date)
 */
public class ClickCounter
{
   private int cur;
   
   public void click()
   {
        cur = cur + 1;
   }
   
   public void reset()
   {
       cur = 0; 
   }
   public int count()
   {
       return cur;
   }
}
