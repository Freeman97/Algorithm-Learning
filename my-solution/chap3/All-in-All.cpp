#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    bool no = false;
    while(cin >> s >> t)
    {
        no = false;
        int k = 0;
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = k; j < t.length(); j++)
            {
                if(t[j] == s[i])
                {
                    k = j + 1;
                    break;
                }
                if(j + 1 >= t.length())
                {
                    no = true;
                    break;
                }
            }
            if(no)
            {
                break;
            }
        }
        if(!no)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
