#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <string> 
using namespace std; 
 
class Student { 
private: 
    int rollNumber; 
    string name; 
    int age; 
    string course; 
 
public: 
    // Method to input student details 
    void inputStudentDetails() { 
        cout << "Enter Roll Number: "; 
        cin >> rollNumber; 
        cin.ignore(); 
        cout << "Enter Name: "; 
        getline(cin, name); 
        cout << "Enter Age: "; 
        cin >> age; 
        cin.ignore(); 
        cout << "Enter Course: "; 
        getline(cin, course); 
    } 
 
    // Method to display student details 
    void displayStudentDetails() const { 
        cout << "Roll Number: " << rollNumber << "\nName: " << name 
             << "\nAge: " << age << "\nCourse: " << course << "\n"; 
    } 
 
    // Save student to file 
    void saveToFile() const { 
        ofstream outFile("students.txt", ios::app); 
        if (outFile.is_open()) { 
            outFile << rollNumber << " " << name << " " << age << " " << course << endl; 
            outFile.close(); 
            cout << "Student record added successfully.\n"; 
        } else { 
        cout << "Error: Unable to open file.\n"; 
        } 
    } 
// Static method to search for a student 
    static void searchStudent(int rollNo) { 
        ifstream inFile("students.txt"); 
        string line; 
        bool found = false; 
        if (inFile.is_open()) { 
            while (getline(inFile, line)) { 
                Student s; 
                stringstream ss(line); 
                ss >> s.rollNumber >> ws; 
                getline(ss, s.name, ' '); 
                ss >> s.age >> ws; 
                getline(ss, s.course); 
                if (s.rollNumber == rollNo) { 
                    cout << "\nRecord Found:\n"; 
                    s.displayStudentDetails(); 
                    found = true; 
                    break; 
                } 
            } 
            inFile.close(); 
            if (!found) { 
                cout << "Record not found.\n"; 
            } 
        } else { 
        cout << "Error: Unable to open file.\n"; 
        } 
    } 
    // Static method to delete a student 
    static void deleteStudent(int rollNo) { 
        ifstream inFile("students.txt"); 
        ofstream tempFile("temp.txt"); 
        string line; 
        bool found = false; 
        if (inFile.is_open() && tempFile.is_open()) { 
            while (getline(inFile, line)) { 
                Student s; 
                stringstream ss(line); 
                ss >> s.rollNumber >> ws; 
                getline(ss, s.name, ' '); 
                ss >> s.age >> ws; 
                getline(ss, s.course); 
                if (s.rollNumber != rollNo) { 
                    tempFile << line << endl; 
                } else { 
                    found = true; 
                } 
            } 
            inFile.close(); 
            tempFile.close(); 
            remove("students.txt"); 
            rename("temp.txt", "students.txt"); 
            if (found) { 
                cout << "Record deleted successfully.\n"; 
            } else { 
                cout << "Record not found.\n"; 
            } 
        } else { 
        cout << "Error: Unable to open file.\n"; 
        } 
    } 
    // Static method to display all students 
    static void displayAllStudents() { 
        ifstream inFile("students.txt"); 
        string line; 
        if (inFile.is_open()) { 
            cout << "\nAll Student Records:\n"; 
            while (getline(inFile, line)) { 
                Student s; 
                stringstream ss(line); 
                ss >> s.rollNumber >> ws; 
                getline(ss, s.name, ' '); 
                ss >> s.age >> ws; 
                getline(ss, s.course); 
                s.displayStudentDetails(); 
                cout << endl; 
            } 
            inFile.close(); 
        } else { 
            cout << "Error: Unable to open file.\n"; 
        } 
    } 
}; 
int main() { 
    int choice; 
    do { 
        cout << "\n--- Student Record Management System ---\n"; 
        cout << "1. Add Student\n2. Search Student\n3. Delete Student\n4. Display All Students\n5.Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: { 
                Student s; 
                s.inputStudentDetails(); 
                s.saveToFile(); 
                break; 
            } 
            case 2: { 
                int rollNo; 
                cout << "Enter Roll Number to Search: "; 
                cin >> rollNo; 
                Student::searchStudent(rollNo); 
                break; 
            } 
            case 3: { 
                int rollNo; 
                cout << "Enter Roll Number to Delete: "; 
                cin >> rollNo; 
                Student::deleteStudent(rollNo); 
                break; 
            } 
            case 4: 
                Student::displayAllStudents(); 
                break; 
            case 5: 
                cout << "Exiting the program.\n"; 
                break; 
            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } while (choice != 5); 
    return 0; 
    } 