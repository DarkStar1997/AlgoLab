#include <iostream>
#include <vector>
#include <tuple>
int main()
{
	int m, n; std::cin>>m>>n;
	std::vector<std::vector<int>> arr(m, std::vector<int>(n));
	for(auto& i:arr)
		for(auto& j:i)
			std::cin>>j;
	std::cout<<"Enter the element to be searched\n";
	int x; std::cin>>x;
	auto[low, high, flag] = std::make_tuple(0, m*n-1, false);
	while(low <= high)
	{
		auto mid = low + (high - low) / 2;
		if(arr[mid/n][mid%n] == x)
		{
			flag = true;
			std::cout<<"Element found at position: "<<(mid/n)+1<<","<<(mid%n)+1<<'\n';
			break;
		}
		else if(x < arr[mid/n][mid%n])
			high = mid - 1;
		else
			low = mid + 1;
	}
	if(!flag)
		std::cout<<"Element not found!!!\n";
}
