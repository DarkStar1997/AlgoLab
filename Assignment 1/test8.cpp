#include <iostream>
#include <vector>
int find(std::vector<int> &arr, int low, int high)
{
	int mid = (high + low)/2;
	if(low <= high)
	{
		if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
			return mid;
		else if(arr[mid] < arr[mid+1])
			return find(arr, mid+1, high);
		else
			return find(arr, low, mid-1);
	}
	return mid;
}
int main()
{
	int n; std::cin>>n;
	std::vector<int> arr(n);
	for(auto& i:arr)
		std::cin>>i;
	std::cout<<find(arr, 0, n-1)<<'\n';
}
