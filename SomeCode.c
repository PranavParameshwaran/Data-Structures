#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N[100];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&N[i]);
    }
    
    int count=0;
    int c10=0;
    int last;
    int modv,val;
    int flag=0;
    long long temp;
    int siz,tiz;
    for(int i=0;i<T;i++)
    {
        count=0;
        last = N[i]%10;
        if(last==9)
        {
            count++;
            printf("%d\n",count);
        }
        else
        {
            temp=N[i];
            if(temp<9)
                printf("-1\n");
            else
            {
                siz = floor(log10(temp)+1);
                val = pow(10,siz-1);
                tiz = temp%val;
                modv = tiz%9;
                if(modv==0)
                {
                    val = tiz/9;
                    count=val;
                    printf("%d\n",count);
                    flag=1;
                }
                if(flag!=1)
                {
                    modv = temp%9;
                    if(modv==0)
                    {
                        val = temp/9;
                        count=val;
                        printf("%d\n",count);
                        flag=1;
                    }
                    else
                        printf("-1\n");
                }
                    
                // while(temp>=9)
                // {
                //     temp-=10;
                //     c10++;
                //     modv = temp%9;
                //     if(modv==0)
                //     {
                //         val = temp/9;
                //         count=val;
                //         printf("%d\n",count);
                //         flag=1;
                //     }
                // }
                // if(flag!=1)
                // {
                //     temp=N[i];
                //     modv = temp%9;
                //     if(modv==0)
                //     {
                //         val = temp/9;
                //         count=val;
                //         printf("%d\n",count);
                //     }
                //     else
                //         printf("-1\n");
                // }
                
            }
        }
    }
    return 0;
}

