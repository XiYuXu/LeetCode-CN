#include <stdio.h>
#include <stdlib.h>

//获取目标数组,数组长度,以及目标和
int* twoSum(int* nums, int numsSize, int target){
    int *returnValue = (int *)malloc(2*sizeof(int));    //必须用malloc,堆中申请的空间函数结束后不被释放
    int *p = NULL;
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){                  //每次比较的j都是i后一个数直到数组末尾
            if(nums[i]+nums[j]==target){
                returnValue[0]=i;
                returnValue[1]=j;
                break;
            }
        }
    }
    return returnValue;
}
int main(){
    int nums[3] = {1,2,3};
    int numsSize = 0;
    int target = 4;
    int *returnValue = NULL;
    numsSize = sizeof(nums)/sizeof(int);
    returnValue = twoSum(&nums,numsSize,target);
    printf("%d,%d",returnValue[0],returnValue[1]);
    return 0;
}


