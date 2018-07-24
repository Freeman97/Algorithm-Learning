#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    char puzzle[10][10];
    char buf;
    char move;
    int blankR = 0;
    int blankC = 0;
    int n = 1;
    bool err = false;
    bool breakFlag = false;
    memset(puzzle, 0, sizeof(puzzle));
    while(true)
    {
        blankR = 0;
        blankC = 0;
        breakFlag = false;
        err = false;
        memset(puzzle, 0, sizeof(puzzle));
        // construct the puzzle
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                buf = (char)getchar();
                if(isprint(buf))
                {
                    if(buf != 'Z')
                    {
                        puzzle[i][j] = buf;
                        if(buf == ' ')
                        {
                            blankR = i;
                            blankC = j;
                        }
                    }
                    else
                    {
                        breakFlag = true;
                        break;
                    }
                }
            }
            if(breakFlag)
            {
                break;
            }
            getchar();
        }
        if(breakFlag)
        {
            break;
        }
        // operating
        while(true)
        {
            move = getchar();
            if(move == '0')
            {
                break;
            }
            else if(move == 'A')
            {
                if(blankR == 0)
                {
                    err = true;
                }
                else
                {
                    char temp;
                    temp = puzzle[blankR - 1][blankC];
                    puzzle[blankR - 1][blankC] = puzzle[blankR][blankC];
                    puzzle[blankR][blankC] = temp;
                    blankR--;
                }
            }
            else if(move == 'B')
            {
                if(blankR == 4)
                {
                    err = true;
                }
                else
                {
                    char temp;
                    temp = puzzle[blankR + 1][blankC];
                    puzzle[blankR + 1][blankC] = puzzle[blankR][blankC];
                    puzzle[blankR][blankC] = temp;
                    blankR++;
                }
            }
            else if(move == 'R')
            {
                if(blankC == 4)
                {
                    err = true;
                }
                else
                {
                    char temp;
                    temp = puzzle[blankR][blankC + 1];
                    puzzle[blankR][blankC + 1] = puzzle[blankR][blankC];
                    puzzle[blankR][blankC] = temp;
                    blankC++;
                }
            }
            else if(move == 'L')
            {
                if(blankC == 0)
                {
                    err = true;
                }
                else
                {
                    char temp;
                    temp = puzzle[blankR][blankC - 1];
                    puzzle[blankR][blankC - 1] = puzzle[blankR][blankC];
                    puzzle[blankR][blankC] = temp;
                    blankC--;
                }
            }
        }
        getchar();
        // output
        if(n > 1)
        {
            printf("\n");
        }
        printf("Puzzle #%d:\n", n++);
        if(err)
        {
            printf("This puzzle has no final configuration.\n");
            continue;
        }
        bool firstFlag = true;
        for(int i = 0; i < 5; i++)
        {
            firstFlag = true;
            for(int j = 0; j < 5; j++)
            {
                if(!firstFlag)
                {
                    printf(" ");
                }
                if(firstFlag)
                {
                    firstFlag = false;
                }
                printf("%c", puzzle[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}