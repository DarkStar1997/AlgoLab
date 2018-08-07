#include <iostream>
#include <vector>
void countSort(std::vector<int> &arr, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(std::vector<int> &arr, int n)
{
    int m = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > m)
            m = arr[i];
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
int main()
{
    int n; std::cin>>n;
    std::vector<int> arr(n);
    for(auto& i : arr)
        std::cin>>i;
    radixsort(arr, n);
    for(const auto& i : arr)
        std::cout<<i<<' ';
    std::cout<<'\n';
    return 0;
}