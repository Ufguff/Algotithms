#include<deque>
#include <vector>

bool check(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size());
    deque<int> q;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            q.push_back(i);
            while (q.size())
            {
                int p = q.front();  q.pop_front();
                if (visited[p]) return false;
                visited[p] = true;
                for (int j = 0; j < graph[p].size(); j++)
                    q.push_back(graph[p][j]);
            }
        }
    }
    return false;
}
