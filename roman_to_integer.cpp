// Question link - https://www.interviewbit.com/problems/roman-to-integer/
// Solution 

string converter(int A)
{
    string s = "";
    while(A>0)
    {
        if(A<=9)
        {
            if(A<=3) 
            {
                for(int i=0; i<A; i++)
                {
                    s+="I";
                }
            }
            else if(A == 4) s += "IV";
            else if(A <= 8)
            {
                s += "V";
                for(int i=0; i<A-5; i++) s+="I";
            }
            else if(A == 9) s+="IX";
            A=0;
        }
        else if(A>=10 && A<=99)
        {
            int q = A/10;
            if(q<=3)
            {
                for(int i=0; i<q; i++)
                {
                    s += "X";
                }
            }
            else if(q==4) s+="XL";
            else if(q<=8)
            {
                s+="L";
                for(int i=0; i<q-5; i++)
                {
                    s+="X";
                }
            }
            else if(q==9) s+="XC";
            A%=10;
        }
        else if(A>=100 && A<=999)
        {
            int q = A/100;
            if(q<=3)
            {
                for(int i=0; i<q; i++)
                {
                    s += "C";
                }
            }
            else if(q==4) s+="CD";
            else if(q<=8)
            {
                s+="D";
                for(int i=0; i<q-5; i++)
                {
                    s+="C";
                }
            }
            else if(q==9) s+="CM";
            A%=100;
        }
        else if(A>=1000 && A<=3999)
        {
            int q = A/1000;
            if(q<=3)
            {
                for(int i=0; i<q; i++) s += "M";
            }
            A%=1000;
        }
    }
    return s;
}
int Solution::romanToInt(string A) {
    for(int i=1; i<=3999; i++)
    {
        if(converter(i) == A) return i;
    }
}
