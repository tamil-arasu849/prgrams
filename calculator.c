#include<stdio.h>
#include<stdio.h>
#include<string.h>

void main()
{
    char cal[30];
    int i, sign;
    int lenofex, res, c, mul, num;
    printf("Enter the expression: ");
    gets(cal);

    //calculating the length of the expression
    lenofex=strlen(cal);

    i=0, sign=1, num=0, mul=0, c=0, res=0;
    while(i<lenofex)
    {
        //extracting numbers out of the expression
        while(cal[i]>='0' && cal[i]<='9')
        {
            num=num*10 + (cal[i]-'0');
            i++;
        }

        //enters this block if cal[i] is an operator
        switch(cal[i])
        {

        //this case is selected if operator is '+'
        case '+':

            //enters this block if the program has already seen a '*' operator
            if(c==1)
            {
                res+=sign*mul*num;
                mul=0;
            }

            //enters this block if the program has already seen a '/' operator
            else if(c==2)
            {
                res+=sign*(mul/num);
                mul=0;
            }

            //enters thid block if the program hasn't seen any '/' and '*' operators recently
            else{
                res+=sign*num;
            }

            c=0;
            num=0;
            sign=1;
            break;

        case '-':

            //enters this block if the program has seen a '*' operator recently
            if(c==1)
            {
                res+=sign*mul*num;
                mul=0;
            }

            //enters this block if the program has seen a '/' operator recently
            else if(c==2)
            {
                res+=sign*(mul/num);
                mul=0;
            }

            //enters this block if the program hasn't seen any '/' and '*' operators recently
            else{
                res+=sign*num;
            }

            c=0;
            num=0;
            sign=-1;
            break;

        case '*':
            //enters this block if there has not been any recent multiplication or division operation
            if(!mul)
            {
                mul=num*sign;
            }

            //enters this block if there has been any recent division operation
            else if(c==2)
            {
                mul/=num*sign;
            }

            //enters this block if there has been any recent multiplication operation
            else
            {
                mul*=num*sign;
            }

            c=1;
            sign=1;
            num=0;
            break;

        case '/':

            //enters this block if there has not been any recent mul or div operations
            if(!mul)
            {
                mul=num*sign;
            }

            //enters this block if there has been any recent mul operation
            else if(c==1)
            {
                mul*=num*sign;
            }

            //enters this block if there has been any recent div operation
            else
            {
                mul/=num*sign;
            }

            c=2;
            num=0;
            sign=1;
            break;
        }

        //this block combines the result with the last number based on the last operator
        if(i>=(lenofex-1))
        {

            //enters this block if the last operator is '*'
            if(c==1)
            {
                res+=mul*num*sign;
            }

            //enters this block if the last operator is '/'
            else if(c==2)
            {
                res+=mul/num*sign;
            }

            //enters this block if the last operator is either '+' or '-'
            else
            {
                res+=num*sign;
            }
        }
        i++;
    }

    printf("\nThe result is = %d", res);
}
