// Question Link - https://www.interviewbit.com/problems/fraction/
// Solution 

string Solution::fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        return "0";
    }
    if (denominator == 0) {
        return "";
    }
    string result = "";
    //std::cout << numerator << " " << denominator << endl;
    if ((numerator < 0) ^ (denominator < 0)) {
        //std::cout << "True" << endl;
        result += "-";
    }
    //numerator = abs(numerator);
    //denominator = abs(denominator);
    long num = numerator, den = denominator;
    num = abs(num);
    den = abs(den);
    long res = num/den;
    result += to_string(res);
    
    long rem = (num%den)*10;
    if (rem == 0) {
        return result;
    }
    
    std::map<long, int> mp;
    result += ".";
    while (rem != 0) {
        if (mp.find(rem) != mp.end()) {
            int beg = mp[rem];
            string part1 = result.substr(0,beg);
            string part2 = result.substr(beg, result.length()-beg);
            result = part1 + "("+part2+")";
            return result;
        }
        mp[rem] = result.length();
        res = rem/den;
        result += to_string(res);
        rem = (rem%den) *10;
    }
    return result;
}