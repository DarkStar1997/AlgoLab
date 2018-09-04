#include <iostream>
#include <vector>
int main()
{
	std::cout<<"Enter the number of available coins\n";
	int n; std::cin>>n;
	std::vector<int> coins(n);
	std::cout<<"Enter the coins\n";
	for(auto& i : coins)
		std::cin>>i;
	std::cout<<"Enter the value\n";
	int val; std::cin>>val;
	std::vector<int> ans(val+1, 0);
	for(const auto& i : coins)
		ans[i] = 1;
	for(int i = 2; i <= val; i++)
	{
		int x = 1 + ans[i - 1];
		for(const auto& c : coins)
			if(c < i)
				x = std::min(x, 1 + ans[i - c]);
		if(ans[i] != 0)
			ans[i] = std::min(ans[i], x);
		else
			ans[i] = x;
	}
	std::cout<<ans[val]<<'\n';
}
