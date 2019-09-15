#include <stdio.h>
#include <limits.h>


int maxSubArray(int* nums, int numsSize){
    int value = INT_MIN;
    int temp = 0;
    for(int i=0;i<numsSize;i++){
        temp+=nums[i];
        value = (temp>value)?temp:value;
        if(temp < 0){
            temp = 0;
        }
    }
    return value;
}


int main(){
    int array[5] = {-1};
    int value = maxSubArray(array,1);
    printf("%d",value);
    return 0;
}
