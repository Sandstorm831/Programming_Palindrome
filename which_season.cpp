// Problem Link - https://www.interviewbit.com/problems/which-season/
#include <bits/stdc++.h>
using namespace std;
string solve(int A) {
    if(A > 12) return "Invalid";
    else if(A >= 1 && A <= 2) return "Winter";
    else if(A >= 3 && A <= 5) return "Spring";
    else if(A >= 6 && A<= 8) return "Summer";
    else if(A>=9 && A<= 11) return "Autumn";
    else return "Winter";    
}
int main()
{}