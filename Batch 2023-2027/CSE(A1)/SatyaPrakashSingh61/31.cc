#include <iostream> 
#include <fstream> 
#include <cstring> 
using namespace std; 
class Student { 
    int rollNumber; 
    char name[50]; 
    int age; 
    char course[50]; 
public: 
    void getDetails() { 
        cout << "Enter Roll Number: "; 
        cin >> rollNumber; 
        cin.ignore(); 
        cout << "Enter Name: "; 
        cin.getline(name,50); 
        cout << "Enter Age: "; 
        cin >> age; 
        cin.ignore(); 
        cout << "Enter Course: "; 
        cin.getline(course,50); 
        } 
 
    void showDetails() const { 
        cout << "Roll Number: " << rollNumber << endl; 
        cout << "Name: " << name << endl; 
        cout << "Age: " << age << endl; 
        cout << "Course: " << course << endl; 
    } 
 
    int getRollNumber() const { 
        return rollNumber; 
    } 
 
    void writeToFile(fstream &file) const { 
        file.write((const char*) this, sizeof(Student)); 
    } 
 
    void readFromFile(fstream &file) { 
 
 
        file.read((char*) this, sizeof(Student)); 
    } 
}; 
 
void addStudent() { 
    fstream file("students.dat", ios::out | ios::app | ios::binary); 
    if (!file) { 
        cerr << "Error opening file." << endl; 
        return; 
    } 
    Student student; 
    student.getDetails(); 
    student.writeToFile(file); 
    file.close(); 
    cout << "Student added successfully." << endl; 
} 
 
void searchStudent() { 
    fstream file("students.dat", ios::in | ios::binary); 
    if (!file) { 
        cerr << "Error opening file." << endl; 
        return; 
    } 
    int rollNumber; 
    cout << "Enter Roll Number to search: "; 
    cin >> rollNumber; 
 
    Student student; 
    bool found = false; 
    while (file.read((char*) (&student), sizeof(Student))) { 
        if (student.getRollNumber() == rollNumber) { 
            cout << "Record found:" << endl; 
            student.showDetails(); 
            found = true; 
            break; 
        } 
    } 
    file.close(); 
    if (!found) { 
        cout << "Record not found." << endl; 
    } 
} 
 
void deleteStudent() { 
    fstream file("students.dat", ios::in | ios::binary); 
    fstream tempFile("temp.dat", ios::out | ios::binary); 
    if (!file || !tempFile) { 
        cerr << "Error opening file." << endl; 
        return; 
    } 
    int rollNumber; 
    cout << "Enter Roll Number to delete: "; 
    cin >> rollNumber; 
 
    Student student; 
    bool found = false; 
    while (file.read((char*) (&student), sizeof(Student)))  
   { 
        if (student.getRollNumber() == rollNumber) { 
            found = true; 
        } else { 
            student.writeToFile(tempFile); 
        } 
    } 
    file.close(); 
    tempFile.close(); 
 
    remove("students.dat"); 
    rename("temp.dat", "students.dat"); 
 
    if (found) { 
        cout << "Record deleted successfully." << endl; 
    } else { 
        cout << "Record not found." << endl; 
    } 
} 
void displayAllStudents() { 
    fstream file("students.dat", ios::in | ios::binary); 
    if (!file) { 
        cerr << "Error opening file." << endl; 
        return; 
    } 
    Student student; 
    cout << "Student Records:" << endl; 
    while (file.read((char*)(&student), sizeof(Student))) { 
        student.showDetails(); 
        cout << "----------------------" << endl; 
    } 
    file.close(); 
} 
int main() { 
    int choice; 
        cout << "\nMenu:\n"; 
        cout << "1. Add Student\n"; 
        cout << "2. Search Student\n"; 
        cout << "3. Delete Student\n"; 
        cout << "4. Display All Students\n"; 
        cout << "0. Exit\n"; 
    do { 
        cout << "Choice: "; 
        cin >> choice; 
        cin.ignore(); 
 
        switch (choice) { 
            case 1: 
                addStudent(); 
                break; 
            case 2: 
                searchStudent(); 
                break; 
            case 3: 
                deleteStudent(); 
                break; 
            case 4: 
                displayAllStudents(); 
                break; 
            case 0: 
                cout << "Exiting program." << endl; 
                break; 
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } while (choice != 0); 
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0; 
} 