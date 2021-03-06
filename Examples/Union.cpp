// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#define max 10
#define MAX 20
void print(int a[MAX], int n){
  int i;
  printf("\n{");
  for(i = 0; i < (n - 1); i++){
    printf(" %d,",a[i]);
  }
  printf(" %d }\n", a[i]);
}
int scan(int a[max], int n){
  int i, j, k = 0, l;
  printf("\nEnter %d Elements : ", n);
  for(i = 0; i < n; i++){
    scanf("%d", &l);
    for(j = 0; j < k; j++){
      if(l == a[j]){
	break;
      }
    }
    if(j == k){
      a[k] = l;
      k++;
    }
  }
  return k;
}
int uni(int a[max], int b[max], int c[MAX], int m, int n){
  int i, j, k = 0;
  for(i = 0; i < m; i++, k++){
    c[k] = a[i];
  }
  for(j = 0; j < n; j++){
    for(i = 0; i < m; i++){
      if(a[i] == b[j])
	break;
    }
    if(i == m){
      c[k] = b[j];
      k++;
    }
  }
  return k;
}
void main() {
    int a[max], b[max], c[MAX];
    int n,m,p;
    clrscr();
    printf("Union of two Sets:-\n");
    X:printf("Enter Number of Elements of Set A: ");
    scanf("%d", &m);
    if(m > max) {
	printf("Sorry! We can not work with sets having elements more than %d. Please Retry...\n",max);
	goto X;
    }
    Y:printf("Enter Number of Elements of Set B: ");
    scanf("%d", &n);
    if(n > max) {
	printf("Sorry! We can not work with sets having elements more than %d. Please Retry...\n",max);
	goto Y;
    }
    scan(a, m);
    scan(b, n);
    p = uni(a, b, c, m, n);
    printf("\nSet A : ");
    print(a, m);
    printf("\nSet B : ");
    print(b, n);
    printf("\nUnion of Set A and Set B : ");
    print(c, p);
    getch();
}
