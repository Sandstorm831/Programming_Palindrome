#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vowel;
    string alph;
    getline(cin, alph);
    int l = alph.length();
    for (int i = 0; i < l; i++)
    {
        int c = alph[i];
        if (isupper(c))
        {
            alph[i] = tolower(c);
        }
        
    }
    for (int i = 0; i < l; i++)
    {
        if(alph[i]=='a'||alph[i]=='e'||alph[i]=='i'||alph[i]=='o'||alph[i]=='u'||alph[i]=='y')
		{
            vowel++;
		    
		    //Deleting vowels. 
			for(int j=i; j<l; j++)
			{
			    //Storing string without vowels.
				alph[j]=alph[j+1];
			}
		i--;
		l--;
		}

    }
    alph.shrink_to_fit();
    for (int i = 0; i < l-vowel; i++)
    {
        cout<<"."<<alph[i];
    }
    
}