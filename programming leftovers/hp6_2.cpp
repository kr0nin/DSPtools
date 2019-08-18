        // proj6
        // Erich Kroneberger
        
        #include <iostream>
        #include <iomanip>
        #include <limits>
        using namespace std;
        
        int main ()
        {
            
          int num = 0;           
          
          cout<<endl<<"ASCII TABLE"<<endl<<endl;
          
          for(num=0;num<128;num++)
          {
                        cout<<"|";
                        cout<<setw(3)<<right;
                        
                        if (num==8)cout<<num<<" "<<"BS ";
                        else if (num==9)cout<<num<<("^"+(char)(64+num))<<"\\t ";
                        else if (num==10)cout<<num<<("^"+(char)(64+num))<<"\\n ";
                        else if (num==13)cout<<num<<" "<<"CR ";
                        else if (num==27)cout<<num<<" "<<"ESC";
                        else if (num==32)cout<<num<<("^"+(char)(64+num))<<" SP ";
                        else if (num==127)cout<<num<<" DEL";
                        else if ((num>=0)&&(num<=32))cout<<num<<" "<<"^"<<(char)(64+num)<<" ";
                        else cout<<num<<"  "<<(char)num<<" ";
                         
                        if (((num+1)%8)==0)cout<<"|"<<endl;
          }
          
          cout<<endl;
          
            std::cout << "Press ENTER to continue...";
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
          
          return 0;
        }
