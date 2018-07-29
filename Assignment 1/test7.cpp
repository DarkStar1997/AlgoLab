#include <iostream>
#include <vector>
int find(std::vector<int> &arr, int low, int high, int diff)
{
	int mid = (low + high) / 2;
	if((arr[mid+1] - arr[mid]) != diff)
		return arr[mid]+diff;
	if(mid != 0 && arr[mid] - arr[mid-1] != diff)
		return arr[mid-1]+diff;
	if(arr[mid] == arr[0] + diff*mid)
		return find(arr, mid+1, high, diff);
	return find(arr, low, mid-1, diff);
}
int main()
{
	int n; std::cin>>n;
	std::vector<int> arr(n);
	for(auto& i:arr)
		std::cin>>i;
	std::cout<<find(arr, 0, n-1, (arr[n-1] - arr[0])/n)<<'\n';
}
