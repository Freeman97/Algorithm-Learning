#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n, k = 0;
    char str[81];
    bool first = true;
    memset(str, 0, sizeof(str));
    scanf("%d", &n);
    while(n--)
    {
        k = 0;
        scanf("%s", str);
        bool breakFlag = false;
        bool stopFlag = true;
        for(int i = 1; i < strlen(str) / 2 + 1; i++)
        {
            breakFlag = false;
            stopFlag = true;
            for(int j = i; j < strlen(str); j += i)
            {
                for(int l = 0; l < i; l++)
                {
                    if(str[l] != str[j + l])
                    {
                        breakFlag = true;
                        stopFlag = false;
                        break;
                    }
                }
                if(breakFlag)
                {
                    break;
                }
            }
            if(stopFlag)
            {
                k = i;
                if(!first)
                {
                    printf("\n");
                }
                printf("%d\n", k);
                break;
            }
        }
        if(!k)
        {
            k = strlen(str);
            if(!first)
            {
                printf("\n");
            }
            printf("%d\n", k);
        }
        memset(str, 0, sizeof(str));
        first = false;
    }
    return 0;
}