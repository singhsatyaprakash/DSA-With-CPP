#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Student{
public:
    int marks;
    string name;
    Student(string name,int marks){
        this->marks=marks;
        this->name=name;
    }
    //to create heap of class student we have to overload..
    bool operator < (const Student&obj)const{
        return this->marks < obj.marks; //max heap  
    }
};
int main(){
    priority_queue<Student>pq;
    pq.push(Student("Satya",92));
    pq.push(Student("Apoorva",95));
    pq.push(Student("Deepak",90));
    while(!pq.empty()){
        cout<<pq.top().name<<endl;
        pq.pop();
    }
    return 0;
}
