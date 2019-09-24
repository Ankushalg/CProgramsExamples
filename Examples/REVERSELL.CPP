// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
typedef struct stack {
    char data;
    stack *next;
};
int isEmpty(stack *s){
    if(s == NULL)
	return 1;
    return 0;
}
stack *push(stack *top, char x){
    stack *s = (stack *) malloc(sizeof(stack));
    s->data = x;
    s->next = top;
    top = s;
    return top;
}
char pop(stack *top){
    char x; stack *s;
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
	    printf("%c", s->data);
    }
}
stack *getRev(char a[20]){
    stack *s;
    int i;
    s = NULL;
    for(i = 0; a[i] != '\0'; i++){
	s = push(s, a[i]);
    }
    return s;
}
void main(){
    stack *s;
    char x[20];
    clrscr();
    printf("Reverse String:\nEnter a string: ");
    gets(x);
    s = getRev(x);
    printf("String is :\n %s\nReverse Form is:\n ", x);
    print(s);
    getch();
}