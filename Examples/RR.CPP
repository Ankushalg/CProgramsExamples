#include<stdio.h>
#include<conio.h>
#define MAX 2000
#define max 30

typedef struct process{
  char name[max];
  int bt, at, wt, ta, rt, end;
};

void main(){
  int a = 0, n, qt, trt = 0, i, flag = 1;
  float awt = 0, ata = 0;
  process p[max], temp;
  clrscr();

  // Title of the Program
  printf("RR - Round Robin Scheduling\n");

  // Getting all processes List with their Arriving Time
  // and Bus Time.
  printf("Enter Quantum Time: ");
  scanf("%d", &qt);
  printf("Enter total number of processes: ");
  scanf("%d", &n);
  printf("Enter Details of %d processes:\n", n);
  for(i = 0; i < n; i++){
    printf("\nEnter Name of Process %d: ", i + 1);
    scanf(" %s", &p[i].name);
    printf("Enter Arriving Time of Process %d: " , i+1);
    scanf("%d", &p[i].at);
    printf("Enter Bus Time of Process %d: ", i+1);
    scanf("%d", &p[i].bt);
    p[i].rt = p[i].bt;
    trt += p[i].rt;
  }

  // Sorting processes list according to the arriving time
  // using bubble sort.
  while(flag){
   flag = 0;
   for(i = 1; i < n; i++){
     if(p[i - 1].at > p[i].at){
       flag = 1;
       temp = p[i];
       p[i] = p[i - 1];
       p[i-1] = temp;
     }
   }
  }

  // Calculating Waiting Time, Turn Around Time of each process
  // and Average Waiting and Turn Around Time.
  while(trt > 0){
    for(i = 0; i < n; i++){
      if(a < p[i].at){
	a = p[i].at;
      }
      if(p[i].rt == 0){
	continue;
      }
      if(p[i].rt <= qt){
	trt -= p[i].rt;
	a += p[i].rt;
	p[i].rt = 0;
	p[i].end = a;
      } else {
	trt -= qt;
	a += qt;
	p[i].rt -= qt;
      }
    }
  }

  for(i = 0; i < n; i++){
    p[i].ta = p[i].end - p[i].at;
    p[i].wt =p[i].ta - p[i].bt;
    awt += p[i].wt;
    ata += p[i].ta;
  }

  awt = awt/n;
  ata = ata/n;

  // Showing Calculated Values in tabular form:
  printf(" -----------------------------------------------------\n");
  printf("                   RR - Round Robin                   \n");
  printf(" -----------------------------------------------------\n");
  printf("  Job  | Arriving | Bus  | Wait | Turn  Around | Job  \n");
  printf("  ID   | Time     | Time | Time | Time         | Name \n");
  printf(" -----------------------------------------------------\n");
  for(i = 0; i < n; i++){
    printf("  %d  >    %d         %d      %d         %d           %s\n", i, p[i].at, p[i].bt, p[i].wt, p[i].ta, p[i].name);
  }
  printf(" -----------------------------------------------------\n\n");
  printf("Average Wait Time: %.2f\nAverage Turn Around Time: %.2f", awt, ata);

  printf("\n\nPress any key to exit...");
  getch();
}