#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TNode;

int getLength(TNode *p){
    int length = 0;
    if(p!=NULL)
    {
        length = length+getLength(p->left)+getLength(p->right)+1;
        return length;
    }
    return 0;
}
int maxDepth(struct TreeNode* root){
    int length = 0;
    length = getLength(root);
    printf("%d",length);
    double temp_depth = log(length+1)/log(2);
    int depth = temp_depth;

    if(depth<temp_depth){
        return depth+1;
    }
    return depth;
}

int main(){
    TNode *root = NULL;
    int Length = 0;
    int nums[]={1,2,NULL,3,NULL,4,NULL,5};
    int length = sizeof(nums)/sizeof(nums[0]);
    root = (TNode *)malloc(sizeof(TNode)*length);
    if(root == NULL){
        printf("room error");
    }
    TNode *temp = root;
    for(int i=0;i<length;i++){
        temp[i].val = nums[i];
        temp[i].left = NULL;
        temp[i].right = NULL;
    }
    for(int i=0;i<=length/2-1;i++){
        if(2*i+1<length){
            temp[i].left = &temp[2*i+1];
        }
        if(2*i+2<length){
            temp[i].right = &temp[2*i+2];
        }
    }
    printf("%d",maxDepth(root));
    return 0;
}
