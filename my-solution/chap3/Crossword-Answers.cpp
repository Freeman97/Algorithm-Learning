#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    int row, col;
    char buf;
    int n = 1;
    char puzzle[10][10];
    int eligible[10][10];
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
            printf("\n");
        }
        printf("puzzle #%d:\n", n++);
        printf("Across\n");
        // across
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(eligible[i][j] != 0)
                {
                    printf("%3d.", eligible[i][j]);
                    while(puzzle[i][j] != '*' && j < col)
                    {
                        printf("%c", puzzle[i][j]);
                        j++;
                    }
                    printf("\n");
                }
            }
        }
        // down
        printf("Down\n");
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(eligible[i][j] != 0)
                {
                    printf("%3d.", eligible[i][j]);
                    int k = i;
                    while(puzzle[k][j] != '*' && k < row)
                    {
                        printf("%c", puzzle[k][j]);
                        eligible[k][j] = 0;
                        k++;
                    }
                    printf("\n");
                }
            }
        }
        memset(eligible, 0, sizeof(eligible));
    }
    return 0;
}