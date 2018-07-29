#include <vector>
#include <iostream>
int main()
{
	int n; std::cin>>n;
	std::vector<bool> check(1000, false);
	std::vector<int> arr(n);
	for(int i = 0; i < n; i++)
	{
		std::cin>>arr[i];
		check[arr[i]] = true;
	}
	int x; std::cin>>x; bool flag = false;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] <= x)
		{
			int y = x - arr[i];
			if(check[y])
			{
				std::cout<<arr[i]<<","<<y<<'\n';
				flag = true; break;
			}
		}
	}
	if(!flag)
		std::cout<<"No such pair found!!!\n";
}
