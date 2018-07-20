#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int num, front1, front2;
    char seq[100];
    memset(seq, 0, sizeof(seq));
    scanf("%d", &num);
    while(num--)
    {
        front1 = 0;
        front2 = 0;
        scanf("%s", seq);
        int len = strlen(seq);
        for(int i = 1; i <= len; i++)
        {
            front2 = i;
            for(int j = 0; j < len; j++)
            {
                int p1;
                int p2;
                if(front1 + j > len - 1)
                {
                    p1 = front1 + j - len;
                }
                else
                {
                    p1 = front1 + j;
                }
                if(front2 + j > len - 1)
                {
                    p2 = front2 + j - len;
                }
                else
                {
                    p2 = front2 + j;
                }
                if(seq[p2] < seq[p1])
                {
                    front1 = front2;
                }
                else if(seq[p2] > seq[p1])
                {
                    break;
                }
            }
        }
        for(int k = front1; k < front1 + len; k++)
        {
            int p;
            if(k > len - 1)
            {
                p = k - len;
            }
            else
            {
                p = k;
            }
            printf("%c", seq[p]);
        }
        printf("\n");
    }
    return 0;
}