#include <vector>
#include <functional>
using namespace std;

bool checkCycle(vector<vector<int>> &graph)
{
    function<bool(int, vector<vector<int>>&, vector<int>&)> help = [&help](int i, vector<vector<int>> &graph, vector<int> &visited)
    {
        if (visited[i] == 1)
            return true;
        visited[i] = 1;
        for (int j = 0; j < graph[i].size(); j++){
            bool flag = help(i, graph, visited);
            if (flag)
            return true;
        }
        visited[i] = 2;
        return false;
    };
    vector<int> visited(graph.size());
    for (int i = 0; i < visited.size(); i++)
        if (visited[i] != 2)
        {
            bool flag = help(i, graph, visited);
            if (flag)
                return true;
        }
    return false;
}

