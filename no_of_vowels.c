#include<stdio.h>
#include<string.h>

void main()
{
    char c[20];
    int n=0, i=0;
    printf("Enter the string : ");
    scanf("%s", c);
    while(c[i]!=NULL)
    {
        if(c[i]=='a' || c[i]=='e' || c[i]=='i' || c[i]=='o' || c[i]=='u' || c[i]=='A' || c[i]=='E' || c[i]=='I' || c[i]=='O' || c[i]=='U')
        {
            n++;
        }
        i++;
    }

    printf("The number of vowels in the given string is %d", n);
}
