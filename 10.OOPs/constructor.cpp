#include<iostream>
#include<string>
using namespace std;
class User{
private:
    int id;
    string password;
public:
    string username;
    //constructor with parameter...
    User(int id){
        this->id=id;//special pointer which distgiush b/w the class id and formal parameter...
    }

//setter for password
void setPassword(string password){
    this->password=password;
}

//getter for password
string getPassword(){
    return password;
}
};

int main(){
User s1(230112058);//object of User class...,calling constructor
s1.username="kingofmidgard";///providing input to username as it is public assign directely....
s1.setPassword("kundan singh");//providing input password by setter because it is private...
cout<<"UserName:"<<s1.username<<endl;//directely can access...
cout<<"Password:"<<s1.getPassword()<<endl;//as it is private we need getter to access this....
    return 0;
}