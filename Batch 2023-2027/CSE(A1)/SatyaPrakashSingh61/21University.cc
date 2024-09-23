/*
21. In a university, a University has multiple Departments. Define a University class that aggregates multiple Department objects. Each department has properties like name, facultyCount, and headOfDepartment. The university "has" departments, but departments can exist independently.
Note: The University aggregates Department objects, where the departments are part of the university but exist independently (e.g., a department might be transferred or merged with another university).
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Department {
private:
    string name;
    int facultyCount;
    string headOfDepartment;
public:
    Department(string deptName,int count,string head):name(deptName),facultyCount(count),headOfDepartment(head){}
    void display()const{
        cout<<"\nDepartment: "<<name<<endl;
        cout<<"Faculty Count: "<<facultyCount<<endl;
        cout<<"Head of Department: "<<headOfDepartment<<endl;
    }
};
class University{
private:
    string name;
    vector<Department*>departments;//University has multiple Departments...
public:
    University(string uniName):name(uniName){}
    // Function to add a department to the university
    void addDepartment(Department* dept) {
        departments.push_back(dept);
    }
    void displayDepartments()const{
        cout<<"\nUniversity: "<<name<<endl;
        for(const auto& dept:departments){
            dept->display();
            cout<<endl;
        }
    }
};

int main() {
    // Creating departments independently...
    Department* CSE_Dept=new Department("Computer Science & Engineering",50,"Prof.Dibyahash Bordoloi");
    Department* Math_Dept=new Department("Mathematics",30, "Dr.Neeraj Dhiman");
    // Creating university
    University uni("Graphic Era Hill University");
    // Aggregating departments into the university
    uni.addDepartment(CSE_Dept);
    uni.addDepartment(Math_Dept);
    // Display all departments in the university
    uni.displayDepartments();
    // Departments exist independently, so we delete them manually
    delete CSE_Dept;
    delete Math_Dept;
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Excuted By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}
