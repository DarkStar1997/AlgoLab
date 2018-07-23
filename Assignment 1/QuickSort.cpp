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
    std::vector<int> arr = {std::istream_iterator<int>(std::cin), std::istream_iterator<int>()};
    sort<int>(arr, 0, arr.size() - 1, [](int x, int y){return x<y;});
    std::cout<<"Sorted array:\n";
    std::for_each(arr.begin(), arr.end(), [](const int &x){std::cout<< x << '\n';});
}