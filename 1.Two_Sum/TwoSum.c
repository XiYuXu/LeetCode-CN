#include <stdio.h>
#include <stdlib.h>

//��ȡĿ������,���鳤��,�Լ�Ŀ���
int* twoSum(int* nums, int numsSize, int target){
    int *returnValue = (int *)malloc(2*sizeof(int));    //������malloc,��������Ŀռ亯�������󲻱��ͷ�
    int *p = NULL;
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){                  //ÿ�αȽϵ�j����i��һ����ֱ������ĩβ
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


