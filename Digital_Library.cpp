#include <algorithm>
#include <iostream>
#include <vector>
#include<string>

using namespace std;

struct Book
{
    string id;
    string title;
    string author;
    vector<string> key;
    string publish;
    string year;
};

bool cmp(Book a, Book b)
{
    return a.id < b.id;
}

int main()
{
    int n;
    cin >> n;
    vector<Book> book(n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, book[i].id);
        getline(cin, book[i].title);
        getline(cin, book[i].author);
        getline(cin, temp);
        getline(cin, book[i].publish);
        getline(cin, book[i].year);
        string str;
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == ' ')
            {
                book[i].key.push_back(str);
                str.clear();
            }
            else
            {
                str += temp[j];
            }
        }
        book[i].key.push_back(str);
    }
    sort(book.begin(), book.end(), cmp);
    int k;
    cin >> k;
    getchar();
    for (int i = 0; i < k; i++)
    {
        string temp1, temp2, temp;
        getline(cin, temp);
        for (int i = 0; i < temp.size(); i++)
        {
            if (i<2)
            {
                temp1 += temp[i];
            }
            else if(i>2)
            {
                temp2 += temp[i];
            }
        }
        cout << temp1 << " " << temp2 << endl;
        if (temp1[0] == '1')
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (book[i].title == temp2)
                {
                    cout << book[i].id << endl;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "Not Found" << endl;
            }
        }
        else if (temp1[0] == '2')
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (book[i].author == temp2)
                {
                    cout << book[i].id << endl;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "Not Found" << endl;
            }
        }
        else if (temp1[0] == '3')
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < book[i].key.size(); j++)
                {
                    if (book[i].key[j] == temp2)
                    {
                        cout << book[i].id << endl;
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
            {
                cout << "Not Found" << endl;
            }
        }
        else if (temp1[0] == '4')
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (book[i].publish == temp2)
                {
                    cout << book[i].id << endl;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "Not Found" << endl;
            }
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (book[i].year == temp2)
                {
                    cout << book[i].id << endl;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "Not Found" << endl;
            }
        }
    }

    return 0;
}