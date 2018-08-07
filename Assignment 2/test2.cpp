#include <iostream>
#include <vector>
int merge(std::vector<int> &arr, std::vector<int> temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i=left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}
int count(std::vector<int> &arr, std::vector<int> temp, int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        inv_count  = count(arr, temp, left, mid);
        inv_count += count(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}
int main()
{
    int n; std::cin>>n;
    std::vector<int> arr(n);
    for(auto& i : arr)
        std::cin>>i;
    std::cout<<count(arr, arr, 0, n-1)<<'\n';
    return 0;
}