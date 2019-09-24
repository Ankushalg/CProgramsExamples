// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#define max 20
typedef struct stack {
    int a[max];
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
void push(stack *s, int x){
    if(!isFull(s)){
        s->top++;
        s->a[s->top] = x;
    } else {
        printf("Error: Stack Overflow...");
    }
}
int pop(stack *s){
    int x;
    if(!isEmpty(s)){
        x = s->a[s->top];
        s->top--;
        return x;
    } else {
        return NULL;
    }
}
stack *getBinary(int x){
    stack *s;
    init(s);
    for(; x > 0; x/=2)
	push(s, x%2);
    return s;
}
void print(stack *s){
    for(; !isEmpty(s); s->top--){
	printf(" %d", s->a[s->top]);
    }
}
void main(){
    stack *s;
    int x;
    clrscr();
    printf("Decimal to Binary Convertion:\nEnter a positive number: ");
    scanf("%d", &x);
    s = getBinary(x);
    printf("Number is : %d\nBinary Form is:\n", x);
    print(s);
    getch();
}