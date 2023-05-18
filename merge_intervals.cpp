// que link - https://www.interviewbit.com/problems/merge-intervals/

// solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int s = newInterval.start;
    int e = newInterval.end;
    int ss, ee;
    int i;
    int sp;
    for(i=0; i<intervals.size(); i++)
    {
        Interval xx = intervals[i];
        if(s >= xx.start && s <= xx.end)
        {
            ss = xx.start;
            sp=1;
            break;
        }   
        else if(s < xx.start)
        {
            ss = s;
            sp=0;
            break;
        }
    }
    int j;
    for(j=i+sp; j<intervals.size(); j++)
    {
        if(e < intervals[j].start)
        {
            ee = e;
            break;
        }
        else if(e > intervals[j].start && e < intervals[j].end)
        {
            ee = intervals[j].end;
            j++;
            break;
        }
    }
    vector<Interval> vv;
    for(int k=0; k<i; k++)
    {
        vv.push_back(intervals[k]);
    }
    vv.push_back(Interval(ss,ee));
    for(int k=j; k<intervals.size(); k++)
    {
        vv.push_back(intervals[k]);
    }
    return vv;
}