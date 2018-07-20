#include <stdio.h>
using namespace std;

int main()
{
    int T;
    int a[100000] = {0};
    bool ifhave = false;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < T; i++)
    {
        ifhave = false;
        for(int j = a[i] - 45; j <= a[i]; j++)
        {
            if(j <= 0)
            {
                continue;
            }
            int digitsum = j, temp = j;
            for(int k = 0; k < 5; k++)
            {
                digitsum += temp % 10;
                temp /= 10;
            }
            if(digitsum == a[i])
            {
                printf("%d\n", j);
                ifhave = true;
                break;
            }
        }
        if(!ifhave)
        {
            printf("%d\n", 0);
        }
    }
    return 0;
}