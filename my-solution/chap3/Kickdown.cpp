#include <iostream>
#include <string>
using namespace std;

int main()
{
    string master;
    string driven;
    while(cin >> master >> driven)
    {
        int offset1 = 0;
        int offset2 = 0;
        bool exitFlag = true; 
        int m = master.length();
        int d = driven.length();
        for(int i = 0; i < m; i++)
        {
            exitFlag = true;
            for(int j = 0; j < d; j++)
            {
                if((master[i + j] == '2') && (driven[j] == '2'))
                {
                    exitFlag = false;
                    break;
                }
                if(i + j + 1>= m)
                {
                    break;
                }
            }
            if(exitFlag)
            {
                offset1 = i;
                break;
            }
        }
        if(!exitFlag)
        {
            offset1 = m;
        }
        exitFlag = true;
        for(int i = 0; i < driven.length(); i++)
        {
            exitFlag = true;
            for(int j = 0; j < m; j++)
            {
                if((master[j] == '2') && (driven[i + j] == '2'))
                {
                    exitFlag = false;
                    break;
                }
                if(i + j + 1 > d)
                {
                    break;
                }
            }
            if(exitFlag)
            {
                offset2 = i;
                break;
            }
        }
        if(!exitFlag)
        {
            offset2 = d;
        }
        offset1 = offset1 + d > m ? offset1 + d : m;
        offset2 = offset2 + m > d ? offset2 + m : d;
        cout << (offset1 > offset2 ? offset2 : offset1) << endl;
    }
    return 0;
}
