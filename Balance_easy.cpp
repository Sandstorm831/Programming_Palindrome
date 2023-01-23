#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long qrs;
    cin >> qrs;
    set<long long> ust;
    map<long long, long long> store;
    for (long long i = 0; i < qrs; i++)
    {
        char x;
        cin >> x;
        if (x == '+')
        {
            long long a;
            cin >> a;
            ust.insert(a);
        }
        else if (x == '?')
        {
            long long a;
            cin >> a;
            if (store.find(a) == store.end())
            {
                bool u = true;
                long long l = 1;
                while (u)
                {
                    long long fi = l * a;
                    if (ust.find(fi) == ust.end())
                    {
                        cout << fi << endl;
                        store[a] = fi;
                        u = false;
                    }
                    else
                        l++;
                }
            }
            else
            {
                long long fi = store[a];
                if (ust.find(fi) == ust.end())
                    cout << fi << endl;
                else
                {
                    bool u = true;
                    long long l = int(fi / a) + 1;
                    while (u)
                    {
                        long long fi = l * a;
                        if (ust.find(fi) == ust.end())
                        {
                            cout << fi << endl;
                            store[a] = fi;
                            u = false;
                        }
                        else
                            l++;
                    }
                }
            }
        }
    }
}