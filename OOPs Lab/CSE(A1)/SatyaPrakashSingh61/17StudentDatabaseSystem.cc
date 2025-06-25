#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
class Student{
public:
    string name;
    int roll_number;
    string course;
    float marks;
    //Constructor with parameter...
    Student(string n,int r,string c,float m){
        name=n;
        roll_number=r;
        course=c;
        marks=m;
    }
};

//Function to add a student
void addStudent(vector<Student*>& students){//all vector are call by value we need to pass it as reference...
    string name;
    string course;
    int roll_number;
    float marks;
    cout<<"Enter student's name: ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Enter roll number: ";
    fflush(stdin);
    cin>>roll_number;
    cout<<"Enter course: ";
    fflush(stdin);
    getline(cin,course);
    cout<<"Enter marks: ";
    fflush(stdin);
    cin>>marks;
    students.push_back(new Student(name,roll_number,course,marks));//creating object...dynmaically
    cout<<"Student added successfully."<<endl;
    return;
}
// Function to delete a student
void deleteStudent(vector<Student*>& students){
    if(students.empty()){
        cout<<"No students to delete."<<endl;//empty vector...
        return;
    }
    int roll_number;
    cout<<"Enter roll number of the student to delete: ";
    cin>>roll_number;
    for (auto i=students.begin();i!= students.end();i++){
        if((*i)->roll_number==roll_number){
            delete *i;  // Free memory allocated to that student...
            students.erase(i);//delete student data..
            cout<<"Student record deleted successfully."<<endl;
            return;
        }
    }
    cout<<"Student with roll number "<<roll_number<<" not found."<<endl;
}
// Function to view all students in tabular form
void viewStudents(const vector<Student*>& students){//cannot modify data at time of printing..
    if(students.empty()){
        cout<<"No students to display."<<endl;
        return;
    }
    // Print table header
    //left algin the data in left side by default it is in right side...
    cout<<left<<setw(20)<<"Name"<<setw(15)<<"Roll Number"<<setw(20)<<"Course"<<setw(10)<<"Marks"<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    // Printing student's details
    for (const auto& student:students){
        cout<<left<<setw(20)<<student->name<<setw(15)<<student->roll_number<<setw(20)<<student->course<<setw(10)<<student->marks<<endl;
    }
}
// Function to calculate average marks of all students
float calculateAverageMarks(const vector<Student*>& students) {
    if (students.empty()) {
        cout<<"No students to calculate average marks."<<endl;
        return 0;
    }
    float totalMarks=0;
    for (const auto& student:students){
        totalMarks+=student->marks;
    }
    return totalMarks/students.size();
}
// Function to find the student with the highest marks
Student* findHighestMarks(const vector<Student*>& students) {
    if(students.empty()){
        cout<<"No students to search for highest marks."<<endl;
        return nullptr;
    }
    Student* topStudent=students[0];
    for(const auto& student:students){
        if(student->marks > topStudent->marks){
            topStudent=student;
        }
    }
    return topStudent;
}
int main(){
    vector<Student*>students; //Vector to store student records using pointers
    int choice;
        cout<<"\nStudent Information System Menu"<<endl;
        cout<<"Press[1] for Add Student"<<endl;
        cout<<"Press[2] for Delete Student"<<endl;
        cout<<"Press[3] for View Students Record"<<endl;
        cout<<"Press[4] for Calculate Average Marks"<<endl;
        cout<<"Press[5] for Find Student with Highest Marks"<<endl;
        cout<<"Press[0] for Exit"<<endl;
    do{
        cout<<"Choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            addStudent(students);
            break;
        case 2:
            deleteStudent(students);
            break;
        case 3:
            viewStudents(students);
            break;
        case 4:{
            float avgMarks=calculateAverageMarks(students);//pass vector..
            if(avgMarks>0){
                cout<<"Average Marks: "<<avgMarks<<endl;
            }
            break;
        }
        case 5:{
            Student* topStudent=findHighestMarks(students);
            if(topStudent!=nullptr){
                cout<<"Top Student: "<<topStudent->name<<" with marks: "<<topStudent->marks<<endl;
            }
            break;
        }
        case 0:
            cout<<"Exiting the system"<<endl;
            break;
        default:
            cout << "Invalid choice!"<<endl;
        }
    }while(choice!=0);
    // Free allocated memory
    for(auto& student:students){
        delete student;
    }
    return 0;
}
