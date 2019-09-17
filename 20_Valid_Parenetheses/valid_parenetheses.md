## 题目地址
https://leetcode-cn.com/problems/valid-parentheses/

## 题目描述

```
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
```

## 初级思路

> 很自然想到遍历所有字符,用栈结构记录情况,若是遇到左括号,当前字符压栈.
> 遇到右括号,查看当前栈顶的是否是对应的左括号,若匹配,弹栈,比较下一个字符,若不匹配,则该不是有效字符串.
> 遍历结束后,查看栈空间,若为空,则说明字符串有效,若不为空,则字符串无效.

## 技巧
```
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
```

> 前三个case无论哪个触发,都会执行入栈操作,因此不用单独break
> 后面三个用了前--操作符,指针先退位指向弹出的元素,若是匹配,则已经进行了弹栈操作,若不匹配,直接返回false

## 注意

1. 栈溢出错误,可以用realloc函数申请更大的空间

## 代码

C Code:
```
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


```

