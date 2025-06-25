int findPeakElement(int* nums, int numsSize) {
    static int i=0;
    if(i==0 && nums[i]>nums[i+1]){
        return i;
    }
    else if(true) {
        for(i=1;i<numsSize-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
    }
    else if(i==numsSize-1 && nums[i]>nums[i-1]){
        return i;
    }
    return 0;
}


// int findPeakElement(int* nums, int numsSize) {
//     static int i=0;
//     while(i<numsSize){
//         if(i==0 && nums[i]>nums[i+1]){
//             return i;
//         }
//         else if(i>0 && nums[i]>nums[i-1] && nums[i]>nums[i+1]){
//                 return i;
//             }
//         else if(i<numsSize && i==numsSize-1 && nums[i]>nums[i-1]){
//             return i;
//         }
//     }
//     return -1;
// }
