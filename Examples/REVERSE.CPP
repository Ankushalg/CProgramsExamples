// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 20
typedef struct stack {
    char a[max];
    int top;
};
void init(stack *s){
    s->top = -1;
}
int isEmpty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
int isFull(stack *s){
    if(s->top == max - 1)
        return 1;
    return 0;
}
void push(stack *s, char x){
    if(!isFull(s)){
        s->top++;
        s->a[s->top] = x;
    } else {
        printf("Error: Stack Overflow...");
    }
}
char pop(stack *s){
    char x;
    if(!isEmpty(s)){
        x = s->a[s->top];
        s->top--;
        return x;
    } else {
        return NULL;
    }
}
void print(stack *s){
    for(; !isEmpty(s); s->top--){
	    printf("%c", s->a[s->top]);
    }
}
stack *getRev(char a[max]){
    stack *s;
    int i;
    for(i = 0; a[i] != '\0'; i++){
        push(s, a[i]);
    }
    return s;
}
void main(){
    stack *s;
    char x[max];
    clrscr();
    printf("Reverse String:\nEnter a string: ");
    gets(x);
    s = getRev(x);
    printf("String is :\n %s\nReverse Form is:\n ", x);
    print(s);
    getch();
}