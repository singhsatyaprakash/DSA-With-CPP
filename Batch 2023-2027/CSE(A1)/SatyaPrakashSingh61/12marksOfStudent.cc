/*
12.Anna is competing to be the top student in her high school. She wants to know how many of her classmates scored higher than she did on their exams this semester.
You need to create a class named Student with the following features:
Data Members:
An array scores[5] that stores a student's scores for 5 exams.
Member Functions:
A void input() function that reads 5 exam scores and stores them in the scores array.
An int calculateTotalScore() function that calculates and returns the sum of the scores in the scores array.*/
#include<iostream>
using namespace std;
class Student{
    private:
        int scroes[5];
    public:
        void input(){
            static int j=1;
            cout<<"Enter 5 subjects marks of student "<<j++<<":"<<endl;
            for(int i=0;i<5;i++){
                cin>>scroes[i];
            }
        }
        int CalculatetotalScore(){
            int sum=0;
            for(int i=0;i<5;i++){
                sum+=scroes[i];
            }
            return sum;
        }
};

int main(){
    int n;
    cout<<"How many students:";
    cin>>n;
    //creating Student object...
    Student s[n];
    for(int i=0;i<n;i++){
        s[i].input();
    }
    int annaScore=s[0].CalculatetotalScore();
    int maxScore=annaScore;
    //finding which student have high marks then anna..
    int highmarkStudent=0;
    for(int i=1;i<n;i++){
        if(s[i].CalculatetotalScore()>annaScore){
            ++highmarkStudent;
        }
    }
    cout<<"No. of student having higer marks than Anna are: "<<highmarkStudent<<endl;
    cout<<"****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}