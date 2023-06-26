#include <bits/stdc++.h>
using namespace std;
class disjiontSet{
    vector<int> elder;
    vector<int> rank;
    int n;
    public:
    disjiontSet(int a)
    {
        elder.resize(a);
        rank.resize(a,0);
        n = a;
        setter();
    }
    void setter()
    {
        for (int i = 0; i < n; i++)
        {   
            elder[i] = i;
        }
    }
    int find(int x)
    {
        if(elder[x] == x) return elder[x];
        elder[x] = find(elder[x]);
        return elder[x];
    }
    void Union(int x, int y)
    {
        int elder_a = find(x);
        int elder_b = find(y);
        if(elder_a == elder_b) return;
        else if(rank[elder_a]>rank[elder_b]) elder[elder_b] = elder_a;
        else if(rank[elder_a]<rank[elder_b]) elder[elder_a] = elder_b;
        else if(rank[elder_a] == rank[elder_b])
        {
            elder[elder_a] = elder_b;
            rank[elder_b]++;
        }
    }

};
int main()
{
    disjiontSet obj(5);
    obj.Union(0,2);
    obj.Union(4,2);
    obj.Union(3,1);
    if (obj.find(4) == obj.find(0)) cout << "Yes\n";
    else cout << "No\n";
    if (obj.find(1) == obj.find(0)) cout << "Yes\n";
    else cout << "No\n";
}
