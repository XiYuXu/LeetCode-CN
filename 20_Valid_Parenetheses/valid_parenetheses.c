#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid1(char * s){
    int Length = 100;
    int top=0;
    char *stack = malloc(Length);
    while(*s!='\0'){
        switch(*s){
            case '{':
            case '[':
            case '(':
                if(top+1>=Length){
                    Length*=2;
                    stack = realloc(stack,Length);
                }
                stack[top++]=*s;break;
            case '}':
                if(stack[--top]!='{'){
                    return false;
                }break;
            case ']':
                if(stack[--top]!='['){
                    return false;
                };break;
            case ')':
                if(stack[--top]!='('){
                    return false;
                };break;
            default:
                return false;
        }
        s++;
    }
    if(top==0){
        return true;
    }else{
        return false;
    }
}


int main()
{
    printf("%s\n", isValid1("{}") ? "true" : "false");
    return 0;
}
