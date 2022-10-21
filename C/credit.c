#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long card = get_long("Enter the card number:\n");
    long carddigit = card;
    long startingDigits = card;
    long soma = 0;
    bool par = false;
    while (card > 0) //if card bigger than 0
    {
        int num = card % 10; // gets the last digit
        if (par) //start false (we dont want to do line 17-23)
        {
            int mult1 = num * 2; //if odd multiple by 2
            int soma2 = 0;
            if (mult1 > 9) //if its bigger than 9, gets second digit and summ 1
            {
                soma2 = mult1 % 10;
                soma2 = soma2 + 1;
            }
            else //multiples by 2
            {
                soma2 = num * 2;
            }
            num = soma2;
        } //divide card/10, change to true, and summ the loop
        card /= 10;
        par = !par;
        soma += num;
    }
    int luhn = soma;
    int digit = 0;
    while (carddigit > 0) //while digits is bigger than 0
    {
        carddigit /= 10; //divide by 10
        digit++; //store +1
    }
    if (luhn % 10 == 0)
    {
        while (startingDigits > 99)
        {
            startingDigits /= 10;
        }
        if (digit == 15 && (startingDigits == 34 || startingDigits == 37))
        {
            printf("AMEX\n");
        }
        //Mastercard has 16 digits, starts between 50 and 56
        else if (digit == 16 && (startingDigits > 50 && startingDigits < 56))
        {
            printf("MASTERCARD\n");
        }
        //Visa has 13 or 16 digits, starts with 4
        else if ((digit == 13 || digit == 16) && startingDigits / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (luhn % 10 != 0)
    {
        printf("INVALID\n");
    }
    return 0;
}