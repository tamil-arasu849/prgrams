#include<stdio.h>

void main()
{
    int n, temp, r, sum=0;
    printf("Enter the number : ");
    scanf("%d", &n);
    do{
        temp=n;
        sum=0;
        while(n>0)
        {
            r=n%10;
            sum=(sum*10)+r;
            n=n/10;
        }
        n=temp;
        n++;
    }while(temp!=sum);

    if(temp==sum)
        printf("The next palindrome number is %d", sum);
}
