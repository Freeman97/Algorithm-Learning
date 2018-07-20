#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n, x, y, counter = 1;
    scanf("%d", &n);
    int a[20][20];
    for(int k = 0; k < n / 2; k++)
    {
        x = k;
        y = n - 1 - k;
        for(int i = x; i <= n - 1 - x; i++)
        {
            a[i][y] = counter;
            counter++;
        }
        for(int i = y - 1; i >= n - 1 - y; i--)
        {
            a[n - 1 - x][i] = counter;
            counter++;
        }
        for(int i = n - 1 - x - 1; i >= x; i--)
        {
            a[i][n - 1 - y] = counter;
            counter++;
        }
        for(int i = n - 1 - y + 1; i <= y - 1; i++)
        {
            a[x][i] = counter;
            counter++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("%3d\n", a[i][n - 1]);
    }
}