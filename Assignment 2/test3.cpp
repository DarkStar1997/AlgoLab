#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
std::optional<int> kth(int *arr1, int m, int *arr2, int n, int k)
{
    if (k > (m+n) || k < 1) 
        return {};
    if (m > n) 
        return kth(arr2, n, arr1, m, k);

    if (m == 0) 
        return arr2[k - 1];
    
    if (k == 1) 
        return std::min(arr1[0], arr2[0]);

    int i = std::min(m, k / 2), j = std::min(n, k / 2);

    if (arr1[i - 1] > arr2[j - 1] )
        return kth(arr1, m, arr2 + j, n - j, k - j);
    else
        return kth(arr1 + i, m - i, arr2, n, k - i);
}
int main()
{
    int m, n, k;
    std::cin>>m;
    std::vector<int> arr1(m);
    for(auto& i : arr1)
        std::cin>>i;
    std::cin>>n;
    std::vector<int> arr2(n);
    for(auto& i : arr2)
        std::cin>>i;
    std::cin>>k;     
    std::optional<int> ans = kth(arr1.data(),m,arr2.data(), n, k);

    if(!ans.has_value())
        std::cout<<"Invalid query\n";
    else 
        std::cout<<ans.value()<<'\n';
     
    return 0;
}