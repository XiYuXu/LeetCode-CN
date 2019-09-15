#include <stdio.h>
#include <string.h>

int isPalindrome(char *s){
    int length = strlen(s);
    int i=0,j=length-1;

    while(i<j){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')|| (s[i]>='0' && s[i]<='9')){
            if((s[j]>='a' && s[j]<='z')||(s[j]>='A' && s[j]<='Z')|| (s[j]>='0' && s[j]<='9')){
                if((s[i]==s[j]) || (s[i]==s[j]-32 && s[i]>='A') || (s[i]==s[j]+32 && s[j]>='A')){
                    i++;
                    j--;
                    continue;
                }
                else{
                    return 0;
                }
            }else{
                j--;
                continue;
            }
        }else{
            i++;
            continue;
        }
    }
    return 1;
}
int main(){
    char *s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s)){
        printf("it's a palindrome\n");
    }else{
        printf("it's not a palindrome\n");
    }
    return 0;
}
