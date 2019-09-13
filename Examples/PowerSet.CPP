// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 8
#define MAX 65
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
void getBinaryInSet(int a[max], int n, int j){
    // gets the binary code of a number n of j length in an a array
    for(; n > 0 && j >= 0; j--,n /= 2)
        a[j] = n%2;
}
int getPowerSet(int a[max],int b[MAX][max], int n){
    int temp[max], total, i, j, k;
    total = pow(2,n);
    for(i = 0; i < total; i++){
        // getting binary code.
        getBinaryInSet(temp, i, n - 1);
        // putting value of sub sets according to binary code.
        // 1 - element is present
        // 0 - element is not present
        for(j = 0, k = 0; j < n; j++){
            if(temp[j] == 1){
                b[i][k] = a[j];
                k++;
            }
        }
        if(k < n) {
            b[i][k] = NULL;
        }
    }
    return i;
}
void printPowerSet(int b[MAX][max], int p, int n){
    int i,j;
    printf("\n{ ");
    for(i = 0; i < p; i++){
        printf("{ ");
        for(j = 0; b[i][j] != NULL && j < n;j++){
            printf(" %d", b[i][j]);
        }
        printf(" } ");
    }
    printf("}\n");
}
void main() {
    int a[max],b[MAX][max];
    int n,p;
    clrscr();
    printf("Power Set of a Set A:-\n");
    X:printf("Enter Number of Elements of Set A: ");
    scanf("%d", &n);
    if(n > max) {
        printf("Sorry! We can not work with sets having elements more than %d. Please Retry...\n",max);
        goto X;
    }
    scan(a, n);
    printf("\nSet A : ");
    print(a, n);
    p = getPowerSet(a,b,n);
    printf("\nPower Set of A: \n");
    printPowerSet(b, p, n);
    getch();
}
