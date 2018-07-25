#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int cycle[10000];
    int d, n, m, integer, counter = 0, length = 0, b = 0;
    bool fin = false;
    memset(cycle, 0, sizeof(cycle));
    while(scanf("%d", &n) == 1)
    {
        fin = false;
        scanf("%d", &d);
        // preprocess: ensure the numerator smaller than denominator and store the integer part
        integer = n / d;
        m = n;
        n = n % d;
        for(int i = 0; ; i++)
        {
            // manual division
            n = 10 * n;
            for(int j = 0; ; j++)
            {
                if((j + 1) * d > n)
                {
                    cycle[i] = j;
                    n = n - j * d;
                    break;
                }
            }
            bool breakFlag1 = false;
            bool breakFlag2 = false;
            if(i >= 10)
            {
                for(int j = 1; j < (i + 1) / 4 + 1; j++) // j <= 3 j++
                {
                    breakFlag2 = false;
                    counter = 0;
                    int k = 0;
                    for(k = i - j; k >= j - 1; k -= j)
                    {
                        for(int l = 0; l < j; l++)
                        {
                            if(cycle[i - l] != cycle[k - l])
                            {
                                if(counter >= 3)
                                {
                                    breakFlag1 = true;
                                    breakFlag2 = true;
                                    b = k + 1;
                                    length = j;
                                    fin = true;
                                }
                                else
                                {
                                    breakFlag2 = true;
                                }
                                break;
                            }
                        }
                        if(breakFlag2)
                        {
                            break;
                        }
                        counter++;
                    }
                    if(breakFlag1)
                    {
                        break;
                    }
                    if(!breakFlag2)
                    {
                        b = k + 1;
                        length = j;
                        fin = true;
                        break;
                    }
                }
                if(fin)
                {
                    break;
                }
            }
        }
        // output
        printf("%d/%d = %d.", m, d, integer);
        for(int i = 0; i < b; i++)
        {
            printf("%d", cycle[i]);
        }
        printf("(");
        for(int i = 0; i < length; i++)
        {
            printf("%d", cycle[b + i]);
            if(b + i == 49)
            {
                printf("...");
                break;
            }
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n", length);
        printf("\n");
        break;
    }
    return 0;
}