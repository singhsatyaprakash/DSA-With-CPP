#include<iostream> 
#include<stdlib.h> 
#include<fstream> 
#include<conio.h> 
using namespace std;
int main(){ 
   char fname[20],ch; 
   ifstream fin; // create an input stream 
   cout<<"Enter the name of the file: "; 
   cin.get(fname, 20); 
   cin.get(ch); 
 
   fin.open(fname, ios::in);       // open file in read mode
   if(!fin.is_open()){         // if fin stores zero i.e., false value  
    cout<<"Error occurred in opening the file..!!\n"; 
    cout<<"Press any key to exit...\n"; 
    getch(); 
    exit(1); 
   } 

   while(fin.eof()){ // fin will be 0 when eof is reached  
      fin.get(ch);        // read a character 
      cout<<ch;       // display the character 
   } 
   cout<<"\nPress any key to exit...\n"; 
   fin.close(); 
   return 0;
}