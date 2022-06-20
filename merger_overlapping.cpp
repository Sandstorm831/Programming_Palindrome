/* Problem Link -   https://www.interviewbit.com/problems/merge-overlapping-intervals/
 * Problem Solution Function ----------------------------------------+
 * Definition for an interval.                                       |               
 * struct Interval {                                                 |
 *     int start;                                                    |   
 *     int end;                                                      |   
 *     Interval() : start(0), end(0) {}                              |   
 *     Interval(int s, int e) : start(s), end(e) {}                  |   
 * };                                                                |   
 *                                                                   |   
 bool mycomp(Interval a,Interval b){        <------------------------+
     return a.start<b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> atease;
    if(A.size() == 0) return atease;
    if(A.size() == 1) return A;
    sort(A.begin(), A.end(), mycomp);
    atease.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        if(atease.back().end < A[i].start) atease.push_back(A[i]);
        else
        {
            atease.back().end = max(atease.back().end, A[i].end);
        }
    }
    return atease;
}
*/
#include <bits/stdc++.h>
using namespace std;
class Interval{
    public:
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool mycomp(Interval a,Interval b){
     return a.start<b.start;
}
vector<Interval> merge(vector<Interval> &A)
{
    vector<Interval> atease;
    if(A.size() == 0) return atease;
    if(A.size() == 1) return A;
    sort(A.begin(), A.end(), mycomp);
    atease.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        if(atease.back().end < A[i].start) atease.push_back(A[i]);
        else
        {
            atease.back().end = max(atease.back().end, A[i].end);
        }
    }
    return atease;
}
int main()
{
    Interval hel1(17, 20); Interval hel2(32, 68); Interval hel3(36, 45); Interval hel4(3, 57); Interval hel5(62, 96); Interval hel6(14, 59);  Interval hel7(60, 80); Interval hel8(40, 42); Interval hel9(35, 40);
    vector<Interval> myvec;
    myvec.push_back(hel1);
    myvec.push_back(hel2);
    myvec.push_back(hel3);
    myvec.push_back(hel4);
    myvec.push_back(hel5);
    myvec.push_back(hel6);
    myvec.push_back(hel7);
    myvec.push_back(hel8);
    myvec.push_back(hel9);
    vector<Interval> answer = merge(myvec);
    for (int i = 0; i < answer.size(); i++)
    {
        cout<<answer[i].start<<" "<<answer[i].end<<endl;
    }
}