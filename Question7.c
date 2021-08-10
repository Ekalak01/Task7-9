#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int N;

    FILE *fp;///pointer for File

    fp = fopen("data.txt","w");/// Create File 

    printf("Input : ");/// Take Input At Parameter 
    scanf("%d",&N);///N is How many line what do u want.

    srand(time(NULL));///RandomSeed by time 

    for (int i = 0; i < N;i++ ){
        fprintf(fp,"%d\n",rand()%1000);
    }
    fclose(fp);
    return (0);
}