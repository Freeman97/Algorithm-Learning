#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int rect[6][2];
    memset(rect, 0, sizeof(rect));
    while(cin >> rect[0][0] >> rect[0][1])
    {
        int n = 1;
        int count[6] = {1, 0, 0, 0, 0, 0};
        int m = 1;
        while(true)
        {
            int buf1, buf2;
            int exist = -1;
            cin >> buf1 >> buf2;
            for(int i = 0; i < n; i++)
            {
                if(((buf1 == rect[i][0]) && (buf2 == rect[i][1])) || ((buf1 == rect[i][1]) && (buf2 == rect[i][0])))
                {
                    // cout << "im in!" << endl;
                    exist = i;
                    break;
                }
            }
            if(exist != -1)
            {
                if(count[exist] % 2 == 0)
                {
                    rect[n][0] = buf1;
                    rect[n][1] = buf2;
                    n++;
                }
                count[exist] += 1;
            }
            else
            {
                rect[n][0] = buf1;
                rect[n][1] = buf2;
                count[n] += 1;
                n++;
            }
            m++;
            if(m >= 6)
            {
                break;
            }
        }
        // checkit
        bool possible = false;
        int temp1, temp2;
        if(rect[3][0] != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            memset(rect, 0, sizeof(rect));
            continue;
        }
        for(int i = 1; i < n; i++)
        {
            if(rect[0][0] == rect[i][0])
            {
                temp1 = i;
                temp2 = 1;
                possible = true;
            }
            else if(rect[0][0] == rect[i][1])
            {
                temp1 = i;
                temp2 = 0;
                possible = true;
            }
        }
        if(possible)
        {
            if(((rect[3 - temp1][0] == rect[0][1]) && (rect[3 - temp1][1] == rect[temp1][temp2])) || ((rect[3 - temp1][0] == rect[temp1][temp2]) && (rect[3 - temp1][1] == rect[0][1])))
            {
                cout << "POSSIBLE" << endl;
                memset(rect, 0, sizeof(rect));
                continue;
            }
        }
        cout << "IMPOSSIBLE" << endl;
        memset(rect, 0, sizeof(rect));
    }
    return 0;
}
