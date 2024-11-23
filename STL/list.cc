#include<iostream>
#include<list>
using namespace std;
void printL(list<int>ls){
    for(auto i:ls){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    list<int>ls;
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(3);
    ls.push_back(3);
    ls.push_back(3);
    ls.push_back(4);
    ls.push_front(34);
    printL(ls);
    ls.pop_back();
    printL(ls);
    ls.pop_front();
    printL(ls);
    ls.remove(3);//all 3 will delelte
    printL(ls);

}