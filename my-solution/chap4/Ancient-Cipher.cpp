#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
char str1[101];
char str2[101];
int cnt1[26];
int cnt2[26];
int comparator(const void* a, const void* b);

int main()
{
    ios::sync_with_stdio(false);
    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str2));
    while(cin >> str1 >> str2)
    {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int m = strlen(str1);
        int n = strlen(str2);
        bool a = true;
        for(int i = 0; i < m; i++)
        {
            cnt1[(int)str1[i] - 65] += 1;
        }
        for(int i = 0; i < n; i++)
        {
            cnt2[(int)str2[i] - 65] += 1;
        }
        qsort(cnt1, 26, sizeof(int), comparator);
        qsort(cnt2, 26, sizeof(int), comparator);
        for(int i = 0; i < 26; i++)
        {
            if(cnt1[i] != cnt2[i])
            {
                a = false;
                break;
            }
        }
        if(a)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}

int comparator(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}