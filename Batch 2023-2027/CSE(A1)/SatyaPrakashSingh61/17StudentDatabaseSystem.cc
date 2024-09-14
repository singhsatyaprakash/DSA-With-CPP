#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Student{
public:
    string name;
    int rollNumber;
    string course;
    float marks;
    //Constructor..
    Student(string n,int r,string c,float m):name(n),rollNumber(r),course(c),marks(m){}
    void display() {
        cout<<setw(15)<<name<<setw(15)<<rollNumber<<setw(15)<<course<<setw(10)<<marks<<endl;
    }
};
// Function declarations
void addStudent(Student** &students, int &numStudents);
void deleteStudent(Student** &students, int &numStudents, int rollNumber);
void viewStudents(Student** students, int numStudents);
float calculateAverageMarks(Student** students, int numStudents);
void findTopStudent(Student** students, int numStudents);

int main() {
    Student** students=nullptr;  // Pointer to dynamically allocated array of Student pointers
    int numStudents = 0;           // Number of students
    int choice,rollNumber;

    while(true){
        // Display menu
        cout<<"\nStudent Database System\n";
        cout<<"1. Add Student\n";
        cout<<"2. Delete Student\n";
        cout<<"3. View All Students\n";
        cout<<"4. Calculate Average Marks\n";
        cout<<"5. Find Student with Highest Marks\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                addStudent(students, numStudents);
                break;
            case 2:
                cout << "Enter roll number to delete: ";
                cin >> rollNumber;
                deleteStudent(students, numStudents, rollNumber);
                break;
            case 3:
                viewStudents(students, numStudents);
                break;
            case 4:
                cout << "Average Marks: " << calculateAverageMarks(students, numStudents) << endl;
                break;
            case 5:
                findTopStudent(students, numStudents);
                break;
            case 6:
                // Free dynamically allocated memory
                for (int i = 0; i < numStudents; i++) {
                    delete students[i];
                }
                delete[] students;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

// Function to add a new student
void addStudent(Student** &students, int &numStudents) {
    string name, course;
    int rollNumber;
    float marks;

    cout << "Enter student name: ";
    cin.ignore();  // Clear input buffer
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;
    cout << "Enter course: ";
    cin.ignore();  // Clear input buffer
    getline(cin, course);
    cout << "Enter marks: ";
    cin >> marks;

    // Create a new Student object
    Student* newStudent = new Student(name, rollNumber, course, marks);

    // Resize the students array
    Student** temp = new Student*[numStudents + 1];
    for (int i = 0; i < numStudents; i++) {
        temp[i] = students[i];
    }
    temp[numStudents] = newStudent;

    delete[] students;  // Free old array
    students = temp;    // Assign new array
    numStudents++;      // Increase the number of students

    cout << "Student added successfully!" << endl;
}

// Function to delete a student by roll number
void deleteStudent(Student** &students, int &numStudents, int rollNumber) {
    int index = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found!" << endl;
        return;
    }

    // Delete the student and shift the array
    delete students[index];
    for (int i = index; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    // Resize the students array
    Student** temp = new Student*[numStudents - 1];
    for (int i = 0; i < numStudents - 1; i++) {
        temp[i] = students[i];
    }

    delete[] students;  // Free old array
    students = temp;    // Assign new array
    numStudents--;      // Decrease the number of students

    cout << "Student deleted successfully!" << endl;
}

// Function to view all students in a tabular format
void viewStudents(Student** students, int numStudents) {
    if (numStudents == 0) {
        cout << "No students available!" << endl;
        return;
    }

    // Display table headers
    cout << setw(15) << "Name"
         << setw(15) << "Roll Number"
         << setw(15) << "Course"
         << setw(10) << "Marks" << endl;
    cout << "-------------------------------------------------------------" << endl;

    // Display student data in tabular format
    for (int i = 0; i < numStudents; i++) {
        students[i]->display();
    }
}

// Function to calculate the average marks of all students
float calculateAverageMarks(Student** students, int numStudents) {
    if (numStudents == 0) return 0;

    float totalMarks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i]->marks;
    }
    return totalMarks / numStudents;
}

// Function to find the student with the highest marks
void findTopStudent(Student** students, int numStudents) {
    if (numStudents == 0) {
        cout << "No students available!" << endl;
        return;
    }

    Student* topStudent = students[0];
    for (int i = 1; i < numStudents; i++) {
        if (students[i]->marks > topStudent->marks) {
            topStudent = students[i];
        }
    }

    cout << "Top Student:" << endl;
    topStudent->display();
}
