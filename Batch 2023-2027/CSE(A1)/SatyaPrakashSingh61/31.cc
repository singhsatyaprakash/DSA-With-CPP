#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class Student{
    int rollNumber;
    string name;
    int age;
    string course;
    public:
    //method to input student details
    void inputStudentDetails(){
        cout<<"Enter roll Number:";
        cin>>rollNumber;
        cout<<"Enter Name:";
        getline(cin,name);
        cout<<"Enter Age:";
        cin>>age;
        cout<<"Enter Course:";
        getline(cin,course);
    }
    void displayStudentDetails(){
        cout<<"Roll Number:"<<rollNumber<<"\nName:"<<name<<"\nAge:"<<age<<"\nCourse:"<<course<<"\n";
    }
    void saveToFile() const{
        ofstream outFile("students.txt",ios::app);
        if(outFile.is_open()){
            outFile<<rollNumber<<" "<<name<<" "<<age<<" "<<course<<endl;
            outFile.close();
            cout<<"Student record added sucessfully.\n";
        }
        else{
            cout<<"Error:Unable to open file.\n";
        }
    }
    static void searchStudents(int rollNo){
        ifstream inFile("students.txt");
        string line;
        bool found=false;
        if(inFile.is_open()){
            while(getline(inFile,line)){
                Student s;
                stringstream ss(line);
                ss>>s.rollNumber>>ws;
                getline(ss,s.name,' ');
                ss>>s.age>>ws;
                getline(ss,s.course);
                if(s.rollNumber==rollNo){
                    cout<<"\nRecord Found.\n";
                    s.displayStudentDetails();
                }
            }
        }
    }
};
int main(){
    
}
