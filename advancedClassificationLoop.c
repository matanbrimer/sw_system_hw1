#include"NumClass.h"
#include<math.h>
#include <stdbool.h>

int isPalindrome(int num){

    int temp = num;
    int count = 0;
    int result = 0;

    while(temp != 0){
        count++;
        temp = temp / 10;
    }
    temp=num;
    for (int i = 0; i < count; i++)
    {
        result = (result*10) + (temp%10);
        temp = temp / 10;
    }
    
   

    return (num == result)?true:false;

}

int isArmstrong(int num){

    int temp = num;
    int count = 0;
    while(temp != 0){
        count++;
        temp = temp / 10;
    }
    temp = num;

    for (int i = 0; i < count; i++)
    {
       num -= pow(temp%10,count);
       temp = temp / 10;
    }
    


    return (num==0)?true:false;

}
