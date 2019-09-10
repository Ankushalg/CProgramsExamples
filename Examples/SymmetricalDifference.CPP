// @author Ankush Kumar (ankushalg@gmal.com)
#include<stdio.h>
#include<conio.h>
#define max 20
#define MAX 20
void print(int a[max], int n){
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
int inter(int a[max], int b[max], int c[max], int n, int m){
  int i, j, k = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      if(a[i] == b[j])
	break;
    }
    if(j < m){
      c[k] = a[i];
      k++;
    }
  }
  return k;
}
int diff(int a[max], int b[max], int c[max], int n, int m){
  int i, j, k = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < m; j++){
      if(a[i] == b[j])
	break;
    }
    if(j == m){
      c[k] = a[i];
      k++;
    }
  }
  return k;
}
int symDiff(int a[max], int b[max], int c[max], int n, int m){
  int uSet[max], iSet[max], u, i;
  u = uni(a,b,uSet,n,m);
  i = inter(a,b,iSet,n,m);
  return diff(uSet,iSet,c,u,i);
}
void main() {
    int a[max], b[max], c[max];
    int n,m,p;
    clrscr();
    printf("Symmetric Diffrence of two Sets :-\n");
    X:printf("Enter Number of Elements of Set A: ");
    scanf("%d", &n);
    if(n > max) {
        printf("Sorry! We can not work with sets having elements more than %d. Please Retry...\n",max);
        goto X;
    }
    Y:printf("Enter Number of Elements of Set B: ");
    scanf("%d", &m);
    if(m > max) {
        printf("Sorry! We can not work with sets having elements more than %d. Please Retry...\n",max);
        goto Y;
    }
    scan(a, n);
    scan(b, m);
    p = symDiff(a, b, c, n, m);
    printf("\nSet A : ");
    print(a, n);
    printf("\nSet B : ");
    print(b, m);
    printf("\nSymmetric Difference of Set A and Set B : ");
    print(c, p);
    getch();
}