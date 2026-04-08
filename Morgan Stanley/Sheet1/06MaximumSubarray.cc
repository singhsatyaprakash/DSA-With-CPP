#include<bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>& arr, int l, int mid, int r) {
    int leftSum = INT_MIN, sum = 0;

    // go left from mid
    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    // go right from mid+1
    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(vector<int>& arr, int l, int r) {
    if (l == r) return arr[l];

    int mid = (l + r) / 2;

    int leftAns = maxSubarray(arr, l, mid);
    int rightAns = maxSubarray(arr, mid + 1, r);
    int crossAns = maxCrossingSum(arr, l, mid, r);

    return max({leftAns, rightAns, crossAns});
}

int main() {
    int n;
    cout << "Enter n:";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << maxSubarray(arr, 0, n - 1) << "\n";

    return 0;
}// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter n:";
//     cin>>n;
//     vector<int>arr(n);
//     cout<<"Enter array:"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     //approach 1...Brute force O(N^2)...
//     int maxsum=INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             maxsum=max(maxsum,sum);
//         }
//     }
//     cout<<maxsum<<"\n";
    
//     //approach 2...Kadane Algo
//     maxsum=0;
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         maxsum=max(maxsum,sum);
//         if(sum<0){
//             sum=0;
//         }
//     }
//     cout<<maxsum<<"\n";


//     return 0;

// }
