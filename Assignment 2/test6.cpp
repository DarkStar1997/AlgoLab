#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int n; std::cin>>n;
    std::vector<int> arr(n);
    for(auto& i : arr)
        std::cin>>i;
    int k; std::cin>>k;
    std::make_heap(arr.begin(), arr.begin()+k, [](const int &x, const int &y){return x>y;});
    for(int i = k; i < n; i++)
        if(arr[i]>arr[0])
        {
            arr[0] = arr[i];
            std::make_heap(arr.begin(), arr.begin()+k, [](const int &x, const int &y){return x>y;});
        }
    std::cout<<arr[0]<<'\n';
}