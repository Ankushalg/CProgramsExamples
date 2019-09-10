#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node {
    int data;
    node *next;
};
node *create(int n) {
    node *head, *p, *q;
    int i, x;
    head = (node *) malloc(sizeof(node));
    scanf("%d", &x);
    head->data = x;
    head->next = NULL;
    p = head;
    for(i = 1; i < n; i++){
        q = (node *) malloc(sizeof(node));
        scanf("%d", &x);
        q->data = x;
        q->next NULL;
        p->next = q;
        p = q;
    }
}
void print(node *head){
    node *p;
    for(p = head; p != NULL; p = p->next){
        printf(" <%d>", p->data);
    }
}
int count(node *head){
    int n = 0;
    node *p;
    for(p = head; p != NULL; p = p->next, n++)
        ;
    return n;
}
node *transLoc(node *head, int loc){
    int n = 1;
    node *p;
    for(p = head; p != NULL && n < loc; p = p->next, n++)
        ;
    return p;
}
node *transNode(node *head, int x){
    node *p;
    for(p = head; p != NULL && p->data != x; p = p->next)
        ;
    return p;
}
int find(node *head, int x){
    int n = 0;
    node *p;
    for(p = head; p != NULL && p->data != x; p = p->next, n++)
        ;
    return n;
}
node *transLast(node *head){
    node *p;
    for(p = head; p->next != NULL; p = p->next)
        ;
    return p;
}
node *insert(node *head, int loc, int x){
    node *p, *q;
    if(head == NULL && loc == 1){
            q = (node *) malloc(sizeof(node));
            q->data = x;
            q->next = NULL;
            return q;
        }
    }
    if(loc == 1){
        q = (node *) malloc(sizeof(node));
        q->data = x;
        q->next = head;
        return q;
    }
    p = transLoc(loc - 1);
    q = (node *) malloc(sizeof(node));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return head;
}
node *delete(node *head, int loc, int x){
    
}