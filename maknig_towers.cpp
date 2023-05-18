#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> p(n + 1, vector<int>());
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            p[a].push_back(j);
        }
        vector<int> count;
        for (int j = 1; j < p.size(); j++)
        {
            int counter = 0;
            int x = p[j].size();
            for (int k = 0; k < x - 1; k++)
            {
                if ((p[j][k + 1] - p[j][k]) % 2 == 1)
                    counter++;
            }
            if (p[j].size() >= 1)
                counter++;
            count.push_back(counter);
        }
        for (int j = 0; j < count.size(); j++)
        {
            cout << count[j] << " ";
        }
        cout << endl;
    }
}