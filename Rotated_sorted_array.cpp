#include <bits/stdc++.h>using namespace std;

int search(vector<int> A, int B)
{

    int low = 0,
        high = A.size() - 1;
    int mid = (low + high) / 2;

    while (high >= low)
    {
        mid = (low + high) / 2;

        if (A[mid] == B)
        {
            return mid;
        }

        else if (A[mid] > A[low])
        {
            if (B >= A[low] && B < A[mid])
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        else
        {
            if (A[mid] < B && B <= A[high])
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {
        180,
        181,
        182,
        183,
        3,
        4,
        5,
        6,
        7,
        8}

    ;
    cout << search(A, 182);
}