#include <bits/stdc++.h>
using namespace std;
int ans;
void finder(int starter, int maxer, string &text, vector<string> &words, vector<pair<int, int>> &match)
{
    int maxx = 0, id = -1, pos = -1;
    for (int i = starter; i <= maxer; i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            string word = words[j];
            if (i + word.length() > text.length() || i + word.length() <= maxer)
                continue;
            else if (text.substr(i, word.size()) == word)
            {
                if (i + word.length() > maxx)
                {
                    maxx = i + word.length();
                    id = j;
                    pos = i;
                }
            }
        }
    }
    if (id == -1)
    {
        ans = -1;
        return;
    }
    else
    {
        match.push_back(make_pair(pos, id));
        ans++;
        if (maxx == text.length())
            return;
        else
            finder(starter + 1, maxx, text, words, match);
    }
}
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        ans = 0;
        string text;
        cin >> text;
        int n;
        cin >> n;
        vector<string> words;
        vector<pair<int, int>> match;
        for (int j = 0; j < n; j++)
        {
            string st;
            cin >> st;
            words.push_back(st);
        }
        finder(0, 0, text, words, match);
        if (ans == -1)
        {
            cout << -1<<endl;
            continue;
        }
        else
        {
            cout << ans << endl;
            for (int j = 0; j < ans; j++)
            {
                cout << match[j].second + 1 << " " << match[j].first + 1 << endl;
            }
        }
    }
}
