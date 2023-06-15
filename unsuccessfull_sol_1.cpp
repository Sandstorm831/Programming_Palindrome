// Problem Link - https://www.interviewbit.com/problems/maximal-string/
// Maximal string 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pseudo = "129814999";
    int swaps = 4;
    int real = stoi(pseudo);
    vector<int> digits;
    while (real>0)
    {
        int remainder = real%10;
        digits.push_back(remainder);
        real = real/10;
    }
    for (int i = 0; i < digits.size(); i++)
    {
        cout<<digits[i]<<" ";
    }
    cout<<endl;
    vector<int> copy = digits;
    vector<int> digits_reverse;
    vector<int> copy_reverse_copy = digits;
    int swaps_reverse = swaps;
    for (int i = 1; i <= digits.size(); i++)
    {
        digits_reverse.push_back(digits[digits.size() - i]);
    }
    for (int i = 0; i < digits_reverse.size(); i++)
    {
        cout<<digits_reverse[i]<<" ";
    }
    cout<<endl;
    sort(copy.begin(), copy.end());
    sort(copy_reverse_copy.begin(), copy_reverse_copy.end());
    for (int i = 0; i < copy.size(); i++)
    {
        cout<<copy[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < copy_reverse_copy.size(); i++)
    {
        cout<<copy_reverse_copy[i]<<" ";
    }
    cout<<endl;

    for (int l = 0; l < swaps; l++)
    {
        auto it = find(digits.begin(), digits.end(), copy[copy.size() - 1]);
        int bigd = it-digits.begin();
        cout<<bigd<<endl;
        if (digits[bigd] == digits[digits.size()-1-l]){
            cout<<"number of swaps :"<<swaps<<endl;
            swaps++;
            cout<<"number of swaps :"<<swaps<<endl;
        }
        int swap = digits[digits.size() - 1-l];
        digits[digits.size()-1-l] = digits[bigd];
        digits[bigd] = swap;
        copy.pop_back();
        /*
        for (int i = 0; i < copy.size(); i++)
        {
            cout<<copy[i]<<" ";
        }
        */
        for (int i = 0; i < digits.size(); i++)
        {
            cout<<digits[i]<<" ";
        }
        cout<<endl;
    }

    for (int l = 0; l < swaps_reverse; l++)
    {
        auto iti = find(digits_reverse.begin()+l, digits_reverse.end(), copy_reverse_copy[copy_reverse_copy.size() - 1]);
        int bigd = iti-digits_reverse.begin();
        cout<<bigd<<endl;
        if (digits_reverse[bigd] == digits_reverse[l]){
            cout<<"number of swaps_reverse :"<<swaps_reverse<<endl;
            swaps_reverse++;
            cout<<"number of swaps_reverse :"<<swaps_reverse<<endl;
        }
        int swap_reverse = digits_reverse[l];
        digits_reverse[l] = digits_reverse[bigd];
        digits_reverse[bigd] = swap_reverse;
        copy_reverse_copy.pop_back();
        /*
        for (int i = 0; i < copy.size(); i++)
        {
            cout<<copy[i]<<" ";
        }
        */
        for (int i = 0; i < digits_reverse.size(); i++)
        {
            cout<<digits_reverse[i]<<" ";
        }
        cout<<endl;
    }
    
    string final = "";
    string final_reverse = "";
    
    for (int i = 1; i <= digits.size(); i++)
    {
        final += to_string(digits[digits.size()-i]);
    }
    for (int i = 0; i < digits_reverse.size(); i++)
    {
        final_reverse += to_string(digits_reverse[i]);
    }
    if (stoi(final) <= stoi(final_reverse))
    {
        cout<<final_reverse;
    }
    else
    {
        cout<<final;
    }
    cout<<endl<<final<<" "<<final_reverse;
}