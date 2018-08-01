#include <cstdio>
#include <cstring>
using namespace std;
char ans[1000];
char gue[1000];
int cnt1[26];
bool check(char a);

int main()
{
    int x, c = 7;
    while(true)
    {
        c = 7;
        memset(ans, 0, sizeof(ans));
        memset(gue, 0, sizeof(gue));
        memset(cnt1, 0, sizeof(cnt1));
        scanf("%d", &x);
        if(x == -1)
        {
            break;
        }
        scanf("%s%s", ans, gue);
        int m = strlen(ans);
        int n = strlen(gue);
        for(int i = 0; i < m; i++)
        {
            cnt1[(int)ans[i] - 97] += 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(!check(gue[i]))
            {
                c--;
            }
            if(!c)
            {
                break;
            }
        }
        // final check
        bool d = false;
        for(int i = 0; i < 26; i++)
        {
            if(cnt1[i])
            {
                d = true;
                break;
            }
        }
        printf("Round %d\n", x);
        if(!d)
        {
            printf("You win.\n");
        }
        else if(!c)
        {
            printf("You lose.\n");
        }
        else
        {
            printf("You chickened out.\n");
        }
    }
    return 0;
}

bool check(char a)
{
    if(cnt1[(int)a - 97])
    {
        cnt1[(int)a - 97] = 0;
        return true;
    }
    else
    {
        return false;
    }
}
