// Problem Link - https://www.interviewbit.com/problems/square-root-of-integer/
#include <bits/stdc++.h>
using namespace std;
int squart(int A){
    long int zameen = 0;
    long int akaash = (long int)A;
    while (akaash-zameen>0)
    {
        long int beechka = (akaash+zameen)/2;
        if(beechka*beechka == (long int)A) return beechka;
        else if(beechka*beechka > (long int)A) akaash = beechka-1;
        else zameen = beechka+1;
    }
    if(zameen*zameen <= (long int)A ) return zameen;
    else return zameen-1;
}