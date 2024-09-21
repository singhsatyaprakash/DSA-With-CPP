#include<iostream>
#include<string.h>
#include<vector>
#include<iomanip>
using namespace std;
class Student{
public:
    string name;
    int rollNumber;
    string course;
    float marks;
    Student(string n,int r,string c,float m):name(n),rollNumber(r),course(c),marks(m){}
};
class StudentDatabase{
private:
    vector<Student*>students;
public:
    ~StudentDatabase() {
        for (Student* student : students) {
            delete student;
        }
    }
    void addStudent(){
        string name,course;
        int rollNumber;
        float marks;
        cout<<"Enter name: ";
        getline(cin,name);
        cout<<"Enter roll number: ";
        cin>>rollNumber;
        cout<<"Enter course: ";
        getline(cin,course);
        cout<<"Enter marks: ";
        cin>>marks;
        Student* newStudent= new Student(name,rollNumber,course,marks);
        students.push_back(newStudent);
        cout<<"Student added successfully!\n";
    }

    void deleteStudent() {
        int rollNumber;
        cout << "Enter roll number of the student to delete: ";
        cin >> rollNumber;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if ((*it)->rollNumber == rollNumber) {
                delete *it;
                students.erase(it);
                cout << "Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void viewStudents() const {
        cout << fixed << setprecision(2);
        for (const Student* student : students) {
            cout << "Name: " << student->name
                 << ", Roll Number: " << student->rollNumber
                 << ", Course: " << student->course
                 << ", Marks: " << student->marks << '\n';
        }
    }

    void calculateAverageMarks() const {
        if (students.empty()) {
            cout << "No students in the database.\n";
            return;
        }

        float totalMarks = 0;
        for (const Student* student : students) {
            totalMarks += student->marks;
        }
        float average = totalMarks / students.size();
        cout << "Average Marks: " << average << '\n';
    }

    void findHighestMarks() const {
        if (students.empty()) {
            cout << "No students in the database.\n";
            return;
        }

        Student* highestStudent = students[0];
        for (Student* student : students) {
            if (student->marks > highestStudent->marks) {
                highestStudent = student;
            }
        }
        cout << "Student with Highest Marks: " 
             << highestStudent->name 
             << " (Roll Number: " << highestStudent->rollNumber 
             << ", Marks: " << highestStudent->marks << ")\n";
    }
};

int main() {
    StudentDatabase db;
    int choice;

    do {
        cout << "\nStudent Database System\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. View Students\n";
        cout << "4. Calculate Average Marks\n";
        cout << "5. Find Highest Marks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: db.addStudent(); break;
            case 2: db.deleteStudent(); break;
            case 3: db.viewStudents(); break;
            case 4: db.calculateAverageMarks(); break;
            case 5: db.findHighestMarks(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
