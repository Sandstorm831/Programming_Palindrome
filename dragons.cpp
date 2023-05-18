#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int brr[], int n)
{
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swap(brr[i], brr[i + 1]);
        }
    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, brr, n - 1);
}

int main()
{
    int power, dragons;
    cin >> power >> dragons;
    int arr[dragons], brr[dragons];
    for (int i = 0; i < dragons; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = a;
        brr[i] = b;
    }
    bubbleSort(arr, brr, dragons);
    for (int i = 0; i < dragons; i++)
    {
        if (arr[i] >= power)
        {
            cout << "NO";
            break;
        }
        else
        {
            power += brr[i];
            if (i + 1 == dragons)
            {
                cout << "YES";
            }
        }
    }
}