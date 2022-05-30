//Problem Link - https://www.interviewbit.com/problems/pick-from-both-sides/
#include <bits/stdc++.h>
using namespace std;
int max_sum_both_sides(vector<int> A, int B){
    int k=1;
    vector<int> suffix, prefix;
    suffix.push_back(0);
    prefix.push_back(0);
    int size = A.size();
    while (k<=B)
    {
        suffix.push_back(suffix[k-1]+A[k-1]);
        prefix.push_back(prefix[k-1]+A[A.size()-k]);
        k++;
    }
    int max_sum = suffix[B];
    for (int i = 0; i < B; i++)
    {
        if (suffix[i]+prefix[B-i]>max_sum)
        {
            max_sum = suffix[i]+prefix[B-i];
        }
        continue;
    }
    
    return max_sum;
    
}
int main(){
    // This vector has to be assuemd
    vector<int> A = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35};
    int B = 48;
    cout<<max_sum_both_sides(A, B);

}