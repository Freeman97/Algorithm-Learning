#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n, sum, con = 0;
    char seq[81];
    memset(seq, 0, sizeof(seq));
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", seq);
        int i = 0;
        sum = 0;
        con = 0;
        while(seq[i] != '\0')
        {
            if(seq[i] == 'O')
            {
                con++;
                sum += con;
            }
            else if(seq[i] == 'X')
            {
                con = 0;
            }
            i++;
        }
        printf("%d\n", sum);
    }
    return 0;
}