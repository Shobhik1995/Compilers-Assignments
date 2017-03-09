#include <iostream>
#include <string>
using namespace std;

class LexAnalyzer {
   
   private: string s;

   public : void fail()
   {
      cout<<"NOT A NUMBER"<<endl;
   }

   public: void printExpo()
   {
      int i=0;
      while (s[i] != 'e' && s[i] != 'E')
      {
         i++;
      }
      i++;
      cout<<"Value of the exponent : "<<s.substr(i, std::string::npos)<<endl;
   };

   public: bool isDigit(char d)
   {
      if(d =='0' || d == '1' || d == '2' || d == '3' || d == '4' || d == '5' || d == '6' || d == '7' || d == '8' || d == '9' )
         return true;
      else
         return false;
   };	
   public: void getToken()
   {
   	cout<<"Enter a string"<<endl;
   	cin>>s;
      int start=0;
      int end=0;
   	int state=12;
   	for(int i=0;i<s.length();i++)
   	{//cout<<state<<endl;
         //cout<<i<<endl;
   		if(state == 12)
         {
            if(isDigit(s[i]))
            {
              state = 13;  
            }
            else
            {
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state == 13)
         {
            if(isDigit(s[i]))
            {
               if(i == s.length() -1)
               {
                  cout<<"INTEGER"<<endl;
                  //cout<<state<<endl;
                  return;
               }
               state=13;
            }
            else if(s[i] == '.')
            {
               state=14;

            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
               state=16;
            }
            else
            {
               state=20;
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state == 14)
         {
            if(isDigit(s[i]))
            {
               state=15;
               if(i == s.length()-1)
               {
                  cout<<"REAL NUMBER"<<endl;
                  //cout<<state<<endl;   
                  return;
               }
            }
            else
            {
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state == 15)
         {
            if(isDigit(s[i]))
            {
               if(i == s.length() -1)
               {
                  cout<<"REAL NUMBER"<<endl;
                  //cout<<state<<endl;
                  return;
               }
               state=15;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
               state =16;
            }
            else
            {
               state=21;
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state = 16 )
         {
            if(s[i] == '+' || s[i] == '-')
            {
               state =17;
               start=i;

               //enter code for recording the sign of
               //the exponent here
            }
            else if(isDigit(s[i]))
            {
               state = 18;
               start=i;
               if(i == s.length() -1)
               {
                  end=i;
                  cout<<"EXPONENT"<<endl;
                  printExpo();
                  //cout<<state<<endl;
                  return;
               }

            }
            else
            {
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state =17)
         {
            if(isDigit(s[i]))
            {
               state =18;
               if(i == s.length() -1)
               {
                  end=i;
                  cout<<"EXPONENT"<<endl;
                  printExpo();
                  //cout<<state<<endl;
                  return;
               }
            }
            else
            {
               fail();
               //cout<<state<<endl;
               return;
            }
         }
         else if(state == 18)
         {
            if(isDigit(s[i]))
            {
               state=18;
               if(i == s.length()-1)
               {
                  end=i;
                  cout<<"EXPONENT"<<endl;
                  printExpo();
                  //cout<<state<<endl;
                  return;
               }

            }
            else
            {
               state = 19;
               fail();
               //cout<<state<<endl;
               return;
            }
         }

   	} 
   };



};




int main()
{
 LexAnalyzer la=LexAnalyzer();
 la.getToken();
}