// code for counting how many coins needed for specific amount of change owned.
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        // Set float input "n" and store user input named "Change Owned" in it.
        n = get_float("Change Owned: ");
    }
    // while do loop so user cannot put a value equal or less than 0
    while (n <= 0);
    // Define variables will be needed to count number of coins for each categoty and sum total number of coins
    int i, coins25 = 0, coins10 = 0, coins5 = 0, coins1 = 0, coins;
    // convert the user input in Dollars to Cents.
    i = round(n * 100);
    // use while if loop to account number of coins for each of 25c, 10c, 5c, 1c categories.
    while (i > 0)
    {
        if (i >= 25)
        {
            i = i - 25;
            coins25 = coins25 + 1;
        }
        else   if (i >= 10)
        {
            i = i - 10;
            coins10 = coins10 + 1;
        }
        else   if (i >= 5)
        {
            i = i - 5;
            coins5 = coins5 + 1;
        }
        else   if (i >= 1)
        {
            i = i - 1;
            coins1 = coins1 + 1;
        }
        // Sum all above counts in variable coins.
        coins = coins25 + coins10 + coins5 + coins1;
    }
    {
        printf("%i", coins);
    }
    printf("\n");
}