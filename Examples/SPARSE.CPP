// @author Ankush Kumar (ankushalg@gmal.com)
#include<stdio.h>
#include<conio.h>
#define max 65
#define min 3
typedef struct mn{
   int m;
   int n;
};
void matrixToSparse(int a[8][8], int b[max][min], int m, int n){
    int i, j, k = 0;
    b[0][0] = m;
    b[0][1] = n;
    for(i = 0; i < m; i++){
	for(j = 0; j < n; j++){
	    if(a[i][j] != 0){
		k++;
		b[k][0] = i;
		b[k][1] = j;
		b[k][2] = a[i][j];
	    }
	}
    }
    b[0][2] = k;
}
mn sparseToMatrix(int a[8][8], int b[max][min]){
   int i, j, k;
   mn x;
   x.m = b[0][0];
   x.n = b[0][1];
   for (i = 0; i < x.m; i++){
       for(j = 0; j < x.n; j++){
	   for(k = 1; k <= b[0][2]; k++){
	       if(i == b[k][0] && j == b[k][1]){
		   break;
	       }
	   }
	   if(k <= b[0][2]){
	       a[i][j] = b[k][2];
	   } else {
	       a[i][j] = 0;
	   }
       }
   }
   return x;
}
void printS(int a[max][min]){
   int i, j;
   for(i = 0; i <= a[0][2]; i++){
       printf("\n");
       for(j = 0; j < 3; j++){
	   printf("\t%d", a[i][j]);
       }
   }
}
void printM(int a[8][8], int m, int n){
    int i, j;
    for(i = 0; i < m; i++){
	printf("\n");
	for(j = 0; j < n; j++){
	    printf("\t%d",a[i][j]);
        }
    }
}
void scanM(int a[8][8], int m, int n){
    int i, j;
    for(i = 0; i < m; i++){
	for(j = 0; j < n; j++){
	    scanf("%d", &a[i][j]);
	}
    }
}
void insert(int a[max][min], int m, int n, int x){
    int i;
    if(m < a[0][0] && n < a[0][1]){
      for(i = 1; i <= a[0][2]; i++){
	if(a[i][0] == m && a[i][1] == n){
	   break;
	}
      }
      if(i > a[0][2]){
	a[i][0] = m;
	a[i][1] = n;
	a[i][2] = x;
	a[0][2] = i;
	//printf("\n%d, %d: <%d %d %d>",i, a[0][2], a[i][0], a[i][1], a[i][2]);
      } else {
	a[i][2] += x;
      }
    }
}
void scanS(int a[max][min], int m, int n) {
    int i, j, k, x, y, v, p;
    printf("\nEnter total number of non zero elements of Sparse Matrix: ");
    a[0][0] = m;
    a[0][1] = n;
    a[0][2] = 0;
    scanf("%d", &p);
    printf("Enter %d triples (row, column, value) : ", p);
    for(i = 1; i <= p; i++){
	scanf("%d%d%d", &x,&y,&v);
	insert(a,x,y,v);
    }
}
void transpose(int b[max][min]){
    int i, j;
    for(i = 1; i <= b[0][2]; i++){
	j = b[i][0];
	b[i][0] = b[i][1];
	b[i][1] = j;
    }
}
int add(int a[max][min], int b[max][min],int c[max][min]){
    int i, j, k = 0;
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1]){
	printf("\nAddition Not Possible...");
	return 0;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    for(i = 1; i <= a[0][2]; i++){
	k++;
	c[k][0] = a[i][0];
	c[k][1] = a[i][1];
	c[k][2] = a[i][2];
    }
    for(i = 1; i <= b[0][2]; i++){
	for(j = 1; j <= a[0][2]; j++){
	    if(a[j][0] == b[i][0] && a[j][1] == b[i][1]){
		break;
	    }
	}
	if(j > a[0][2]){
	    k++;
	    c[k][0] = b[i][0];
	    c[k][1] = b[i][1];
	    c[k][2] = b[i][2];
	} else {
	    c[j][2] += b[i][2];
	}
    }
    c[0][2] = k;
    return 1;
}
void main() {
    int a[8][8], b[max][min],c[max][min],d[max][min], m, n, p, q;
    clrscr();
    X:printf("Sparse Matrix:\nChoose any Operation:\n1 - Matrix to Sparse Matrix\n2 - Sparse Matrix to Matrix\n3 - Transpose Sparse Matrix\n4 - Add Sparse Matrix\n5 - Insert triple in Sparse Matrix\n0 - Exit : ");
    scanf("%d", &p);
    switch (p) {
    case 0:
	printf("Press any key to exit.");
	break;
    case 2:
	printf("Enter a Matrix m, n value: ");
	scanf("%d%d", &m,&n);
	scanS(b,m,n);
	printf("\nSparse Matrix is : \n");
	printS(b);
	sparseToMatrix(a,b);
	printf("\nMatrix form is : \n");
	printM(a,m,n);
	break;
    case 1:
	printf("Enter a Matrix m, n value: ");
	scanf("%d%d", &m,&n);
	printf("Enter %d Matrix elemets: ", m*n);
	scanM(a,m,n);
	printf("\nMatrix is : \n");
	printM(a,m,n);
	matrixToSparse(a,b,m,n);
	printf("\nSparse Matrix form is : \n");
	printS(b);
	break;
    case 3:
	printf("Enter a Matrix m, n value: ");
	scanf("%d%d", &m,&n);
	scanS(b,m,n);
	printf("\nSparse Matrix is : \n");
	printS(b);
	transpose(b);
	printf("\nTranspose of Sparse Matrix is : \n");
	printS(b);
	break;
    case 4:
	printf("Enter Matrix m, n value: ");
	scanf("%d%d", &m,&n);
	printf("\nSparse Matrix A :\n");
	scanS(b,m,n);
	printf("\nSparse Matrix B :\n");
	scanS(c,m,n);
	add(b,c,d);
	printf("\nSparse Matrix A is : \n");
	printS(b);
	printf("\nSparse Matrix B is : \n");
	printS(c);
	printf("\nSparse Matrix A + B is : \n");
	printS(d);
	break;
    case 5:
	printf("Enter a Matrix m, n value: ");
	scanf("%d%d", &m,&n);
	scanS(b,m,n);
	printf("\nSparse Matrix is : \n");
	printS(b);
	printf("\nEnter a triple (row, colounm, value) to insert: ");
	scanf("%d%d%d",&m,&n,&p);
	insert(b, m, n, p);
	printf("\nUpdated Sparse Matrix is : \n");
	printS(b);
	break;
    default:
	printf("Wrong Input... Please Retry...\n");
	goto X;
	break;
    }
    getch();
}