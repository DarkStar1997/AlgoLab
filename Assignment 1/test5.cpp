#include <iostream>
#include <algorithm>
#include <vector>
#include <optional>
#include <tuple>
std::optional<int> find(const std::vector<int> &a, int n, const std::vector<int> &b, int m)
{
    int min_index = 0, max_index = n, i, j;
     
    while (min_index <= max_index)
    {
        i = (min_index + max_index) / 2;
        j = ((n + m + 1) / 2) - i;
        if (i < n && j > 0 && b[j - 1] > a[i])        
            min_index = i + 1;
        else if (i > 0 && j < m && b[j] < a[i - 1])        
            max_index = i - 1;        
        else
        {
            if (i == 0)            
                return std::optional<int>{b[j - 1]};
            if (j == 0)            
                return std::optional<int>{a[i - 1]};            
            else           
                return std::max(a[i - 1], b[j - 1]);
        }
    }
    return {};
}
int main()
{
    int n; std::cin>>n;
    std::vector<int> a(n);
    for(auto& i : a)
        std::cin>>i;
    std::cin>>n;
    std::vector<int> b(n);
    for(auto& i : b)
        std::cin>>i;
    std::optional<int> ans = find(a, a.size(), b, b.size());
    if(ans.has_value())
        std::cout<<ans.value()<<'\n';
    else
        std::cout<<"Error!!!\n";
}