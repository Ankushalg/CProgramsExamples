// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct stack {
    int data;
    stack *next;
};
int isEmpty(stack *s){
    if(s == NULL)
	return 1;
    return 0;
}
stack *push(stack *top, int x){
    stack *s = (stack *) malloc(sizeof(stack));
    s->data = x;
    s->next = top;
    top = s;
    return top;
}
int pop(stack *top){
    int x; stack *s;
    if(!isEmpty(top)){
	x = top->data;
	s = top;
	top = top->next;
	free(s);
	return x;
    } else {
	return NULL;
    }
}
void print(stack *top){
    stack *s;
    for(s = top; !isEmpty(s); s = s->next){
	    printf("%d", s->data);
    }
}
stack *getBinary(int x){
    stack *s;
    s = NULL;
    for(; x > 0; x/=2)
	    s = push(s, x%2);
    return s;
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