#include <cs50.h>
#include <stdio.h>

int odd_even(int);

int main(void)
{
    // get credit number
    long credit = get_long("Number: ");

    // check sum
    long temp = credit;
    int i;
    int j;
    int sum = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    for (i = 1; temp != 0; i++)
    {
        int digit = temp % 10; // getting single digit
        int n = odd_even(i);   // for skiping digits
        if (n == 1)
        {
            int product = digit * 2; // multiplying digits by 2
            if (product > 9)         // checking if product is greater than 9 to split in digits
            {
                int temp_1 = product;
                for (j = 0; temp_1 != 0; j++)
                {
                    int digit_1 = temp_1 % 10; // adding digits of product greater than 9
                    sum_1 = sum_1 + digit_1;
                    temp_1 = temp_1 / 10;
                }
            }
            else
            {
                sum = sum + product; // adding digit which is less than 9
            }
        }
        else
        {
            sum_2 = sum_2 + digit;
        }
        temp = temp / 10;
    }
    sum = sum + sum_1 + sum_2; // adding every digit

    // check length and other requirements
    int m;
    int digit_2;
    long temp_2 = credit;
    for (m = 0; m < i - 1; m++)
    {
        digit_2 = temp_2 % 10; // first number of card
        temp_2 = temp_2 / 10;
    }

    int p;
    int digit_3;
    long temp_3 = credit;
    for (p = 0; p < i - 2; p++)
    {
        digit_3 = temp_3 % 10; // first number of card
        temp_3 = temp_3 / 10;
    }
    printf("%i", digit_3);

    int last = sum % 10;

    if (digit_2 == 5)
    {
        if (digit_3 == 1 || digit_3 == 2 || digit_3 == 3 || digit_3 == 4 || digit_3 == 5)
        {
            if (last == 0)
            {
                if (i - 1 == 16)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit_2 == 3)
    {
        if (digit_3 == 4 || digit_3 == 7)
        {
            if (last == 0)
            {
                if (i - 1 == 15)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit_2 == 4)
    {
        if (last == 0)
        {
            if (i - 1 > 12 && i - 1 < 17)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int odd_even(int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
