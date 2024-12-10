#include<iostream> 
#include<fstream> 
using namespace std; 
 
 
class Student 
{ 
    private: 
    int rn; 
    string name; 
    public: 
    void getdata() 
    { 
        cout<<"\n Enter the Roll No and Name:"; 
        cin>>rn;
        cin.ignore();
        cin>>name;
    } 
}; 
int main() 
{ 
    Student s1; 
    s1.getdata(); 
    ofstream in("Sample1.txt"); 
    in.write((char*) &s1 ,sizeof(s1)); 
    in.close();
    ifstream out;
    out.open("Sample.txt");
    out.read((cahr*) &out,sizeof()

} 