#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
template<typename T, int N, typename Comp>
void merge(std::vector<T> &arr, int low, int mid, int high, Comp cmp)
{
    mid = low + (high - low) / 2;
    auto [len1, len2] = std::make_pair(std::min(N, mid - low + 1), std::min(N, high - mid));
    std::vector<T> left(arr.begin() + low, arr.begin() + low + len1);
    std::vector<T> right(arr.begin() + mid + 1, arr.begin() + mid + 1 + len2);
    auto [i, j, k] = std::make_tuple(0, 0, low);
    while(i < len1 && j < len2)
        if(cmp(left[i], right[j]))
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    while(i < len1)
        arr[k++] = left[i++];
    while(j < len2)
        arr[k++] = right[j++];
}
template<typename T, int N, typename Comp>
void sort(std::vector<T> &arr, int low, int high, Comp cmp)
{
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        sort<T, N>(arr, low, mid, cmp);
        sort<T, N>(arr, mid+1, high, cmp);
        merge<T, N>(arr, low, mid, high, cmp);
    }
}
int main()
{
    std::vector<int> arr = {std::istream_iterator<int>(std::cin), std::istream_iterator<int>()};
    auto arr1 = arr;
    sort<int, 2>(arr, 0, arr.size() - 1, [](int x, int y){return x<y;});
    std::cout<<"2nd smallest element is: "<<arr[1]<<'\n';
    sort<int, 2>(arr1, 0, arr1.size() - 1, [](int x, int y){return x>y;});
    std::cout<<"2nd largest element is: "<<arr1[1]<<'\n';
}