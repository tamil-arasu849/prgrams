#include<stdio.h>

void main()
{
    int n, r, sum=0, temp;
    printf("Enter the number : ");
    scanf("%d", &n);
    temp=n;
    while(n>0)
    {
        r=n%10;
        sum=(sum*10)+r;
        n=n/10;
    }

    if(temp==sum)
        printf("Given number is a palindrome number. %d", sum);
    else
        printf("Given number is not a palindrome number. %d", sum);
}
