#include <cstdio>
#include <cstring>
int n, k, m, q, p1 = -1, p2;
int c[20];
void go(int v, int step);

int main()
{
    while(true)
    {
        scanf("%d%d%d", &n, &k, &m);
        if(!(n || k || m))
        {
            break;
        }
        q = n;
        p1 = -1;
        p2 = n;
        memset(c, 0, sizeof(c));
        while(true)
        {
            go(0, k);
            go(1, m);
            if(p1 == p2)
            {
                c[p1] = 1;
                q--;
                printf("%3d", p1 + 1);
            }
            else
            {
                c[p1] = 1;
                c[p2] = 1;
                printf("%3d", p1 + 1);
                printf("%3d", p2 + 1);
                q -= 2;
            }
            if(!q)
            {
                break;
            }
            printf(",");
        }
        printf("\n");
    }
    return 0;
}

void go(int v, int step)
{
    if(!v)
    {
        for(int i = 0; i < step;)
        {
            p1 += 1;
            if(p1 > n - 1)
            {
                p1 = 0;
            }
            if(!c[p1])
            {
                i++;
            }
        }
        return;
    }
    else
    {
        for(int i = 0; i < step;)
        {
            p2 -= 1;
            if(p2 < 0)
            {
                p2 = n - 1;
            }
            if(!c[p2])
            {
                i++;
            }
        }
        return;
    }
    return;
}
