#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for(int i=0;i<pricesSize-1;i++){
        for(int j=i+1;j<pricesSize;j++){
            if(prices[j]-prices[i]>max){
                max = prices[j]-prices[i];
            }
        }
    }
    return max;
}


int main(){
    int prices[6] = {7,6,4,3,1};
    int length = maxProfit(prices,6);
    printf("%d",length);
    return 0;
}
