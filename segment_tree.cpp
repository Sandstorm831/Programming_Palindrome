#include <bits/stdc++.h>
using namespace std;
void updatevalue(vector<int>& segmentree, int index, int rinitial, int rfinal, int current, int adder)
{
    if(index < rinitial || index > rfinal) return;
    segmentree[current] += adder;
    if(rinitial != rfinal)
    {
        int mid = (rinitial+rfinal)/2;
        updatevalue(segmentree, index, rinitial, mid, 2*current+1, adder);
        updatevalue(segmentree, index, mid+1, rfinal, 2*current+2, adder);
    }

}
void updatevaluehelper(vector<int>& segmentree, vector<int>& original, int size, int index, int new_value)
{
    if(index<0 || index>size-1) return;
    int value_changed = new_value - original[index];
    original[index] = new_value;
    updatevalue(segmentree, index, 0, size-1, 0, value_changed);
}
int getsum(int qinitial, int qfinal, vector<int> segmentree,int rinitial,int rfinal, int current)
{
    if(qinitial<= rinitial && qfinal >= rfinal) return segmentree[current];
    if(qfinal < rinitial || qinitial > rfinal) return 0;
    int mid = (rinitial+rfinal)/2;
    return getsum(qinitial, qfinal, segmentree, rinitial, mid, 2*current+1) + getsum(qinitial, qfinal, segmentree, mid+1, rfinal, 2*current+2);
}
int getsumhelper(int qinitial, int qfinal, vector<int> segmentree, int size)
{
    if(qinitial < 0 || qinitial>qfinal || qfinal > size-1) return -1;
    return getsum(qinitial, qfinal,segmentree, 0, size-1, 0);
}
int constructsegmentutil(vector<int> aray, int initial, int final, vector<int>& segmentree, int currnt)
{
    if(initial == final)
    {
        segmentree[currnt] = aray[final];
        return aray[final];
    }
    int mid = (initial+final)/2;
    segmentree[currnt] = constructsegmentutil(aray, initial, mid, segmentree, 2*currnt+1) + constructsegmentutil(aray, mid+1, final, segmentree, 2*currnt+2);
    return segmentree[currnt];
}
vector<int> contructsegmentree(vector<int> vec, int size)
{
    // height of segment tree
    int x = (int)(ceil(log2(size)));
    // max size of segment tree
    int max_size = 2*(int)pow(2,x)-1;
    vector<int> segmentree(max_size);
    constructsegmentutil(vec, 0, size-1, segmentree, 0);
    return segmentree;
}
int main()
{
    vector<int> vec = {5,3,2,6,1,4};
    int size = vec.size();
    vector<int> catcher = contructsegmentree(vec, size);
    for (int i = 0; i < catcher.size(); i++)
    {
        cout<<catcher[i]<<" ";
    }
    cout<<endl;
    int sum = getsumhelper(1,2,catcher, size);
    cout<<sum<<endl;
    updatevaluehelper(catcher, vec, size, 2, 4);
    for (int i = 0; i < catcher.size(); i++)
    {
        cout<<catcher[i]<<" ";
    }
}