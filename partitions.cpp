// que link - https://www.interviewbit.com/problems/partitions/

// solution
int Solution::solve(int A, vector<int> &B) {
    if(B.size()<3) return 0;
    vector<int> v;
    int summ=0;
    for(int i=0; i<B.size(); i++)
    {
        summ += B[i];
    }
    if(summ%3 != 0) return 0;
    summ = summ/3;
    int sumer=B[0];
    int i=0;
    while(sumer!=summ && i<A)
    {
        i++;
        sumer+=B[i];
    }
    if(i>=A) return 0;
    int j=A-1;
    sumer=B[A-1];
    while(sumer!=summ && j>=A)
    {
        j--;
        sumer+=B[j];
    }
    if(j<0) return 0;
    int counter=0;
    int altcounter=0;
    int comp=0;
    bool t=false;
    for(int k=i+1; k<j; k++)
    {
        comp += B[k];
        if(summ != 0 && comp%summ == 0) 
        {
            if(comp==summ) t=false;
            if(t && comp==0) counter++;
            else altcounter++;
        }
        else if(summ == 0 && comp == 0) counter++;
    }
    if(summ!=0) return (counter+1)*(altcounter);
    else return ((counter+1)*(counter))/2;
}