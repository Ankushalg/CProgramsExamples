// @author Ankush Kumar (ankushalg@gmail.com)
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
    printf("\nEnter Elements: ");
    head = (node *) malloc(sizeof(node));
    scanf("%d", &x);
    head->data = x;
    head->next = NULL;
    p = head;
    for(i = 1; i < n; i++){
	q = (node *) malloc(sizeof(node));
	scanf("%d", &x);
	q->data = x;
	q->next = NULL;
	p->next = q;
	p = q;
    }
    return head;
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
    int n = 1;
    node *p;
    for(p = head; p != NULL && p->data != x; p = p->next, n++)
	;
	if(p->data == x){
	    return n;
	} else {
	    return -1;
	}
}
node *insert(node *head, int loc, int x){
    node *p, *q;
    if(head == NULL && loc == 1){
	    q = (node *) malloc(sizeof(node));
	    q->data = x;
	    q->next = NULL;
	    return q;
    }
    if(loc == 1){
	q = (node *) malloc(sizeof(node));
	q->data = x;
	q->next = head;
	return q;
    }
    p = transLoc(head, loc - 1);
    q = (node *) malloc(sizeof(node));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return head;
}
node *deleteLoc(node *head, int loc){
    node *p, *q;
    if(head != NULL){
	if(loc == 1){
	    q = head;
	    head = head->next;
	    free(q);
	    return head;
	}
	p = transLoc(head, loc - 1);
	q = p->next;
	p->next = q->next;
	free(q);
	return head;
    } else {
	return head;
    }
}

node *deleteValue(node *head, int x){
    int i;
    node *p, *q;
    if(head != NULL){
	i = find(head, x);
	if(i == -1){
	    printf("\nElement Not Found in Linked List...\n");
	    return head;
	} else {
	    return deleteLoc(head, i + 1);
	}
    } else {
	printf("\nLinked List is Empty...\n");
	return head;
    }
}

node *deleteLast(node *head){
    int last = count(head);
    if(last == 0){
	printf("\nLinked List is empty.\n");
	return head;
    } else {
	return deleteLoc(head, last);
    }
}

int findMid(node *head){
    node *p, *q;
    int i;
    for(i = 0, p = q = head; q != NULL; p = p->next, i++){
	q = q->next;
	if(q->next != NULL){
	    q = q->next;
	}
    }
    return i;
}

node *concat(node *head1, node *head2){
    node *p = transLoc(head1, count(head1));
    p->next = head2;
    return head1;
}
node *deleteW(node *head){
   node *p, *q;
   for(p = head; p != NULL;){
     q = p;
     p = p->next;
     free(q);
   }
   return p;
}

void main(){
    node *head, *head1, *head2;
    int n, a;
    X:clrscr();
    printf("Linked Lists\n1 - Insertion in front\n2 - Insertion at Last\n3 - Insertion at any location\n4 - Insertion after a node\n5 - Delete First\n6 - Delete Last\n7 - Delete specific Location\n8 - Delete Particular Value\n9 - Delete Whole List\n10 - Search an Element\n11 - Split Linked List\n12 - Concatinate");
    scanf("%d", &n);
    switch (n) {
    case 1:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter element to enter in Linked List: ");
	scanf("%d", &a);
	head = insert(head, 1, a);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 2:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter element to enter in Linked List: ");
	scanf("%d", &a);
	head = insert(head, count(head) + 1, a);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 3:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter element to enter in Linked List: ");
	scanf("%d", &a);
	printf("Enter its Position: ");
	scanf("%d", &n);
	head = insert(head, n, a);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 4:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter element to enter in Linked List: ");
	scanf("%d", &a);
	printf("Enter element after which you want to insert it: ");
	scanf("%d", &n);
	n = find(head, n);
	if(n == -1){
	    printf("Element Not Found...");
	    break;
	}
	head = insert(head, n + 1, a);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 5:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	head = deleteLoc(head, 1);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 6:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	head = deleteLoc(head, count(head));
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 7:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter location from which you want to delete element: ");
	scanf("%d", &a);
	head = deleteLoc(head, a);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 8:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	printf("\nEnter element value which you want to delete: ");
	scanf("%d", &a);
	n = find(head, a);
	if(n == -1){
	    printf("Element Not Found...");
	    break;
	}
	head = deleteLoc(head, n);
	printf("\nUpdated Linked List is: \n");
	print(head);
	break;
    case 9:
	printf("Enter total number of elemets of Linked List: ");
	scanf("%d", &a);
	head = create(a);
	printf("Linked List is: \n");
	print(head);
	a = count(head);
	head = deleteW(head);
        printf("\nUpdated Linked List is: \n");
        print(head);
        break;
    case 10:
        printf("Enter total number of elemets of Linked List: ");
        scanf("%d", &a);
        head = create(a);
        printf("Linked List is: \n");
        print(head);        
        printf("\nEnter element value which you want to search: ");
        scanf("%d", &a);
        n = find(head, a);
        if(n == -1){
            printf("Element Not Found...");
        } else {
            printf("\nElement Fount at : %d\n", n);
        }
        break;
    case 11:  
        printf("Enter total number of elemets of Linked List: ");
        scanf("%d", &a);
        head = create(a);
        printf("Linked List is: \n");
        print(head);       
        a = findMid(head);
        if(a == 0){
            printf("\nLinked List is too small...");
            break;
        }
	head1 = transLoc(head, a - 1);
        head2 = head1->next;
        head1->next = NULL;
        printf("\nLinked list 1:\n");
        print(head);
        printf("\nLinked list 2:\n");
        print(head2);
        break;
    case 12:
	printf("Enter total number of elemets of Linked List 1: ");
	scanf("%d", &a);
	head1 = create(a);
	printf("Linked List 1 is: \n");
	print(head1);
	printf("\nEnter total number of elemets of Linked List 2: ");
	scanf("%d", &a);
	head2 = create(a);
	printf("Linked List 2 is: \n");
	print(head2);
	head = concat(head1, head2);
	printf("\nConcated Linked List is: \n");
        print(head);
        break;
    default:
        printf("Wrong Input... Press 1 to Retry or anyother key to exit...");
        scanf("%d", &n);
        if(n == 1){
            goto X;
        }
        break;
    }
    getch();
}
