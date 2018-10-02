#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>
#include <sstream>

void bfs(std::vector<std::list<int>> adjList, std::vector<std::pair<int, int>> &path, int start)
{
	std::unordered_set<int> visited;
	std::queue<int> yetoex;
	yetoex.push(start);
	visited.insert(start);
	while(!yetoex.empty())
	{
		while(!adjList[yetoex.front()-1].empty())
		{
			if(visited.find(adjList[yetoex.front()-1].front()) == visited.end())
			{
				visited.insert(adjList[yetoex.front()-1].front());
				yetoex.push(adjList[yetoex.front()-1].front());
				path.push_back(std::pair<int, int>(yetoex.front(), adjList[yetoex.front()-1].front()));
			}
			adjList[yetoex.front()-1].pop_front();
		}
		yetoex.pop();
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
	bfs(adjList, path, 1);
	std::cout<<"Reachable vertices: ";
	for(int i=0;i<path.size();i++)
		std::cout<<"["<<path[i].first<<","<<path[i].second<<"] ";
	std::cout<<"\n";
}