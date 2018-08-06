#include <iostream>
#include <vector>
int findMin(const std::vector<int> &arr, int low, int high)
{
    if (high < low)  
        return arr[0];
    if (high == low) 
        return arr[low];

    int mid = low + (high - low)/2;
    
    if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
 
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
    if (arr[high] > arr[mid])
       return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}
int main()
{
    int n; std::cin>>n;
    std::vector<int> arr(n);
    for(auto& i : arr)
        std::cin>>i;
    std::cout<<findMin(arr, 0, n-1)<<'\n';
}