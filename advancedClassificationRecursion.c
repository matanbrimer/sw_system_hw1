#include"NumClass.h"
#include<math.h>
#include <stdbool.h>


int isPalindromeRec(int num,int temp , int result){

    if( result == num) return result;
    if (temp == 0)return 0;
    
    
    return isPalindromeRec( num, temp/10 ,(result*10) + (temp%10)) ;

}

int isPalindrome(int num){

    int temp =isPalindromeRec( num, num , 0);
    
    return (temp == num)?true:false;
}



int isArmstrongRec(int num, int digit){
    
    if( num == 0) return num;
    

    return (pow(num % 10, digit) + isArmstrongRec(num / 10, digit));

}

int isArmstrong(int num){
    int count = (floor(log10(num)) + 1);
    int temp = isArmstrongRec(num,count);
    return (temp == num)?true:false;
}



