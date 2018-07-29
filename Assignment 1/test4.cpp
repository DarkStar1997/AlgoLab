#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
template<typename Cmp>
int find(std::vector<int> &arr, int &key, Cmp cmp)
{
	auto[low, high, mid, ans] = std::make_tuple(0, arr.size()-1, 0, -1);
	while(low <= high)
	{
		mid = low + (high - low) / 2;
		if(key == arr[mid])
		{
			ans = mid;
			if(cmp(1, 2))
				high = mid - 1;
			else
				low = mid + 1;
		}
		else if(cmp(key, arr[mid]))
		{
			if(cmp(1, 2))
				high = mid - 1;
			else
				low = mid + 1;
		}
		else
		{
			if(cmp(1, 2))
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	return ans;
}
int main()
{
	int n; std::cin>>n;
	std::vector<int> arr(n);
	for(auto& i:arr)
		std::cin>>i;
	std::cout<<"Enter the key to be searched\n";
	int x; std::cin>>x;
	auto[a1, a2] = std::make_tuple(find(arr, x, std::less<int>()), find(arr, x, std::greater<int>()));
	if(a1 == -1 || a2 == -1)
		std::cout<<"Not found!!!\n";
	else
		std::cout<<a2 - a1 + 1<<'\n';
}
