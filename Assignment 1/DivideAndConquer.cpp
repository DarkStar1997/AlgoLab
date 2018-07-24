#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
template<typename T, typename Comp>
void merge(std::vector<T> &arr, int low, int mid, int high, Comp cmp)
{
    mid = low + (high - low) / 2; int len1, len2, i, j, k;
    std::tie(len1, len2) = std::make_pair(std::min(2, mid - low + 1), std::min(2, high - mid));
    std::vector<T> left(arr.begin() + low, arr.begin() + low + len1);
    std::vector<T> right(arr.begin() + mid + 1, arr.begin() + mid + 1 + len2);
    std::tie(i, j, k) = std::make_tuple(0, 0, low);
    while(i < len1 && j < len2)
        if(cmp(left[i], right[i]))
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    while(i < len1)
        arr[k++] = left[i++];
    while(j < len2)
        arr[k++] = right[j++];
}
template<typename T, typename Comp>
void sort(std::vector<T> &arr, int low, int high, Comp cmp)
{
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        sort(arr, low, mid, cmp);
        sort(arr, mid+1, high, cmp);
        merge(arr, low, mid, high, cmp);
    }
}
int main()
{
    std::vector<int> arr = {std::istream_iterator<int>(std::cin), std::istream_iterator<int>()};
    sort<int>(arr, 0, arr.size() - 1, [](int x, int y){return x>y;});
    std::cout<<"Sorted array:\n";
    std::for_each(arr.begin(), arr.end(), [](const int &x){std::cout<< x << '\n';});
}