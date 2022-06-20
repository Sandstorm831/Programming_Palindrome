// Problem Link - https://www.interviewbit.com/problems/convert-the-amount-in-number-to-words/
#include <bits/stdc++.h>
using namespace std;
string one[] = {"", "one-", "two-", "three-", "four-",
                "five-", "six-", "seven-", "eight-",
                "nine-", "ten-", "eleven-", "twelve-",
                "thirteen-", "fourteen-", "fifteen-",
                "sixteen-", "seventeen-", "eighteen-",
                "nineteen-"};

string ten[] = {"", "", "twenty-", "thirty-", "forty-",
                "fifty-", "sixty-", "seventy-", "eighty-",
                "ninety-"};

string numToWords(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];

    // if n is non-zero
    if (n)
        str += s;

    return str;
}
string convertToWords(int n)
{
    // stores word representation of given number n
    string out;

    // handles digits at ten crore and crore places (if any)
    out += numToWords((n / 10000000), "crore-");

    // handles digits at ten lakh and lakh places (if any)
    out += numToWords(((n / 100000) % 100), "lakh-");

    // handles digits at thousands and tens thousands
    // places (if any)
    out += numToWords(((n / 1000) % 100), "thousand-");

    // handles digit at hundreds places (if any)
    out += numToWords(((n / 100) % 10), "hundred-");

    // we need to add "and" if the number is more than hundred and contains digit at ten's or one's place
    if (n > 100 && n % 100)
        out += "and-";

    // handles digits at ones and tens places (if any)
    out += numToWords((n % 100), "");
    out = out.substr(0, out.size() - 1); // to remove the last trailing "-"
    return out;
}
int solve(string A, string B)
{
    int n = stoi(A);
    string y = convertToWords(n);
    if (y.compare(B) == 0)
        return 1;
    return 0;
}
int main()
{
}