
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "logic.c"

void main(){
    printf("Pls use CTRl + & CTRL - to resize the below line completely in your view and dont change it later . \n once its done enter anything to start");
    for(int i=0;i<73;i++){
        printf("\n|");
    }
    int a;
    scanf("%d",&a);
    system("cls");
    start();
}

