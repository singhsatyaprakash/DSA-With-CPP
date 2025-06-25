#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    list<int>numbers;
    int num;
    cout<<"Enter integers (enter a negative number to stop):\n";
    while(true){
        cin>>num;
        if(num<0){
            break;
        }
        numbers.push_back(num);
    }
    numbers.sort();
    numbers.unique();
    cout<<"Unique elements in the list:";\
    for(int n:numbers){
        cout<<n<<" ";
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}