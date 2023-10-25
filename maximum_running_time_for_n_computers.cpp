// Question Link - https://leetcode.com/problems/maximum-running-time-of-n-computers/description/
// solution 

/* AdHoc approach

**Intuition**

The staright idea, is to use all baterial evenly.
So we take advantage of all the energy wihout any left.
In this case, we can run up to sum(A) / n minutes.
This average value is an upper bounde of the final result.
It's great to start with this enviromental intuition.


**Explanation**

However, there may be some betteries that has too much energy.
They are in charge all the time,
but still can't run out all they have,
then their energy wastes.

So we can compare the average value with the most powerful battery max(A).
If max(A) is bigger, then we can use this battery to charge a computer all the time.
Now we reduce the problem to the left bettery and n - 1 computers.

We continue doing this process,
until the most powerful bettery max(A) can not run average time sum(A) / n.
Then the left betteries can help each other and be use evenly until the end.
One key point of this problem, it's to find out, why betteries can be used "evenly" in this situation.

One quick "prove" is that, the max(A) is smaller than the running time,
so the maximum battery won't get wasted,
the other smaller betteries won't even get easted.

*/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        long long summ = accumulate(batteries.begin(), batteries.end(), 0ll);
        int k=0, nb = batteries.size();
        while(batteries[nb-1-k] > summ/(n-k)) summ -= batteries[nb-1-k++];
        return summ/(n-k);
    }


/*
**Solution using binary search**
The idea is to check if we can run computers for m hours (n * m total hours). For that, we accumulate power from all batteries, taking no more than m from each. If we have enough power for n * m hours - we can run all our computers for m hours.
*/


    long long maxxRunTime(int n, vector<int>& batteries)
    {
        long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0ll);
        while(l<r)
        {
            long long m = (l+r+1)/2, counter=0;
            for(int i=0; i<batteries.size();i++)
            {
                if(batteries[i]>=m) counter+=m;
                else counter+=1ll*batteries[i];
            }
            if(counter >= n*m) l = m;
            else r = m-1;
        }
        return l;
    }
};