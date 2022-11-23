#include <math.h>
#include "NumClass.h"
#include <stdbool.h>

int isStrong(int num)
{

    int count = 0;
    int temp = num;
    int res = 1;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    temp = num;

    for (int i = 0; i < count; i++)
    {
        for (int y = 1; y <= temp % 10; y++)
        {
            res = res * y;
        }
        num -= res;
        temp = temp / 10;
        res = 1;
    }
 
    return (num == 0)?true:false;
}

int isPrime(int num)
{
    int sqrtNum =(int)sqrt((double)num);
    int ret=1;
    for (int i = 2; i <= sqrtNum; i++)
    {
        if (num % i == 0)
        {
            ret =0;
        }
    }

    return (ret == 1)?true:false;
   



}

