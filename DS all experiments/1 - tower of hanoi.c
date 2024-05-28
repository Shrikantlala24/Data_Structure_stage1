#include <stdio.h>
void tower(int n,char src,char des,char aux)
{
 if(n==1)
 {
 printf("Move disk 1 from Tower %c to Tower %c",src,des);
 return;
 }
 tower(n-1,src,aux,des);
 printf("\nMove disk %d from Tower %c to Tower %c\n",n,src,des);
 tower(n-1,aux,des,src);
}
int main()
{
 int n;
 printf("Enter the number of disks:");
 scanf("%d",&n);
 tower(n,'A','B','C');
printf("\n");
 return 0;
}