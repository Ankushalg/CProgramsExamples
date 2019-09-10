#include<stdio.h>
#include<conio.h>
#define max 20
typedef struct term {
    int x;
    int y;
};
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
void carPro(term c[max][max]){
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            c[i][j].x = a[i];
            c[i][j].y = b[j];
        }
    }
}
void main() {
    int a[max], b[max];
    term c[max][max];
    int n, m, i, j;
    clrscr();
    printf("Cartesian Product of two Sets :-\n");
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
    printf("\nSet A : ");
    print(a, n);
    printf("\nSet B : ");
    print(b, m);
    getch();
}