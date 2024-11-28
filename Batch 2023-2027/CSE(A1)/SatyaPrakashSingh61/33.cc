#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>numbers;
    int num;
    cout<<"Enter up to 20 integers (enter a negative number to stop):\n ";
    while(numbers.size()<20){
        cin>>num;
        if(num<0){
            break;
        }
        numbers.push_back(num);
    }
    cout<<"List Before Modification:"<<endl;
    for(int n:numbers){
        cout<<n<<" ";
    }
    if(!numbers.empty()){
        numbers.pop_front();
        numbers.pop_back();
    }
    cout<<"\nList After Modification:"<<endl;
    for(int n:numbers){
        cout<<n<<" ";
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}