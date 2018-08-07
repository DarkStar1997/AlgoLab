#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
template<typename T, typename Comp>
int partition(std::vector<T> &arr, int low, int high, Comp cmp)
{
    auto [pivot, i] = std::make_pair(arr[high], low-1);
    for(int j = low; j < high; j++)
        if(cmp(arr[j], pivot))
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}
template<typename T, typename Comp>
void sort(std::vector<T> &arr, int low, int high, Comp cmp)
{
    if(low < high)
    {
        int x = partition(arr, low, high, cmp);
        sort(arr, low, x-1, cmp);
        sort(arr, x+1, high, cmp);
    }
}
int main()
{
    int m, n; std::cin>>m>>n;
    std::vector<std::vector<int>> arr(m, std::vector<int>(n));
    for(auto& i : arr)
        for(auto& j : i)
            std::cin>>j;
    for(int i = 0; i < m; i++)
        sort(arr[i], 0, arr[i].size()-1, std::less<int>());
    std::cout<<"The sorted 2D array is:\n";
    for(auto& i : arr)
    {
        for(auto& j : i)
            std::cout<<j<<' ';
        std::cout<<'\n';
    }
}