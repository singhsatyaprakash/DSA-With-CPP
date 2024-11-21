#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Member {
private:
    int MemberID;
    string MemberName;
    string MemberType;

public:
    //Constructors
    Member(int id, string name, string type) {
        MemberID = id;
        MemberName = name;
        MemberType = type;
    }

    //Methods
    int getMemberID() const {
        return MemberID;
    }

    string getMemberName() const {
        return MemberName;
    }

    string getMemberType() const {
        return MemberType;
    }
};

class Book {
private:
    int BookID;
    string Title;
    string Publisher;
    string Author;
    int Edition;

public:
    // Constructor
    Book(int id, string title, string publisher, string author, int edition) {
        BookID = id;
        Title = title;
        Publisher = publisher;
        Author = author;
        Edition = edition;
    }

    //Methods
    int getBookID() const {
        return BookID;
    }

    string getTitle() const {
        return Title;
    }

    string getPublisher() const {
        return Publisher;
    }

    string getAuthor() const {
        return Author;
    }

    int getEdition() const {
        return Edition;
    }
};

class Journal : public Book {
private:
    string Editor;
    int Volume;
    int Issue;

public:
    Journal(int id, string title, string publisher, string author, int edition, string editor, int volume, int issue)
        : Book(id, title, publisher, author, edition) {
        Editor = editor;
        Volume = volume;
        Issue = issue;
    }

    string getEditor() const {
        return Editor;
    }

    int getVolume() const {
        return Volume;
    }

    int getIssue() const {
        return Issue;
    }
};

class LibraryDb {
public:
    static Member* Members[100];       // Array of pointers to Member objects
    static int BooksTaken[100];        // Array to keep track of number of books each member has taken
    static Book* Books[200];           // Array of pointers to Book objects
    static bool BookStatus[200];       // Array to track availability of books

public:
    static void initializeLibrary() {
        for (int i = 0; i < 200; ++i) {
            BookStatus[i] = true;       // All books are initially available
        }
    }

    // Validate if a member can borrow more books
    static int validateMemberEligibility(int memberID) {
        if (BooksTaken[memberID] < 5) {      // Assume max 5 books per member
            return 1;      // Eligible
        }
        return 0;         // Not eligible
    }

    // Validate if a book is available
    static int validateBookAvailability(int bookID) {
        if(BookStatus[bookID]){
            return 1;
        }
        return 0;
          // 1 if available, 0 if not
    }

    // Issue a book to a member
    static void issueBook(int memberID, int bookID) {
        BooksTaken[memberID]++;
        BookStatus[bookID] = false;  // Mark book as unavailable
    }

    // Add a member to the library
    static void addMember(Member* m) {
        Members[m->getMemberID()] = m;
    }

    // Add a book to the library
    static void addBook(Book* b) {
        Books[b->getBookID()] = b;
    }
};

// Static initialization
Member* LibraryDb::Members[100] = { nullptr };   
int LibraryDb::BooksTaken[100] = { 0 };
Book* LibraryDb::Books[200] = { nullptr };
bool LibraryDb::BookStatus[200] = { false };

class Transaction {
private:
    int Tid;
    Member* mObj;
    Book* bObj;

public:
    // Constructor
    Transaction(Member* member, Book* book) : mObj(member), bObj(book) {}

    // Helper method to get current date in dd/mm/yyyy format
    string getCurrentDate() {
        time_t now = time(0);
        tm* now_tm = localtime(&now);
        string date = to_string(now_tm->tm_mday) + "/" + to_string(now_tm->tm_mon + 1) + "/" + to_string(now_tm->tm_year + 1900);
        return date;
    }

    // Helper method to calculate return date (14 days from borrow date)
    string calculateReturnDate() {
        time_t now = time(0);
        tm* return_tm = localtime(&now);
        return_tm->tm_mday += 14; // Add 14 days for the return date
        mktime(return_tm); // Normalize the date (e.g., handles month or year change)
        string returnDate = to_string(return_tm->tm_mday) + "/" + to_string(return_tm->tm_mon + 1) + "/" + to_string(return_tm->tm_year + 1900);
        return returnDate;
    }

    // Method to borrow a book
    void borrowBook() {
        // Check if the member and book are valid
        if (!mObj || !bObj) {
            cout << "Error: Invalid Member or Book!" << endl;
            return;
        }

        int memberID = mObj->getMemberID();
        int bookID = bObj->getBookID();

        // Validate member eligibility and book availability
        if (LibraryDb::validateMemberEligibility(memberID) == 0) {
            cout << "Error: Member is not eligible to borrow more books." << endl;
            return;
        }

        if (LibraryDb::validateBookAvailability(bookID) == 0) {
            cout << "Error: Book is currently unavailable." << endl;
            return;
        }

        // Proceed with borrowing
        string borrowDate = getCurrentDate();
        string returnDate = calculateReturnDate();

        // Output borrow and return dates
        cout << "Book borrowed successfully!" << endl;
        cout << "Borrow date: " << borrowDate << endl;
        cout << "Return date: " << returnDate << endl;

        // Update library database
        LibraryDb::issueBook(memberID, bookID);
    }
};

void displayMenu() {
    cout << "\nLibrary Menu:" << endl;
    cout << "Press 1 to add a member" << endl;
    cout << "Press 2 to add a book" << endl;
    cout << "Press 3 to borrow a book" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    // Initialize library
    LibraryDb::initializeLibrary();
    int choice;
    do{
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Member
                int id;
                string name, type;
                cout << "Enter Member ID: ";
                cin >> id;
                cout << "Enter Member Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Member Type: ";
                getline(cin, type);

                Member* newMember = new Member(id, name, type);
                LibraryDb::addMember(newMember);
                cout << "Member added successfully!" << endl;
                break;
            }

            case 2: {
                // Add Book
                int id, edition;
                string title, publisher, author, editor;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Publisher: ";
                getline(cin, publisher);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Edition: ";
                cin >> edition;

                Book* newBook = new Book(id, title, publisher, author, edition);
                LibraryDb::addBook(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }

            case 3: {
                // Borrow Book
                int memberID, bookID;
                cout << "Enter Member ID: ";
                cin >> memberID;
                cout << "Enter Book ID: ";
                cin >> bookID;

                Member* member = LibraryDb::Members[memberID];
                Book* book = LibraryDb::Books[bookID];

                if (member && book) {
                    Transaction transaction(member, book);
                    transaction.borrowBook();
                } else {
                    cout << "Invalid Member ID or Book ID!" << endl;
                }
                break;
            }

            case 0:
                cout << "Exiting the system. Thank You!!!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }while(choice!=0)

    return 0;
}