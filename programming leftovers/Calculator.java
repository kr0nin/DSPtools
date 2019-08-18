
/**
 * Write a description of class Calculator here.
 * 
 * @author erich kroneberger
 * @version 10 September 2009
 */
public class Calculator
{
    private int first, second, answer;
    private int operation, opCnt;
    public Calculator()    {    }
    public int display()    {  return answer;  }
    public void digit(int n)
    {
        if (operation == 0)
        {
            first = (first * 10) + n;
            answer = first;
            }
        else
        {
            second = (second * 10) + n;
            answer = second;
            }
        }
    public void opCount()
    {
        if (opCnt != 0)
        {
            switch (operation)
            {
                case 1: first = (first + second); break;
                case 2: first = (first - second); break;
                case 3: first = (first * second); break;
                case 4: first = (first / second); break;
                }
            second = 0;
            }
        opCnt++;
        }
    public void plus()             {  opCount(); operation = 1;  }
    public void minus()         {  opCount(); operation = 2;  }
    public void times()          {  opCount(); operation = 3;  }
    public void dividedBy()   {  opCount(); operation = 4;  }
    public void equals()
    {
        switch (operation)
        {
            case 0: answer = first; break;
            case 1: answer = (first + second); break;
            case 2: answer = (first - second); break;
            case 3: answer = (first * second); break;
            case 4: answer = (first / second); break;
            }
        first = 0; second = 0; operation = 0; opCnt = 0;
        }
    }