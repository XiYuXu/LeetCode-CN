#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = nums1Size-1;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[index] = nums1[i];
                i--;
            }
            else
            {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
    }
}

int main(){
    int nums1[6] = {1,3,5,0,0,0};
    int nums2[6] = {2,4,6,0,0,0};
    merge(nums1,6,3,nums2,6,3);
    for(int i=0;i<6;i++){
        printf("%d\n",nums1[i]);
    }
    return 0;
}
