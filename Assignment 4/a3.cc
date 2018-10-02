#include <iostream>
#include <vector>

void make_set(std::vector<int> &set)
{
	for(auto &i: set)
	{
		i = -1;
	}
}

int find_set(std::vector<int> &set, int elm)
{
	std::vector<int> stack;
	int temp = elm;
	while(temp>0)
	{
		stack.push_back(temp);
		temp = set[temp-1];
	}
	elm = stack.back();
	for(int i=0;i<stack.size()-1;i++)
		set[stack[i]-1] = temp;
	return elm;
}

bool union_set(std::vector<int> &set, std::pair<int,int> &edge)
{
	int n1 = find_set(set, edge.first), n2 = find_set(set, edge.second);
	if(n1 == n2)
		return false;
	else{
		if(set[n1-1] < set[n2-1])
		{
			set[n1-1] += set[n2-1];
			set[n2-1] = n1;
		}
		else{
			set[n2-1] += set[n1-1];
			set[n1-1] = n2;
		}
	}
	return true;
}

int main()
{
	int v,e;
	std::cout<<"Enter the no. of vertices & edges: ";
	std::cin>>v>>e;
	std::vector<int> set(v);
	std::vector<std::pair<int,int>> edges(e);
	make_set(set);
	std::cout<<"Enter the edges:\nsource\tdestination\n";
	for(int i=0;i<e;i++)
	{
		int n1,n2;
		std::cin>>n1>>n2;
		edges[i] = std::make_pair(n1,n2);
	}
	for(int i=0;i<e;i++)
	{
		if(union_set(set, edges[i]))
		{
			std::cout<<"edge added: "<<edges[i].first<<" - "<<edges[i].second<<"\n";
		}
		else{
			std::cout<<"Cycle detected at edge: "<<edges[i].first<<" - "<<edges[i].second<<"\n";
			break;
		}
	}
}