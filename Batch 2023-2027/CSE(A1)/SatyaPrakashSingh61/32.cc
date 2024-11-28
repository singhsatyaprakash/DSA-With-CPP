#include <iostream> 
#include <vector> 
#include <algorithm> // for max and min functions 
using namespace std; 
int main() { 
    vector<int> numbers(10); 
    cout << "Enter 10 integers:\n"; 
    for (int i = 0; i < 10; i++) { 
        cin >> numbers[i]; 
    } 
// Display elements 
    cout << "Elements in the vector: "; 
    for (int num : numbers) { 
        cout << num << " "; 
    } 
    // Find and display largest and smallest elements 
    int maxElem = *max_element(numbers.begin(), numbers.end()); 
    int minElem = *min_element(numbers.begin(), numbers.end()); 
    cout << "\nLargest element: " << maxElem; 
    cout << "\nSmallest element: " << minElem; 
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0; 
} 