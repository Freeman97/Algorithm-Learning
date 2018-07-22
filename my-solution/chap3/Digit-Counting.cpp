#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n, T;
    int count[10];
    memset(count, 0, sizeof(count));
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &T);
        for(int i = 1; i <= T; i++)
        {
            int j = i;
            while(j > 0)
            {
                count[j % 10] += 1;
                j /= 10;
            }
        }
        printf("%d", count[0]);
        for(int i = 1; i < 10; i++)
        {
            printf(" %d", count[i]);
        }
        printf("\n");
        memset(count, 0, sizeof(count));
    }
    return 0;
}