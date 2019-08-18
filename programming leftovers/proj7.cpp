//CS122
//Proj7 Erich Kroneberger
#include<iostream> //cin, cout
#include<fstream> //file operations
#include<cmath> //for use of sqrt

using namespace std;

int main()
{
     ifstream filein("p7.txt");
     ofstream fileout("p7out.txt");
     
    // check for errors
    // checking for errors is a falure
    // I can't get this to work
    // if (!filein)
    //    { cout<<"initial fin failure /n";
    //     exit(1);
    //    }
    // else (!fileout)
    //     { cout<<"initial fout failure /n";
    //      exit(1);
    //     }
          
     double x,y,x2,y2,r;
     filein>>x; //read first line and ignore
     fileout<<x<<endl;
     
     while(!filein.eof())
     {
          filein >> x >> y;
          r = sqrt((x*x) + (y*y));
          x2 = x/r;
          y2 = y/r;
          fileout << x2 <<" "<< y2<< endl;
     }
     filein.close();
     fileout.close();
     return(0);
}
