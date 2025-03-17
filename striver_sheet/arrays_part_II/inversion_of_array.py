# Coding Ninjas Solution
# Link : https://www.codingninjas.com/codestudio/problems/count-inversions_615
# Inspired by Merge sort

def merger(arr, low, mid, high):
    temp = []
    counter = 0
    i = low
    j = mid+1
    while i<=mid:
        while j <= high and i <= mid:
            if arr[j] >= arr[i]:
                counter += j-(mid+1)
                i+=1
            else:
                j+=1

        if j == high+1 and arr[j-1] < arr[i] :
            counter += high - (mid+1) + 1
            i+=1
    
    i = low
    j = mid+1
    while i<=mid:
        while j <= high:
            if i>mid:
                temp.append(arr[j])
                j+=1
                continue
            elif arr[i] <= arr[j]:
                temp.append(arr[i])
                i+=1
            elif arr[i] > arr[j]:
                temp.append(arr[j])
                j+=1
        if j>high and i<=mid :
            temp.append(arr[i])
            i+=1

    for x in range(low, high+1):
        arr[x] = temp[x - low]

    return counter
            
    
def mergeSorter(arr, low, high):
    if high <= low:
        return 0
    mid = (low + high) // 2
    a = mergeSorter(arr, low, mid)
    b = mergeSorter(arr, mid+1, high)
    c = merger(arr, low, mid, high)
    return a+b+c

def getInversions(arr, n):
    # write your code here !!
    xx = mergeSorter(arr,0,n-1)
    return xx

