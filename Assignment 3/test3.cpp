#include <iostream>
#include <vector>
bool check(const std::vector<int> &s, int n, int sum)
{	
	if( sum == 0 )
		return true;
	if( n==0 && sum != 0 )
		return false;
	if(s[n-1] > sum)
		return check(s, n-1, sum);
	return check(s, n-1, sum) || check(s, n-1, sum - s[n-1]);
}
int main()
{
	std::cout<<"Enter the number of elements in the set\n";
	int n; std::cin>>n;
	std::vector<int> s(n);
	std::cout<<"Enter the elements of the set\n";
	for(int i = 1; i <= n; i++)
		std::cin>>s[i-1];
	std::cout<<"Enter the sum\n";
	int sum; std::cin>>sum;
	if(check(s, n, sum))
		std::cout<<"Found\n";
	else
		std::cout<<"Not found\n";
}
