#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Member class to store details of a library member
class Member {
    int MemberID;
    string MemberName;
    string MemberType;

public:
    Member(int MemberID, string MemberName, string MemberType)
        : MemberID(MemberID), MemberName(MemberName), MemberType(MemberType) {}

    int getMemberID() { return MemberID; }
    string getMemberName() { return MemberName; }
    string getMemberType() { return MemberType; }
};

// Book class to store details of a library book
class Book {
    int BookID;
    string Title;
    string Publisher;
    string Author;
    int Edition;

public:
    Book(int BookID, string Title, string Publisher, string Author, int Edition)
        : BookID(BookID), Title(Title), Publisher(Publisher), Author(Author), Edition(Edition) {}

    int getBookID(){ 
        return BookID;
    }
    string getTitle() { return Title; }
    string getPublisher() { return Publisher; }
};

// LibraryDb class to manage members, books, and their interactions
class LibraryDb {
    static vector<Member> Members;       // List of members
    static vector<int> BooksTaken;       // Number of books taken by each member
    static vector<Book> Books;           // List of books
    static vector<bool> BookStatus;      // true = available, false = issued

public:
    // Function to add a new member
    static void AddMember() {
        int MemberID;
        string MemberName, MemberType;

        cout << "Enter Member ID: ";
        cin >> MemberID;
        cin.ignore(); // Ignore leftover newline
        cout << "Enter Member Name: ";
        getline(cin, MemberName);
        cout << "Enter Member Type (Student/Faculty): ";
        getline(cin, MemberType);

        Members.push_back(Member(MemberID, MemberName, MemberType));
        BooksTaken.push_back(0); // Initialize books taken for this member
        cout << "Member added successfully!\n";
    }

    // Function to add a new book
    static void AddBook() {
        int BookID, Edition;
        string Title, Publisher, Author;

        cout << "Enter Book ID: ";
        cin >> BookID;
        cin.ignore(); // Ignore leftover newline
        cout << "Enter Book Title: ";
        getline(cin, Title);
        cout << "Enter Publisher: ";
        getline(cin, Publisher);
        cout << "Enter Author: ";
        getline(cin, Author);
        cout << "Enter Edition: ";
        cin >> Edition;

        Books.push_back(Book(BookID, Title, Publisher, Author, Edition));
        BookStatus.push_back(true); // Mark book as available
        cout << "Book added successfully!\n";
    }

    // Validate if a member can issue more books
    static bool ValidateMemberEligibility(int MemberID) {
        if (MemberID >= Members.size()) {
            cout << "Invalid Member ID!\n";
            return false;
        }
        return BooksTaken[MemberID] < 5; // Limit to 5 books per member
    }

    // Validate if a book is available
    static bool ValidateBookAvailability(int BookID) {
        for (int i = 0; i < Books.size(); i++) {
            if (Books[i].getBookID() == BookID && BookStatus[i]) {
                return true;
            }
        }
        return false;
    }

    // Function to issue a book
    static void IssueBook() {
        int MemberID, BookID;
        cout << "Enter Member ID: ";
        cin >> MemberID;
        MemberID--; // Adjust index to zero-based
        cout << "Enter Book ID: ";
        cin >> BookID;

        if (ValidateMemberEligibility(MemberID) && ValidateBookAvailability(BookID)) {
            BooksTaken[MemberID]++;
            for (int i = 0; i < Books.size();i++){
                if(Books[i].getBookID() == BookID) {
                    BookStatus[i] = false; // Mark book as issued
                    break;
                }
            }
            cout << "Book issued successfully!\n";
        } else {
            cout << "Book issue failed. Either the book is unavailable or the member has exceeded the limit.\n";
        }
    }

    // Display all members
    static void DisplayMembers() {
        cout << "\nMembers List:\n";
        for ( auto member : Members) {
            cout << "ID: " << member.getMemberID() << ", Name: " << member.getMemberName() << ", Type: " << member.getMemberType() << endl;
        }
    }

    // Display all books
    static void DisplayBooks() {
        cout << "\nBooks List:\n";
        for (int i = 0; i < Books.size(); ++i) {
            cout << "ID: " << Books[i].getBookID() << ", Title: " << Books[i].getTitle()
                 << ", Status: " << (BookStatus[i] ? "Available" : "Issued") << endl;
        }
    }
};

// Static member initialization
vector<Member> LibraryDb::Members;
vector<int> LibraryDb::BooksTaken;
vector<Book> LibraryDb::Books;
vector<bool> LibraryDb::BookStatus;

