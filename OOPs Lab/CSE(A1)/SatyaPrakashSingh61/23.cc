#include<iostream>
using namespace std;
class Shape{
    public:
        virtual void draw();
        virtual void erase();
};
class Circle:public Shape{
    void draw(){
        cout<<"Drawing Circle.\n";
    }
    void erase(){
        cout<<"Erasing Circle.\n";
    }
};
class Triangle:public Shape{
    void draw(){
        cout<<"Drawing Triangle.\n";
    }
    void erase(){
        cout<<"Erasing Triangle.\n";
    }
};
class Square:public Shape{
    void draw(){
        cout<<"Drawing Square.\n";
    }
    void erase(){
        cout<<"Erasing Triangle.\n";
    }
};
int main(){
    cout<<"DEMONSTRATION OF RUN TIME POYIMORPHISM"<<endl;
    Shape *sh;//reference
    cout<<"Drawing (sh->draw()) and Erasing (s->erase()) using these command..\n"<<endl;
    Circle cir;
    sh=&cir;
    sh->draw();
    sh->erase();
    cout<<"Drawing (sh->draw()) and Erasing (s->erase()) using these command..\n"<<endl;
    Triangle tri;
    sh=&tri;
    sh->draw();
    sh->erase();
    cout<<"Drawing (sh->draw()) and Erasing (s->erase()) using these command..\n"<<endl;
    Square sq;
    sh=&sq;
    sh->draw();
    sh->erase();
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}