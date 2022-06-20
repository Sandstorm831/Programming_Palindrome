// Problem Link - https://www.interviewbit.com/problems/count-and-say/hints/
/* Problem Solution Function -----------------------------------+
string Solution::countAndSay(int A) {           <---------------+
    string counter = "1";
    for (int i = 0; i < A-1; i++)
    {
        int number = 0; int derek = counter[0]-48;
        int numeral_counter = 0;
        string giver = "";
        while(numeral_counter < counter.size())
        {
            if(counter[numeral_counter]-48 == derek)
            {
                number ++;
            }
            else
            {
                giver += number+48;
                giver += derek+48;
                derek = counter[numeral_counter]-48;
                number = 1;
                
            }
            numeral_counter++;
        }
        giver += number+48;
        giver += derek+48;
        counter = giver;
    }
    return counter;
}

*/
#include <bits/stdc++.h>
using namespace std;
string counSay(int A)
{
    string counter = "1";
    for (int i = 0; i < A-1; i++)
    {
        int number = 0; int derek = counter[0]-48;
        int numeral_counter = 0;
        string giver = "";
        while(numeral_counter < counter.size())
        {
            if(counter[numeral_counter]-48 == derek)
            {
                number ++;
            }
            else
            {
                giver += number+48;
                giver += derek+48;
                derek = counter[numeral_counter]-48;
                number = 1;
                
            }
            numeral_counter++;
        }
        giver += number+48;
        giver += derek+48;
        counter = giver;
    }
    return counter;
}
int main()
{
    cout<<counSay(35);
}