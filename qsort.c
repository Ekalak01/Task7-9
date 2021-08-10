#include<stdio.h>
void quicksort(int number[],int first,int last)/// สร้าง Funtion Quicksort ขึ้นมา โดย Void รับข้อมูลจาก Parameter
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;
      
      /// ทำการเปรียบเทียบ i,j โดย Pivot ใช้ในการเปรียบเทียบ
      
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)/// สลับที่ i , j โดยมี temp มารองรับ
         { 
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      
      /// ทำการ Rucursion โดยลดขนาดการวน แล้วทำจนเสร็จนั้นเอง
      
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}