#include <stdio.h>
#include <string.h>
using namespace std;

int count[10];
void counter(int T, int count[]);

int main()
{
    int n, T;
    memset(count, 0, sizeof(count));
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &T);
        counter(T, count);
        printf("%d", count[0]);
        for(int i = 1; i < 10; i++)
        {
            printf(" %d", count[i]);
        }
        printf("\n");
        // counter(T / 10, count);
        // counter(T / 100, count);
        // counter(T / 1000, count);
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

void counter(int T, int count[])
{
    int a = 0, b = 0, c = 0, d = 0, a0 = 0, a1 = 0, a2 = 0, a3 = 0;
    a = T / 10; 
    b = T / 100;
    c = T / 1000;
    d = T / 10000;
    a0 = T % 10;//ge
    a1 = (T % 100 - a0) / 10;//shi
    a2 = (T % 1000 - 10 * a1 - a0) / 10;//bai
    a3 = (T % 10000 - 100 * a2 - 10 * a1 - a0) / 10;//qian
    for(int i = 0; i < 10; i++)
    {
        count[i] += a;
    }
    for(int i = 1; i <= a0; i++)
    {
        count[i] += 1;
    }
    if(a1 != 0)
    {
        count[a1] += (a0 + 1);
    }
    if(a2 != 0)
    {
        count[a2] += (a0 + 1);
    }
    if(a3 != 0)
    {
        count[a3] += (a0 + 1);
    }
    return;
}