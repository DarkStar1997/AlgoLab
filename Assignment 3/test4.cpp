#include <iostream>
#include <vector>
int inf = 1;
int min(std::vector<int> &&arr)
{
	int ans = arr[0];
	for(int i = 1; i < arr.size(); i++)
		if(ans > arr[i])
			ans = arr[i];
	return ans;
}
int find(std::vector<std::vector<int>> &arr, int m, int n)
{
	if(m < 0 || n < 0)
		return inf;
	if(m == 0 && n == 0)
		return arr[m][n];
	return arr[m][n] + min({find(arr, m-1, n-1), find(arr, m-1, n), find(arr, m, n-1)});
}
int main()
{
	int m, n;
	std::cin>>m>>n;
	std::vector<std::vector<int>> arr(m, std::vector<int>(n));
	for(auto& i : arr)
		for(auto& j : i)
		{
			std::cin>>j;
			inf += j;
		}
	std::cout<<"Enter the position\n";
	std::cout<<inf<<'\n';
	int x, y; std::cin>>x>>y;
	std::cout<<find(arr, x-1, y-1)<<'\n';
}
