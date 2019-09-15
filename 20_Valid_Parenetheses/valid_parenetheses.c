#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_LENGTH 100
typedef struct stack{
    char *base;
    char *top;
}stack;

void pushStack(char ch,stack *str_stack){
    if(str_stack->top - str_stack->base == 100){
        printf("stack is full");
    }else{
        *str_stack->top = ch;
        str_stack->top++;
    }
}

void clearStack(stack *str_stack){
    if(str_stack->top-str_stack->base == 0){
        printf("the stack is empty\n");
    }else{
        str_stack->top--;
    }
}

int match(char p,char q){
    if((p=='{' && q=='}') ||
       (p=='[' && q==']') ||
       (p=='(' && q==')')){
            return 1;
       }else{
           return 0;
       }
}
int isValid(char * s){
    char *p = s;
    stack str_stack;
    str_stack.base =  (char *)malloc(sizeof(char)*STACK_MAX_LENGTH);
    str_stack.top = str_stack.base;
    while(*p!='\0'){
        if(str_stack.top-str_stack.base == 0){
            pushStack(*p,&str_stack);
            p++;
            continue;
        }
        printf("\nch:%c,stack:%c\n\n",*p,*(str_stack.top-1));
        if(!match(*(str_stack.top-1),*p)){
            pushStack(*p,&str_stack);
        }else{
            clearStack(&str_stack);
        }
        p++;
    }
    if(str_stack.top-str_stack.base == 0)
        return 1;
    else
        return 0;
}
int main(){
    char *s = "({[{[]}]})";
    if(isValid(s)){
        printf("it's valid");
    }else{
        printf("it's false");
    }
    return 0;
}
