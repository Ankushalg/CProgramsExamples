// @author Ankush Kumar (ankushalg@gmal.com)
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
void carPro(term c[max][max], int a[max], int b[max], int m, int n){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            c[i][j].x = a[i];
            c[i][j].y = b[j];
        }
    }
}
void printCar(term c[max][max], int m, int n) {
  int i, j;
  for(i = 0; i < m; i++){
    printf("\n");
    for(j = 0; j < n; j++){
      printf(" ( %d, %d)", c[i][j].x, c[i][j].y);
    }
    }
}

void main() {
    int a[max], b[max];
    term c[max][max];
    int m, n, i, j;
    clrscr();
    printf("Cartesian Product of two Sets :-\n");
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
    printf("\nSet A : ");
    print(a, m);
    printf("\nSet B : ");
    print(b, n);
    carPro(c,a,b, m, n);
    printf("\n Cartetian Product is: \n");
    printCar(c,m,n);
    getch();
}