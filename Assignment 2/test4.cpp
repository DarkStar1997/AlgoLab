#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
int partition(std::vector<int> &arr, int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if(arr[j] <= x)
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[r]);
	return i;
}
int kthSmallest(std::vector<int> &arr, int l, int r, int k)
{
	if(k > 0 && k <= r - l + 1)
	{
		int pos = partition(arr, l, r);
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthSmallest(arr, l, pos-1, k);
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}
int main()
{
	int n, k; std::cin>>n;
	std::vector<int> arr(n);
	for(auto& i : arr)
		std::cin>>i;
	std::cin>>k;
	std::cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k)<<'\n';
	return 0;
}
