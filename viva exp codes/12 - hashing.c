#include<stdio.h>
#define TABLE_SIZE 10

int hash(int key,int table[]) {
    int check;
    check=key % TABLE_SIZE;
    if(table[check]==0){
        return check;
    }
    else{
        while(table[check]!=0){
            key=key+1;
           check=key % TABLE_SIZE; 
        }
         return check;
    }
}

int main() {
    int n,num;
    int table[TABLE_SIZE] = {0,0,0,0,0,0,0,0,0,0};
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        int index=hash(num,table);
        table[index] = num;
    }
    for (int i = 0; i < 10; i++) {
       printf("%d\t",table[i]);
    }
    return 0;
}
