// Problem Link - https://www.interviewbit.com/problems/lru-cache/
/* Problem Solution Function --------------+
#include <list>         <------------------+
list<pair<int,int>> dq;
unordered_map<int, list<pair<int,int>>::iterator> mp;
int cache_cap;

LRUCache::LRUCache(int capacity)
{
    dq.clear();
    mp.clear();
    cache_cap = capacity;
}
int LRUCache::get(int key)
{
    if(mp.find(key) == mp.end()) return -1;
    int value = (*mp[key]).second;
    dq.erase(mp[key]);
    dq.push_front({key, value});
    mp[key] = dq.begin();
    return value;
}
void LRUCache::set(int key, int value)
{
    if(mp.find(key) == mp.end())
    {
        if(cache_cap == dq.size())
        {
            int keyy = (dq.back()).first;
            dq.pop_back();
            mp.erase(keyy);
        }
    }
    else{
        dq.erase(mp[key]);
    }
    dq.push_front({key, value});
    mp[key] = dq.begin();
}
*/