#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int str2Int(char a[]);

int main()
{
    int T;
    char seq[81];
    char buf[3];
    double current;
    memset(seq, 0, sizeof(seq));
    memset(buf, 0, sizeof(buf));
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", seq);
        double mass = 0;
        int i = 0;
        int j = 0;
        while(seq[i] != '\0')
        {
            switch(seq[i])
            {
                case 'C':
                {
                    current = 12.01;
                    mass += current;
                    j = 0;
                    break;
                }
                case 'H':
                {
                    current = 1.008;
                    mass += current;
                    j = 0;
                    break;
                }
                case 'N':
                {
                    current = 14.01;
                    mass += current;
                    j = 0;
                    break;
                }
                case 'O':
                {
                    current = 16.00;
                    mass += current;
                    j = 0;
                    break;
                }
                default:
                {
                    break;
                }
            }
            if(isdigit(seq[i]))
            {
                buf[j] = seq[i];
                j++;
                if(!isdigit(seq[i+1]) || seq[i+1] == '\0')
                {
                    mass += current * (str2Int(buf) - 1);
                    memset(buf, 0, sizeof(buf));
                }
            }
            i++;
        }
        printf("%.3f\n", mass);
    }
}

int str2Int(char a[])
{
    int i = 0;
    int sum = 0;
    while(a[i] != '\0')
    {
        sum = sum * 10 + (a[i] - 48);
        i++;
    }
    return sum;
}