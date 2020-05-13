#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long num; // num : Credit Card Number

    do
    {
        printf("Credit Card Number: \n");
        scanf("%ld", &num);
    }
    while (num <= 0);

    long tnum = num; // tnum : Temporary number to be used in the iterations
    int sum = 0; // Sum : checksum for credit card
    int count = 0; // Count : Number of digits in Credit Card
    long divisor = 10; // Divisor : number will be used to identify fist or two firist digits in Credit Card Number

    // while loop to identify last Digit of Credit Card and add it to the check sum and move to the next number in a similar pattern
    while (tnum > 0)
    {
        int lastDigit = tnum % 10;
        sum = sum + lastDigit;
        tnum = tnum / 100;
    }

    // While loop to identify the digit before last digit in Credit Card Number and multiply it by two
    tnum = num / 10;
    while (tnum > 0)
    {
        int DigitbeforelastDigit = tnum % 10;
        int timesTwo = DigitbeforelastDigit * 2;
        // if the number tinmes two is two digits , then %10 & /10 will decompose this number to its digits
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        tnum = tnum / 100;
    }

    // While loop to Count the number of Digits in Credit Card Number
    tnum = num;
    while (tnum != 0)
    {
        tnum = tnum / 10;
        count++;
    }

    // For loop to Calculate how many Zeros to divid Credit Card Number by to get either First digit or first two digits of Credit Card number
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = num / divisor;
    int firstTwoDigits = num / (divisor / 10);

    // Multi IF Loops to identify Credit Card Type
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15)
        {
            printf("AMEX");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && count == 16)
        {
            printf("MASTERCARD");
        }
        else
        {
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }

    printf("\n");
}