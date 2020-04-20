#include <iostream>
#include <string>

using namespace std;

int path[100000];

int main()
{
    for (int i = 0; i < 100000; i++)
    {
        path[i] = -1;
    }
    int word1, word2, n;
    cin >> word1 >> word2 >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        char word;
        cin >> temp >> word;
        cin >> path[temp];
    }
    int count1, count2;
    count1 = count2 = 0;
    temp = word1;
    while (path[temp] != -1)
    {
        count1++;
        temp = path[temp];
    }
    temp = word2;
    while (path[temp] != -1)
    {
        count2++;
        temp = path[temp];
    }
    if (count1 > count2)
    {
        int count = 0;
        while (count != (count1 - count2))
        {
            count++;
            word1 = path[word1];
        }
        while (word1 != word2)
        {
            word1 = path[word1];
            word2 = path[word2];
        }
        if (word1 == -1)
        {
            cout << word1;
        }
        else
        {
            string str;
            str = to_string(word1);
            int leng = str.size();
            for (int i = 0; i < 5 - leng; i++)
            {
                cout << '0';
            }
            cout << str;
        }
    }
    else
    {
        int count = 0;
        while (count != (count2 - count1))
        {
            count++;
            word2 = path[word2];
        }
        while (word1 != word2)
        {
            word1 = path[word1];
            word2 = path[word2];
        }
        if (word1 == -1)
        {
            cout << word1;
        }
        else
        {
            string str;
            str = to_string(word1);
            int leng = str.size();
            for (int i = 0; i < 5 - leng; i++)
            {
                cout << '0';
            }
            cout << str;
        }
    }

    return 0;
}