int main(){
    int choice;
    do {
        cout << "\n************** Library Management System **************\n";
        cout << "1. Add a Member\n";
        cout << "2. Add a Book\n";
        cout << "3. Issue a Book\n";
        cout << "4. Display Members\n";
        cout << "5. Display Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            LibraryDb::AddMember();
            break;
        case 2:
            LibraryDb::AddBook();
            break;
        case 3:
            LibraryDb::IssueBook();
            break;
        case 4:
            LibraryDb::DisplayMembers();
            break;
        case 5:
            LibraryDb::DisplayBooks();
            break;
        case 0:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}





















// #include<iostream>
// #include<string>
// using namespace std;
// class Member{
//     int Member_Id;
//     string Member_Name;
//     string Member_Type;
//     public:
//     Member(int Member_Id,string Member_Name,string Member_Type){
//         this->Member_Id=Member_Id;
//         this->Member_Name=Member_Name;
//         this->Member_Type=Member_Type
//     }
//     int getMemberID(){
//         return Member_Id;
//     }
//     string getMemberName(){
//         return Member_Name;
//     }
//     string getMemberType(){
//         return Member_Type;
//     }
// };
// class Book{
//     int BookID;
//     string Title;
//     string Publisher;
//     string Author;
//     int Edition;
//     public:
//     Book(int BookID, string Title, string Publisher,string Author, int Edition){
//         this->BookID=BookID;
//         this->Title=Title;
//         this->Publisher=Publisher;
//         this->Author=Author;
//         this->Edition=Edition;
//     }
//     int getBookId(){
//         return BookID;
//     }
//     string getTitle(){
//         return Title;
//     }
//     string getPublisher(){
//         return Publisher;
//     }
// };
// class Journal:public Book{
//     string Editor;
//     int Volume;
//     int Issue;
//     public:
//     Journal(int bookID,string title,string publisher,string Author, int Edition,string editor,int volume,int issue):
//         Book(BookID, Title, Publisher,Author,Edition),
//         Editor(Editor),Volume(Volume),Issue(Issue){}
//     string getEditor(){
//         return  Editor;
//     }
//     int getVolume(){
//         return Volume;
//     }
//     int getIssue(){
//         return Issue;
//     }
// };
// class LibraryDb:public Member,Book{
//     static vector<Member>Members;
//     static vector<int> BooksTaken; // Number of books taken by each member
//     static vector<Book> Books;
//     static vector<bool> BookStatus; // true = available, false = issued
//     public:
//     // //storing book details..
//     // static void InitializeLibrary() {
//     //     Members.push_back(Member(1, "SatyaPrakash", "Student"));
//     //     Members.push_back(Member(2, "Aayush", "Faculty"));

//     //     Books.push_back(Book(101, "C++ Programming", "Oxford", "Reema Thareja", 1));
//     //     Books.push_back(Book(102, "Discrete Mathematics", "S.Chand", "Swapan Kumar", 9));
//     //     Books.push_back(Book(103, "Digital Logic", "Pearson", "Mano", 4));
//     //     Books.push_back(Book(104, "Data Structure", "Oxford", "Reema Thareja", 2));

//     //     BooksTaken.resize(Members.size(), 0); // Initialize books taken to 0 for each member
//     //     BookStatus.resize(Books.size(), true); // All books are initially available
//     // }
//     bool ValidateMemberEligibility(int MemberID){
//         if(BookTaken[MemberID]<5){//eligible 
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     bool ValidateBookAvailability(int BookID){
        
//         return false;
//     }
//     void Issuebook(int MemberID, int BookID){
//         if(ValidateMemberEligibility(MemberID) && ValidateBookAvailability(BookID)){
//             BooksTaken[MemberID]++;
//             BookStatus[bookID]=false;
//             }
//         }
// };

// vector<Member> LibraryDb::Members;
// vector<int> LibraryDb::BooksTaken;
// vector<Book> LibraryDb::Books;
// vector<bool> LibraryDb::BookStatus;

// class Transaction{
//     int Tid;
//     Member mObj;
//     Book bObj;
//     public:
//     Transaction(int tid,Member member,Book book):Tid(tid),mObj(member), bObj(book) {
//         BorrowDate = getCurrentDate();
//         ReturnDate = calculateReturnDate();
//     }

//     void BorrowBook() {
//         cout << "Transaction ID: " << Tid << endl;
//         cout << "Borrow Date: " << BorrowDate << endl;
//         cout << "Return Date: " << ReturnDate << endl;

//         // Update library database
//         LibraryDb::IssueBook(mObj.getMemberID() - 1, bObj.getBookID() - 101); // Adjust indices for array
//     }
// };
// int main(){
//     int choice;
//     do{
//         cout<<"************************          MENU            *************************"<<endl;
//         cout<<"1.Create a new Member."<<endl;
//         cout<<"2.Store new Book"<<endl;
//         cout<<"3.Issue A Book."<<endl;
//         cout<<"4.Return Book."<<endl;
//         cout<<"0.Exiting System."<<endl;
//         cout<<"Choice:";
//         cin>>choice;
//         switch(choice){
//             case 1:{
//                 int Member_Id;
//                 string Member_Name,Member_Type;
//                 cout<<"Enter Member Id:";
//                 cin>>Member_Id;
//                 cout<<"Enter name of Member:"<<endl;
//                 getline(cin,Member_Name);
//                 cout<<"Enter memeber Type:";
//                 getline(cin.Member_Type);
//                 Members.push_back(Member(Member_Id,Member_Name,Member_Type));
//                 break;
//             }
//             case 2:{
//                     int BookID,Edition;
//                     string Title,Publisher,Author;
//                     cout<<"Enter BookId:";
//                     cin>>bookID;
//                     cout<<"Book Title:";
//                     getline(cin,Title);
//                     cout<<"Enter Publisher:";
//                     getline(cin,Publisher);
//                     cout<<"Enter Author:";
//                     getline(cin,Author);
//                     cout<<"Enter Edition:";
//                     cin>>Edition;
//                     Books.push_back(Book(BookID,Title,Publisher,Author,Edition));
//             }

//         }
//     }while(choice!=0);
//     return 0;
// }
