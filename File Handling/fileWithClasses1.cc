// A file 'Employee.txt' contains empno and empname. Write a C++ program to add and read 
// contents of this file and search employee whose name is 'XYZ'. 
#include<iostream> 
#include<fstream> 
#include<stdio.h> 
#include<string.h> 
#include<cstdlib> 
using namespace std; 
class Employee 
{ 
public: 
int empno ; 
char empname[20]; 
}; 
 
 
int main() 
{ 
     Employee e; 
     fstream f; 
     int eno; 
     char ename[20],c; 
     int ch; 
     while(1) 
     { 
          cout<<"\n\n 1. Add Records in the File"; 
          cout<<"\n 2. Search Record by Employee No."; 
          cout<<"\n 3. Search Employee whose Name is 'XYZ'"; 
          cout<<"\n 4. Display All Records"; 
          cout<<"\n 5. Search Record by Employee Name"; 
          cout<<"\n 6. Exit"; 
          cout<<"\n\n Enter Your Choice : "; 
          cin>>ch; 
          switch(ch) 
          { 
               case 1: 
                    f.open("employee.txt",ios::app|ios::binary); 
                    while (1) 
                    { 
                         cout<<"\n Enter Employee Number :  "; 
                         cin>>e.empno; 
                         cin.ignore(); 
                         cout<<"\n Enter Employee Name   :  "; 
                         cin>>e.empname; 
                         cin.ignore(); 
                         f.write((char *) &e,sizeof(e)); 
                         cin.ignore(); 
                         cout<<"\n\n Do You Want to Continue?(Y/N) : "; 
                         cin>>c; 
                         if(c=='n' || c=='N') 
                              break; 
                    } 
                    f.close(); 
                    break; 
                     
               case 2: 
                    f.open("employee.txt",ios::in|ios::binary); 
                    cout<<"\n Enter Employee No.  : "; 
                    cin>>eno; 
                    
                    while(f.read((char *)&e,sizeof(e))) 
 
 
                    { 
                         if(eno == e.empno) 
                         { 
                              cout<<"\n\t"<<e.empno<<" : "<<e.empname;                             
                              break; 
                         } 
                    }  
                    f.close(); 
                    break; 
               case 3: 
                    f.open("employee.txt",ios::in|ios::binary); 
                    while(f.read((char *) &e,sizeof(e))) 
                    { 
                         if(strcmp(e.empname, "XYZ")==0) 
                         { 
                              while(1) 
                              { 
                                   cout<<"\n\t"<<e.empno<<" : "<<e.empname; 
                                   break; 
                              } 
                         } 
                    }  
                    f.close(); 
                    break; 
               case 4: 
                    f.open("employee.txt",ios::in|ios::binary); 
                    f.read((char *) &e,sizeof(e)); 
                    while(f) 
                    { 
                         f.read((char *) &e,sizeof(e)); 
                         cout<<"\n\t"<<e.empno<<" : "<<e.empname; 
                         break; 
                    } 
                    f.close(); 
                    break; 
               case 5: 
                    f.open("employee.txt",ios::in|ios::binary); 
                    cout<<"\n Enter Employee Name  : "; 
                    cin>>ename; 
                    while(f.read((char *) &e,sizeof(e))) 
                    { 
                         if(strcmp(ename,e.empname)==0) 
                         { 
                              while(1) 
                              { 
 
 
                                   cout<<"\n\t"<<e.empno<<" : "<<e.empname; 
                                   break; 
                              } 
                         } 
                    }  
                    f.close(); 
                    break; 
               case 6: 
                    exit(0); 
                     
               default:  
                    cout<<"\n Invalid Choice"; 
            } 
       } 
      
 return 0; 
}