#include<stdio.h>
#include"NumClass.h"
#include <stdbool.h>

int main(){
    int num1=0,num2=0;

    do
    {
        printf("Please enter 2 positive number \n");
        scanf("%d %d", &num1 ,&num2);
    } while (num1 < 0 || num2 < 0 || num1>num2) ;



char s[][40]= {"The Armstrong numbers are: ","The Palindromes are:","The Prime numbers are: ","The Strong numbers are: "};

for (int i = 1; i <= 4; i++)
{
    printf("%s",s[i-1]);

    for ( int h = num1; h <= num2; h++)
    { 
        switch(i)
        {
        case 1:
            if(isArmstrong(h))
            { 
            printf("%d ", h);
            }
            break;

        case 2:
            if(isPalindrome(h))
            {
            printf("%d ", h);
            }
            break;

        case 3:
            if(isPrime(h))
            {  
            printf("%d ", h);
            }
            break;

        case 4:
            if (isStrong(h))
            {
            printf("%d ", h);
            }              
            break;

        }
    }
    printf("\n");
}
        
    
        
    
    
return 0;
    
}