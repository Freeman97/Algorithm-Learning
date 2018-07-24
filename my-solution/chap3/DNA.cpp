#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int T, m, n;
    int ACGT[1000][4];
    char acgt[4] = {'A', 'C', 'G', 'T'};
    int error = 0;
    scanf("%d", &T);
    memset(ACGT, 0, sizeof(ACGT));
    while(T--)
    {
        memset(ACGT, 0, sizeof(ACGT));
        error = 0;
        scanf("%d", &m);
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                char current;
                scanf("%c", &current);
                switch(current)
                {
                    case 'A':
                    {
                        ACGT[j][0] += 1;
                        break;
                    }
                    case 'C':
                    {
                        ACGT[j][1] += 1;
                        break;
                    }
                    case 'G':
                    {
                        ACGT[j][2] += 1;
                        break;
                    }
                    case 'T':
                    {
                        ACGT[j][3] += 1;
                        break;
                    }
                }
            }
            getchar();
        }
        for(int i = 0; i < n; i++)
        {
            int max = 0;
            int index = 0;
            for(int j = 0; j < 4; j++)
            {
                if(ACGT[i][j] > max)
                {
                    max = ACGT[i][j];
                    index = j;
                }
            }
            for(int j = 0; j < 4; j++)
            {
                if(j != index)
                {
                    error += ACGT[i][j];
                }
            }
            printf("%c", acgt[index]);
        }
        printf("\n");
        printf("%d\n", error);
    }
    return 0;
}