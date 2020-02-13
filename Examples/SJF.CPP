#include<stdio.h>
#include<conio.h>
#define MAX 2000
#define max 30

typedef struct process{
  char name[max];
  int bt, at, wt, ta;
};

void main(){
  int a = 0, n, i, flag = 1, x;
  float awt = 0, ata = 0;
  process p[max], temp;
  clrscr();

  // Title of the Program
  printf("SJF - Shortest Job First Scheduling\n");

  // Getting all processes List with their Arriving Time
  // and Bus Time.
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
  int j, k = 0, l, z[max];
  for(i = 0; i < n; i++){
    z[i] = 0;
  }
  for(i = 0; i < n; i++){
    l = 1000;
    for(j = 0; p[j].at <= a; j++){
      if(z[j] == 0 && p[j].bt < l){
	l = p[j].bt;
	k = j;
     }
    }
    p[k].wt = a - p[k].at;
    a = a + p[k].bt;
    p[k].ta = p[k].wt + p[k].bt;
    awt = awt + p[k].wt;
    ata = ata + p[k].ta;
    z[k] = 1;
  }

  awt = awt/n;
  ata = ata/n;

  // Showing Calculated Values in tabular form:
  printf(" -----------------------------------------------------\n");
  printf("               SJF - Shortest Job First               \n");
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