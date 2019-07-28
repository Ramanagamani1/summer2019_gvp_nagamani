///*stringcompress*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
void strcompress(char *s){
int count = 0;
int l = strlen(s);
int p=0, q=0;
for (int i = 0; i < l; ){
    if (s[p] == s[i]){
       i++;
          count++;
}
if (s[i] != s[p] && count == 1){
          s[q] = s[p];
            q++, p++;
      }
     if ((s[i]!=s[p])&&count > 1){
             if (count < 9){
             s[q] = s[p];
             s[q+1] = count+'0';
             p = p + count;
             q=q+2;
   }
    if (count > 9){
        int c = count;
        int num = count;
        int len = 0;
      while (c != 0){
          c = c / 10;
        len++;
    }
        p = p + len;
         while (num != 0){

           s[p--] = num % 10 + '0';
           num /= 10;
   }
      p = p + count;
      q = q + len+1;
  }
      count = 0;
 }
       
}
s[q] = '\0';
}
int main(){
char *s = (char *)malloc(100 * sizeof(char));
printf("enter the string to compress:");
scanf("%s", s);
strcompress(s);
printf("the compressed string is %s", s);
_getch();
return 0;
}
