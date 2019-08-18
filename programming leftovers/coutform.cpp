

    // cout formatting sample
    #include <iostream>
    #include <limits>
    using namespace std;

    int main ()
    {
      double x = 12.0;
       cout.precision(2);              // Precision 2
       cout << " By default:   " << x << endl;
       cout << " showpoint:  " << showpoint  << x << endl;
       cout << " fixed:      " << fixed      << x << endl;
       cout << " scientific: " << scientific << x << endl;

       std::cout << "Press ENTER to continue...";
       std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

      // terminate the program:
      return 0;
    }

              


