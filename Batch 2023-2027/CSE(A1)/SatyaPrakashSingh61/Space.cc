#include<iostream>
using namespace std;
class Space{
    private:
    int x,y,z;
    public:
        Space(int a,int b,int c){
            x=a;
            y=b;
            z=c;
        }

        void operator -(){
            x=-x;
            y=-y;
            z=-z;
        }
        friend void display(Space);
};
    void display(Space temp){
        cout<<temp.x<<" "<<temp.y<<" "<<temp.z<<endl;
        temp.x=100;//cannot modfiy friend in data...
    }
int main(){
    Space s(10,-20,30);
    cout<<"Object s"<<endl;
    display(s);
    -s;
    cout<<"Now Object s"<<endl;
    display(s);
    return 0;
}