#include<iostream>                         
#include <fstream>                         
using namespace std; 
int main() { 
    int count=0;                     
    fstream FileName;                    
    FileName.open("FileName.txt", ios::in); //reading mode         
    if (!FileName) {  //if not open...                       
        cout<<"File doesn’t exist.";           
    } 
    else { 
        char x; 
        while (1) {          
            FileName>>x;   //reading char by char            
            if(FileName.eof())    //untill end of file       
                break;
            count++;               
            cout<<x;                   
        } 
    }
    FileName.close();   
    printf("\nTotal letters:%d",count);
    return 0;
}