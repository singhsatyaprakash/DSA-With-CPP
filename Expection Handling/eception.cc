/*#include <iostream>   
using namespace std;   
int main ()  
{   
int i = 50;   
int j = 0;   
float k = i / j;   
cout << k << endl;   
cout<<"End of Program.."<<endl;
return 0;   
} */

#include<iostream> 
using namespace std; 
int main (){   
    int i = 25;   
    int j = 0;   
    try{    
        if(j==0){
            throw "Attempted to divide by zero!";   
        } 
        float k = 0;   
        k = i/j; 
        cout << k << endl;   
    } 
    catch(const string e){   
        cout << e << endl;   //terminate called after throwing an instance of 'char const*'
    }   
    cout<<"end of Main function"; 
    return 0;   
}  