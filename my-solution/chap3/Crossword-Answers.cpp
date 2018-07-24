#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    int row, col;
    char buf;
    int laststar = 0;
    int n = 1;
    char puzzle[10][10];
    int eligible[10][10];
    bool ifstarted = false;
    bool ifFirst = true;
    memset(puzzle, 0, sizeof(puzzle));
    memset(eligible, 0, sizeof(eligible));
    while(true)
    {
        scanf("%d", &row);
        if(row == 0)
        {
            break;
        }
        scanf("%d", &col);
        getchar();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                buf = (char)getchar();
                if(isprint(buf))
                {
                    puzzle[i][j] = buf;
                }
            }
            // throw away the new line character
            getchar();
        }
        // mark the eligible square
        int m = 1;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if((i == 0 || j == 0) && puzzle[i][j] != '*')
                {
                    eligible[i][j] = m++;
                }
                else if(i >= 1 && puzzle[i - 1][j] == '*' && puzzle[i][j] != '*')
                {
                    eligible[i][j] = m++;
                }
                else if(j >= 1 && puzzle[i][j - 1] == '*' && puzzle[i][j] != '*')
                {
                    eligible[i][j] = m++;
                }
            }
        }
        // output
        if(n > 1)
        {
            printf("\n\n");
        }
        printf("puzzle #%d:\n", n++);
        printf("Across\n");
        // across
        // for(int i = 0; i < row; i++)
        // {
        //     ifstarted = false;
        //     laststar = 0;
        //     for(int j = 0; j < col; j++)
        //     {
        //         if(puzzle[i][j] != '*')
        //         {
        //             if(!ifstarted)
        //             {
        //                 printf("  %d.", eligible[i][j]);
        //                 ifstarted = true;
        //             }
        //             printf("%c", puzzle[i][j]);
        //         }
        //         else
        //         {
        //             ifstarted = false;
        //             if(j - laststar > 1)
        //             {
        //                 printf("\n");
        //                 laststar = j;
        //             }
        //         }
        //     }
        //     if(col - laststar > 1)
        //     {
        //         ifstarted = false;
        //         printf("\n");
        //     }
        // }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(eligible[i][j] != 0)
                {
                    if(ifFirst)
                    {
                        ifFirst = false;
                    }
                    else
                    {
                        printf("\n");
                    }
                    printf("  %d.", eligible[i][j]);
                    while(puzzle[i][j] != '*' && j < col)
                    {
                        printf("%c", puzzle[i][j]);
                        j++;
                    }
                }
            }
        }
        ifFirst = true;
        printf("\n")
        // down
        printf("Down:\n");
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(eligible[i][j] != 0)
                {
                    if(ifFirst)
                    {
                        ifFirst = false;
                    }
                    else
                    {
                        printf("\n");
                    }
                    printf("  %d.", eligible[i][j]);
                    int k = i;
                    while(puzzle[k][j] != '*' && k < row)
                    {
                        printf("%c", puzzle[k][j]);
                        eligible[k][j] = 0;
                        k++;
                    }
                }
            }
        }
        ifFirst = true;
        memset(eligible, 0, sizeof(eligible));
    }
    return 0;
}