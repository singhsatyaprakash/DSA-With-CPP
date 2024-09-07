#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void printList(list<int>ll){
    list<int>::iterator itr;//list ke traf point kar sakta hai
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<" ";
    }
    cout<<endl;
}
int main(){
    list<int>ll;
    //push...
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    //print..
    printList(ll);
    //size
    cout<<"Size of list:"<<ll.size()<<endl;
    //head..
    cout<<"Head:"<<ll.front()<<endl;
    //tail..
    cout<<"Tail:"<<ll.back()<<endl; 

    //pop..
    ll.pop_front();
    ll.pop_back();
    printList(ll);
    cout<<"Size of list:"<<ll.size()<<endl;
    cout<<"Head:"<<ll.front()<<endl;
    cout<<"Tail:"<<ll.back()<<endl;

    //insertion..
    auto itr=ll.begin();
    advance(itr,1);
    ll.insert(itr,15,1);
    //print...
    printList(ll);
    return 0;
}