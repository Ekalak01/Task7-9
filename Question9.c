#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/// แปลงเลขฐานจาก  int --> 16  
char* tohex(int64_t value)/// รับ value 64 bit
{

   char* HEX_DIGITS = "0123456789abcdef";/// ชุดเลขฐาน 16 
   char* s = malloc(sizeof(char)*10);/// จอง Memory ให้ char 10 ช่องสำหรับการ Output  
   
   if(value<0)/// Check เผื่อกรณีที่เป็นติดลบ จะได้แปลง ติดลบให้อยู่ในรูป Binally ได้
   {

      value += ((int64_t)1<<32); /// shiff ไป 32 bit (ปกติใน c int32 bit value) 

   }

   int lim = 0;
   while(1){
      
      char d[2] = {HEX_DIGITS[value & 0xf],'\0'};/// แปลงเป็น Str จาก(0-->f)
      
      char *temp = strdup(s);/// temp* = s
      strcpy(s,d);/// cpy d -> s 
      strcat(s,temp);/// เชื่อม temp + d 
      
      value >>= 4; /// เนื่องจากทำ 16
      
      lim++;

      if (value == 0 || lim == 8)///หาจุด Break เจอต่อเมื่อไม่มีหลักอื่นให้คิดแล้ว เจอ 0 หรือถึง lim
      {
         break;
      }
   }
   /// เพื่อเอา 0x มาต่อหน้า ข้อมูล
   char front[] = "0x";
   char* tmp2= strdup(s);
   strcpy(s,front); /// cpy front --> s
   strcat(s,tmp2); /// front + s
   
   return s;


}
/// Output 
int main () {

   int val_1 = 33;
   printf("%d = %s\n",val_1,tohex(val_1));
   int val_2 = -1;
   printf("%d = %s",val_2,tohex(val_2));
   return 0;
}