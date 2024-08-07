#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cout<<"How many elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    // Finding range...
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    // Counting sort...
    int freq[1000000] = {0};
    // 1st step
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }
    // 2nd step
    int j = 0;
    for(int i=minVal; i<=maxVal; i++) {
        while(freq[i]>0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    cout<<"Sorted array:"<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}

// #include<iostream>
// #include<climits>
// using namespace std;

// int main(){
//     int n;
//     cout<<"How many elements:";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of array:";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//    ///Finding range...
//     int minVal=INT_MAX,maxVal=INT_MIN;
//     for(int i=0;i<n;i++){
//         minVal=min(minVal,arr[i]);
//         maxVal=max(maxVal,arr[i]);
//     }

//     int range=maxVal-minVal+1;  // Adjusting range to include all values
//     //Counting sort...
//     int freq[range]={0};
//     //1st step
//     for(int i=0;i<n;i++){
//         freq[arr[i]-minVal]++;  // Shifting by minVal to make it 0-based index
//     }
//     //2nd step
//     for(int i=minVal,j=0;i<=maxVal;i++){  // Corrected loop condition
//         while(freq[i-minVal]>0){  // Shifting by minVal to access correct index
//             arr[j++]=i;
//             freq[i-minVal]--;
//         }
//     }


//     cout<<"Sorted array:"<<endl;
//        for(int i=0;i<n;i++){ 
//         cout<<arr[i]<<" ";
//     }

// }
