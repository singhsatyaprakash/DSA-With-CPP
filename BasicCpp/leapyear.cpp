#include<iostream>
using namespace std;
int main() {
int year;
cout<<"Enter Year:";
cin>>year;
if (year % 400 == 0) {
    cout << year << " is a leap year.\n";
} 
else if (year % 100 == 0) {
    cout << year << " is NOT a leap year.\n";
} 
else if (year % 4 == 0) {
    cout << year << " is a leap year.\n";
} 
else {
    cout << year << " is NOT a leap year.\n";
}
return 0;
}