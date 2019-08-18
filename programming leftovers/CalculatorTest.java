//====================================================================
  //  CalculatorTest.java
  //
  //  Tests out the Calculator class.
  //
  //  2008.08.04 by Abe Pralle
  //====================================================================

  public class CalculatorTest
  {
    static public void test()
    {
      new CalculatorTest();
    }

    static public void main( String[] args )
    {
      // for command-line startup
      test();
    }

    private Calculator calc;

    private CalculatorTest()
    {
      println( "Creating calculator." );
      calc = new Calculator();

      println( "\nTesting two-operand calculations:" );
      runTest( "928/8",      116 );
      runTest( "511/333",      1 );
      runTest( "331/43",       7 );
      runTest( "977+766",   1743 );
      runTest( "189+652",    841 );
      runTest( "99+6",       105 );
      runTest( "243*52",   12636 );
      runTest( "501*846", 423846 );
      runTest( "732-71",     661 );
      runTest( "14/4",         3 );
      runTest( "980-640",    340 );
      runTest( "635*0",        0 );
      runTest( "444/9",       49 );
      runTest( "147*88",   12936 );
      runTest( "67*63",     4221 );
      runTest( "390+22",     412 );

      // UNCOMMENT THIS CODE TO PERFORM THREE AND FOUR-OPERAND TESTS
      
      println( "\nTesting three-operand calculations:" );
      runTest( "572+48*45",  27900 );
      runTest( "636/25*536", 13400 );
      runTest( "804-16*32",  25216 );
      runTest( "798+733/4",    382 );
      runTest( "851*56/5",    9531 );
      runTest( "823*859/8",  88369 );
      runTest( "297+195+90",   582 );
      runTest( "631-696*4",   -260 );

      println( "\nTesting four-operand calculations:" );
      runTest( "451-446/7+24",      24 );
      runTest( "661/82-3+91",       96 );
      runTest( "454-29*0*117",       0 );
      runTest( "936-494+144+6",    592 );
      runTest( "290*260+1*2",   150802 );
      runTest( "755*89*3+178",  201763 );
      runTest( "838*53/955-664",  -618 );
      runTest( "544/725+2+33",      35 );
      
      println( "\nTesting five-operand calculations:" );
      runTest( "451-446/7+24*2",      48 );
      runTest( "661/82-3+91/4",       24 );
      runTest( "454-29*0*117+99",       99 );
      runTest( "936-494+144+6/2",    296 );
      runTest( "290*260+1*2-800",   150002 );
      runTest( "755*89*3+178+30000",  231763 );
      runTest( "838*53/955-664+18",  -600 );
      runTest( "544/725+2+33*8",      280 );
    }

    private void println( String mesg )
    {
      System.out.println( mesg );
    }

    private void runTest( String cmds, int expected_result )
    {
      for (int i=0; i<cmds.length(); i++)
      {
        char ch = cmds.charAt(i);
        if (ch >= '0' && ch <= '9')
        {
          calc.digit( ch-'0' );
        }
        else
        {
          switch (ch)
          {
            case '+': calc.plus(); break;
            case '-': calc.minus(); break;
            case '*': calc.times(); break;
            case '/': calc.dividedBy(); break;
          }
        }
      }
      calc.equals();

      int actual_result = calc.display();
      if (actual_result == expected_result)
      {
        println( "   PASS " + cmds + " = " + actual_result );
      }
      else
      {
        println( "***FAIL " + cmds + " = " + actual_result + " (should have been " + expected_result + ")" );
      }
    }
  }