
void shiftZero(vector<int>&arr){
    int n=arr.size();
    int i,j=-1;
    for(i=0;i<n;i++){
        if(arr[i]==0){
            j=i+1;
            break;
        }

        if(j==-1){
            return;
        }

        for(j;j<n;j++){
            if(arr[j]!=0){
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
}