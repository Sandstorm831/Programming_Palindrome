#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    string s;
    int a = 0;
    getline(cin, s);
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '4' || s[i] == '7')
        {
            a += 1;
        }
        else
        {
            a += 0;
            break;
        }
        
    }
    int t = stoi(s);
    */
    int t;
    cin >> t;
    if (t % 4 == 0 || t % 7 == 0 || t % 44 == 0 || t % 47 == 0 || t % 74 == 0 || t % 77 == 0 || t % 444 == 0 || t % 447 == 0 || t % 474 == 0 || t % 477 == 0 || t % 744 == 0 || t % 747 == 0|| t % 774 == 0 || t % 777 == 0)
    {
        cout << "YES";
    }
    /*
    else if (a == l)
    {
        cout<<"YES";
    }
    */
    else
    {
        cout << "NO";
    }
}