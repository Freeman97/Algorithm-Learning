#include <stdio.h>
using namespace std;

int main()
{
    int n, A, B, counter = 1;
    int matrix[1000][1000] = {0};
    while(scanf("%d", &n) == 1 && n)
    {
        //fill the answer line
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &matrix[0][i]);
        }
        //fill and compare the other line with answer line
        printf("Game %d:\n", counter++);
        for(int i = 1; true; i++)
        {
            A = 0;
            B = 0;
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
            if(!matrix[i][0])
            {
                break;
            }
            for(int j = 0; j < n; j++)
            {
                //calculate the value of A
                bool Aflag = false;
                if(matrix[i][j] == matrix[0][j])
                {
                    A++;
                    Aflag = true;
                }
                if(!Aflag)
                {
                    //calculate the value of B
                    int c1 = 0;
                    int c2 = 0;
                    //count the times the number appears in the answer line
                    for(int k = 0; k < n; k++)
                    {
                       if(matrix[i][j] == matrix[0][k])
                       {
                           c1++;
                           if(matrix[0][k] == matrix[i][k])
                           {
                               c1--;
                           }
                       }
                    }
                    //count the times the number appears before the current position
                    for(int k = 0; k < j; k++)
                    {
                        if(matrix[i][j] == matrix[i][k])
                       {
                           c2++;
                           if(matrix[i][k] == matrix[0][k])
                           {
                               c2--;
                           }
                       }
                    }
                    B += c1 > c2 ? 1 : 0;
                }
            }
            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}