// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
#include<math.h>
typedef struct term {
  float coeffi;
  int power;
};
typedef struct polynomial{
  term a[10];
  int n;
};
void init(polynomial *p){
  p->n = 0;
}
void insert(polynomial *p, term t){
  int i;
  // To check if any element with same power already present.
  for(i = 0; i < p->n; i++){
    if((p->a[i]).power == t.power)
      break;
  }
  // Inserting element accordingly
  if(i == p->n){
    for(; i > 0 && (p->a[i - 1]).power > t.power; i--){
	p->a[i] = p->a[i - 1];
    }
    p->a[i] = t;
    p->n += 1;
  } else {
    (p->a[i]).coeffi += t.coeffi;
  }
}
void print(polynomial *p){
  int i;
  for(i = 0; i < ((p->n) - 1); i++){
    printf(" (%.2f)x^%d +", (p->a[i]).coeffi, (p->a[i]).power);
  }
  printf(" (%.2f)x^%d ", (p->a[i]).coeffi, (p->a[i]).power);
}
void read(polynomial *p){
  term t;
  float coeffi;
  int power, n = 11, i;
  while(n > 10){
    printf("\nEnter no. of terms of the polynomial: ");
    scanf("%d", &n);
    if(n > 10){
      printf("Only a polynomial with 10 terms is allowed.");
    }
  }
  printf("Enter Terms: \n");
  for(i = 0; i < n; i++){
    printf("Enter Coefficient of %d term: ", i + 1);
    scanf("%f", &coeffi);
    printf("Enter Power of %d term: ", i + 1);
    scanf("%d", &power);
    t.power = power;
    t.coeffi = coeffi;
    insert(p, t);
  }
}
void add(polynomial p1, polynomial p2,polynomial *p3){
  int i;
  for(i = 0; i < p1.n; i++){
    insert(p3, p1.a[i]);
  }
  for(i = 0; i< p2.n; i++){
    insert(p3, p2.a[i]);
  }
}
void mul(polynomial p1, polynomial p2, polynomial *p3){
  int i, j;
  term t;
  for(i = 0; i < p1.n; i++){
    for(j = 0; j < p2.n; j++){
      t.power = p1.a[i].power + p2.a[j].power;
      t.coeffi = p1.a[i].coeffi * p2.a[j].coeffi;
      insert(p3, t);
    }
  }
}
float evaluate(polynomial p, float x){
  int i,j, power;
  float coeffi;
  float r = 0;
  for(i = 0; i < p.n; i++){
    coeffi = (p.a[i]).coeffi;
    power = pow(x, (p.a[i]).power);
    printf("\nc: %f, p: %d", coeffi, power);
    r += (coeffi * power);
  }
  return r;
}
void main(){
  polynomial p1, p2, p3;
  int n;
  float in, out;
  clrscr();
  init(&p1);
  init(&p2);
  init(&p3);
  X:printf("Select Operation of Polynomial:\n Enter 1 for Addition\n 2 for Multiplication\n 3 for Evaluation\n 0 for exit: ");
  scanf("%d",&n);
  switch(n){
    case 0:
      printf("Press Any Key To exit: ");
      break;
    case 1:
      printf("Addition Of Polynomials :- \n");
      printf("Enter 1st Polynomial :- \n");
      read(&p1);
      printf("Enter 2nd Polynomial :- \n");
      read(&p2);
      add(p1, p2, &p3);
      printf("\nFirst Polynomial is : \n");
      print(&p1);
      printf("\nSecond Polynomial is : \n");
      print(&p2);
      printf("\nAdded Polynomial is : \n");
      print(&p3);
      break;
    case 2:
      printf("Multiplication Of Polynomials :- \n");
      printf("Enter 1st Polynomial :- \n");
      read(&p1);
      printf("Enter 2nd Polynomial :- \n");
      read(&p2);
      mul(p1, p2, &p3);
      printf("\nFirst Polynomial is : \n");
      print(&p1);
      printf("\nSecond Polynomial is : \n");
      print(&p2);
      printf("\nMultiplied Polynomial is : \n");
      print(&p3);
      break;
    case 3:
      printf("Evaluation Of Polynomials :- \n");
      printf("Enter the Polynomial :- \n");
      read(&p1);
      printf("\nEnter value of x: ");
      scanf("%f",&in);
      out = evaluate(p1, in);
      printf("\nPolynomial is : \n");
      print(&p1);
      printf("\nEvaluated Value is : %.2f",out);
      break;
    default:
      printf("Wrong Choice\n");
      goto X;
  }
  getch();
}
