        // proj6
        // Erich Kroneberger
        
        #include <iostream>
        #include <iomanip>
        using namespace std;
        
        int main ()
        {
          int num = 0;           
          
          cout<<endl<<"ASCII TABLE"<<endl<<endl;
          
          for(num=0;num<128;num++)
          {
                        cout<<"|";
                        cout<<setw(3)<<right;
                        cout<<num<<" "<<(char)num;
                        
                        if (num==8)cout<<" BS ";
                        else if (num==9)cout<<"\\t ";
                        else if (num==10)cout<<"\\n ";
                        else if (num==13)cout<<"CR ";
                        else if (num==27)cout<<"ESC";
                        else if (num==32)cout<<"SP";
                        else if (num==127)cout<<"DEL";
                        else if (num>=0)&&(num<=7)&&(num>=11)&&(num<=12)
                                (num>=14)&&(num<=26)(num>=28)&&(num<=31)
                                (num>=33)&&(num<=126)&&(num<=32)
                        
                        
                        cout<<"^"<<(char)(64+num);
                        else cout<<" ";
                         
                        if (((num+1)%8)==0)cout<<"|"<<endl;
          }
          
          cout<<endl;
          
          return 0;
        }
