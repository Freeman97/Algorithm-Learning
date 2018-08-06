#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
std::string en;
char de[7][128];
char buffer[7];
int reader(int n);

int main()
{
    std::ios::sync_with_stdio(false);
    int n = 0, m = 0;
    // char buf;
    bool flag = false;
    // bool flag2 = false;
    memset(de, 0 ,sizeof(de));
    memset(buffer, 0 ,sizeof(buffer));
    while(std::getline(std::cin, en))
    {
        if(en[0] == 0)
        {
            break;
        }
        flag = false;
        // flag2 = false;
        n = en.length();
        m = 0;
        // while(true)
        // {
        //     buf = getchar();
        //     printf("%c ", buf);
        //     if(buf != '\n' && buf != -1)
        //     {
        //         en[n] = buf;
        //         n++;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // if(flag2)
        // {
        //     break;
        // }
        // std::cout << "\n";
        // for(int i = 0; i < n; i++)
        // {
        //     std::cout << en[i] << " ";
        // }
        // std::cout << "\n";
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < pow(2, i + 1) - 1; j++)
            {
                de[i][j] = en[m];
                // std::cout << (int)en[m] << " " << i << " " << j << "\n";
                m++;
                if(m >= n)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        flag = false;
        // for(int i = 0; i < 7; i++)
        // {
        //     for(int j = 0; j < pow(2, i + 1) - 1; j++)
        //     {
        //         std::cout << de[i][j] << " ";
        //         m--;
        //         if(m == 0)
        //         {
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if(flag)
        //     {
        //         break;
        //     }
        //     std::cout << "\n";
        // }
        // std::cout << "\n";
        // std::cout << "-------------\n";
        // decoding
        while(true)
        {
            char buf2;
            for(int i = 0; i < 3;)
            {
                std::cin >> buf2;
                if(buf2 != '\n')
                {
                    buffer[i] = buf2;
                    i++;
                }
            }
            int l = reader(3);
            if(l == 0)
            {
                break;
            }
            while(true)
            {
                bool flag = true;
                for(int i = 0; i < l;)
                {
                    std::cin >> buf2;
                    if(buf2 != '\n')
                    {
                        buffer[i] = buf2;
                        if(buffer[i] != '1')
                        {
                            flag = false;
                        }
                        i++;
                    }
                }
                if(flag)
                {
                    break;
                }
                int r = reader(l);
                std::cout << de[l - 1][r];
            }
        }
        std::cout << "\n";
        std::cin.ignore();
    }
    return 0;
}

int reader(int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum * 2 + ((int)buffer[i] - 48);
    }
    return sum;
}