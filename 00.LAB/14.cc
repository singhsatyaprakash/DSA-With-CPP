#include<iostream>
using namespace std;
class Score{
    int score;
    public:
        Score():score(0){}
        Score(int val):score(val){}
        Score& operator ++ (){
            cout<<"Pre-fix called."<<endl;
            score+=10;
            return *this;
        }
        Score operator ++ (int){//Postfix
        cout<<"Post-fix called."<<endl;
            Score temp=*this;
            score+=10;
            return temp;//return original 
        }
        void display() const{
            cout<<"Score:"<<score<<endl;
        }
};
int main(){
    Score s1(50);
    cout<<"Before increment"<<endl;
    s1.display();
    ++s1;
    s1.display();
    s1++;
    s1.display();
    return 0;
}