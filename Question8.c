#include <stdio.h>
#include <stdlib.h>
#include "qsort.c"

int main(){

    char ch ;
    char *filename = "data.txt";
    ///แบ่งการเปิดไฟล์เป็น 3 ขั้นตอนเพื่อให้ทำไปทีละขั้น ไม่ให้เกิด Error
    
    FILE *fp;//check file
    FILE *rf;//read file
    FILE *wf;//write file (After sort)
    
    int count = 0;

    fp = fopen(filename,"r");

    if (fp == NULL)//เมื่อเปิดไฟล์ไม่ได้ให้แจ้ง Error
    {
        printf("ERROR: could not open file");
        
        return 1;
    }
    //นับจำนวนบรรทัดในไฟล์

    for (ch = getc(fp); ch != EOF; ch = getc(fp)) // Count จำนวนบรรทัดในไฟล์(ตัวเลขชุด)
        if (ch == '\n')
            count = count + 1; 
    printf("Count %d\n",count);

    fclose(fp);
    // 

    rf = fopen(filename,"r");
    char* row;
    ssize_t len = 0;
    ssize_t read;
    int buff[count];//สร้าง Array เท่าขนาดที่นับได้
        
    int i=0; 
    while (((read = getline(&row,&len,rf))!=-1)&&(i<count))///read(อ่านค่าในไฟล์( String ))
    {
        buff[i]=atoi(row);///แปลง string เป็น int ( ตัวเลข ) แล้วเก็บใน Array --> buff
        i++;///เก็บค่า i
    }
    fclose(rf);

    quicksort(buff,0,count-1);///Sort ข้อมูลใน Array 0 --> x-1
    
    for(int j = 0;j<count;j++){
        printf("%d\n",buff[j]);/// แสดงค่าหลังจากเรียงข้อมูลแล้ว โดยใช้ for ในการอ่านไฟล์ โดยแสดงใน Parameter 
    }

    wf = fopen("data_sorted.txt","w");/// เขียนไฟล์ใหม่

    for(int x = 0;x < count ; x++)
    {

        fprintf(wf,"%d\n",buff[x]);/// เขียนค่าลงในไฟล์

    }
    fclose(wf);
    return 0;

}