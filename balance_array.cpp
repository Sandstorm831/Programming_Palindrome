// Question Link - https://www.interviewbit.com/problems/balance-array/
//Solution

int Solution::solve(vector<int> &A) {
    vector<int> ev, od;
    for(int i=0; i<A.size(); i++)
    {
        if(i%2==0)
        {
            ev.push_back(A[i]);
            od.push_back(0);
        }
        else
        {
            ev.push_back(0);
            od.push_back(A[i]);
        }
    }
    vector<int> of, ob, ef, eb;
    int ofx=0, obx=0, efx=0, ebx=0;
    for(int i=0; i<A.size(); i++)
    {
        ofx+=od[i];
        efx+=ev[i];
        of.push_back(ofx);
        ef.push_back(efx);
        obx+=od[A.size()-i-1];
        ebx+=ev[A.size()-i-1];
        ob.push_back(obx);
        eb.push_back(ebx);
    }
    reverse(ob.begin(), ob.end());
    reverse(eb.begin(), eb.end());
    int counter=0;
    for(int i=0; i<A.size(); i++)
    {
        if(i%2==0)
        {
            efx = ef[i]-A[i];
            ebx = eb[i]-A[i];
            if(ebx+of[i] == efx+ob[i]) counter++;
        }
        else
        {
            ofx = of[i]-A[i];
            obx = ob[i]-A[i];
            if(ef[i]+obx == ofx+eb[i]) counter++;
        }
    }
    return counter;
}