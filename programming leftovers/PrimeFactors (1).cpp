//=====================================================================
// PrimeFactors.cpp
//
// Factors a given number into its primes; demonstrates basic C++ functionality
//
// History:
// 2009.03.27 by Erich Kroneberger
//=====================================================================

#include <iostream>
      using namespace std;
      
      //----FUNCTION PROTOTYPES---------------------------------------------
      int GetFirstFactor( int n );
      
      
      //----FUNCTION DEFINITIONS--------------------------------------------
      //////////////////////////////////////////////////////////////////////
      //  MAIN FUNCTION
      //  main()
      //
      //  A C++ program automatically starts here.
      //////////////////////////////////////////////////////////////////////
      int main()
      {
        int num;
      
        cout << "Enter a positive whole number to factor: ";
        cin >> num;
   
     cout << "\nThe factors of " << num << " are:" << endl;
   
     while (num > 1)
     {
       int f = GetFirstFactor( num );
       cout << "  " << f << " " << endl;
       num /= f;
     }
   
     return 0;  // No errors
   }
   
   
   //////////////////////////////////////////////////////////////////////
   //  GetFirstFactor( int n ) : int
   //
   //  Returns the first number 2...n that divides evenly into n.
   //////////////////////////////////////////////////////////////////////
   int GetFirstFactor( int n )
   {
     // Check remainder of division by numbers 2...n
     for (int i=2; i<n; ++i)
     {
       if (n % i == 0) return i;  // No remainder so "i" is a factor
     }
   
     // If we ever make it here, then n and 1 are the only factors...
        return n;
 }

