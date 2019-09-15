#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int length=1;
    int temp = nums[0];
    if(numsSize==0){
        return 0;
    }
    for(int i=1;i<numsSize;i++){
        //指向第一个不同于temp的值,或者一直相等直到循环结束
       while(temp==nums[i]){
            if(i<numsSize)
                i++;
       }
       if(i==numsSize)
            return length;
       else{
            temp = nums[i];
            length++;
            nums[length-1] = temp;
       }
    }
    return length;
}

int main(){
    int nums[3] = {1,1,2};
    int length = removeDuplicates(&nums,3);
    printf("%d\n",length);
    for(int i=0;i<length;i++)
        printf("%d",nums[i]);
    return 0;
}



