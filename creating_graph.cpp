#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graphcompiler(vector<pair<int,int>> det, int nodes)
{
    vector<list<int>> graph(nodes+1);
    for (int i = 0; i < det.size(); i++)
    {
        graph[det[i].first].push_back(det[i].second);
    }
    return graph;
}
int main()
{
    vector<pair<int,int>> det;
    det.push_back(make_pair(1,2));
    det.push_back(make_pair(2,1));
    det.push_back(make_pair(4,2));
    det.push_back(make_pair(2,4));
    det.push_back(make_pair(1,4));
    det.push_back(make_pair(4,1));
    det.push_back(make_pair(1,5));
    det.push_back(make_pair(5,1));
    det.push_back(make_pair(4,5));
    det.push_back(make_pair(5,4));
    det.push_back(make_pair(5,3));
    det.push_back(make_pair(3,5));
    vector<list<int>> mo = graphcompiler(det, 5);
}