#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    map<string,int>studentScores;
    string name;
    int score;
    cout<<"Enter student name:";
    getline(cin,name);
    cout<<"Enter Score:";
    cin>>score;
    studentScores[name]=score;
    cout<<"Enter student name to search:";
    cin.ignore();
    getline(cin,name);
    if(studentScores.find(name)!=studentScores.end()){
        cout<<name<<"'s score:"<<studentScores[name]<<endl;
    }
    else{
        cout<<"Student Record not found!"<<endl;
    }
    cout<<"Enter student name to update score:";
    getline(cin,name);
    if(studentScores.find(name)!=studentScores.end()){
        cout<<"Enter new score:";
        cin>>score;
        studentScores[name]=score;
        cout<<name<<"'s new score: "<<studentScores[name]<<endl; 
    }
    else{
        cout<<"Student Record not found!"<<endl;
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}