// @author Ankush Kumar (ankushalg@gmail.com)
#include<stdio.h>
#include<conio.h>
int getAND(int i,int j){
    if(i == 1 && j == 1){
        return 1;
    }
    return 0;
}
int getOR(int i,int j){
    if(i == 1 || j == 1){
        return 1;
    }
    return 0;
}
int getNOT(int i){
    if(i == 1){
        return 0;
    }
    return 1;
}
void printAND(){
    int i,j;
    printf("\n AND TABLE:-");
    printf("\n| A | B | A AND B |\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("| %d | %d |    %d    |\n",i,j,getAND(i,j));        
        }
    }
}
void printOR(){
    int i,j;
    printf("\n OR TABLE:-");
    printf("\n| A | B | A OR B |\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("| %d | %d |   %d  |\n",i,j,getOR(i,j));        
        }
    }
}
void printNOT(){
    int i;
    printf("\n NOT TABLE:-");
    printf("\n| A | NOT A |\n");
    for(i = 0; i < 2; i++){
        printf("| %d |   %d   |\n",i ,getNOT(i));
    }
}
void main(){
    int n;
    clrscr();
    printf("Truth Tables & Operations:\n1 - AND Operation\n2 - OR Operation\n3 - NOT Operation\n0 - Exit");
    scanf("%d", &n);
    switch (n) {
    case 0:
        printf("Press Any key to exit.");    
        break;
    case 1:
        printAND();
        break;
    case 2:
        printOR();
        break;
    case 3:
        printNOT();
        break;
    default:
        printf("Wrong Input... Try Agarin...");
        break;
    }
    getch();
}