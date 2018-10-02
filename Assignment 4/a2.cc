#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <sstream>

void dfs(std::vector<std::list<int>> &adjList, std::vector<std::pair<int, int>> &path, std::unordered_set<int> &visited, int start)
{
	visited.insert(start);
	while(!adjList[start-1].empty())
	{
		if(visited.find(adjList[start-1].front()) == visited.end())
		{
			path.push_back(std::pair<int, int>(start, adjList[start-1].front()));
			dfs(adjList, path, visited, adjList[start-1].front());
		}
		adjList[start-1].pop_front();
	}
}

int main()
{
	int n;
	std::cout<<"Enter the no. of vertices: ";
	std::cin>>n;
	std::cin.get();
	std::vector<std::list<int>> adjList(n);
	std::vector<std::pair<int, int>> path;
	std::unordered_set<int> visited;
	for(int i=0;i<n;i++)
	{
		std::string temp;
		std::cout<<"Adjacent verteces of "<<i+1<<": ";
		getline(std::cin, temp);
		std::stringstream ss(temp);
		int m;
		while(ss>>m)
			adjList[i].push_back(m);
	}
	std::cout<<"Starting vertex: "; 
	int start;
	std::cin>>start;   
	dfs(adjList, path, visited, 1);
	std::cout<<"Reachable vertices: \n";
	for(int i=0;i<path.size();i++)
		std::cout<<"["<<path[i].first<<","<<path[i].second<<"] ";
	std::cout<<"\n";
}