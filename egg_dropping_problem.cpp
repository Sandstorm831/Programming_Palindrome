/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
Suppose that we wish to know which stories in a 36-storey building are safe to drop eggs from, and which will cause the eggs to break on landing.
We make a few assumptions:
.....An egg that survives a fall can be used again. 
.....A broken egg must be discarded. 
.....The effect of a fall is the same for all eggs. 
.....If an egg breaks when dropped, then it would break if dropped from a higher floor. 
.....If an egg survives a fall then it would survive a shorter fall. 
.....It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way.
Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks.
In the worst case, this method may require 36 droppings. Suppose 2 eggs are available.
What is the least number of egg-droppings that is guaranteed to work in all cases? 
The problem is not actually to find the critical floor,
but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.
#include <bits/stdc++.h>
*/
using namespace std;
int eggDrop(int eggs, int floors, unordered_map<string, int>& dp)
{
    if(floors == 0 || floors == 1) return floors;
    if(eggs == 1) return floors;
    string fst = to_string(eggs)+"_"+to_string(floors);
    if(dp.find(fst) != dp.end()) return dp[fst];
    int mann = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int time = 1+max(eggDrop(eggs-1, k-1, dp), eggDrop(eggs, floors-k, dp));
        mann = min(time, mann);
    }
    return dp[fst] = mann;
}
int main()
{
    int eggs = 2;
    int floors = 100;
    unordered_map<string,int> dp;
    dp.clear();
    cout<<eggDrop(eggs, floors, dp);
}