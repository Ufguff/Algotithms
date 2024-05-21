#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

class Circle {
    double x, y, r;
public:
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
    Circle() {}
    bool IsTouched(Circle circle)
    {
        return hypot(circle.x - x, circle.y - y) <= circle.r + r;
    }
};


int n;
vector<vector<int>> graph;
vector<bool> visited;

int DFS()
{
    int count = 0;
    deque<int> queue;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            queue.push_back(i);
            while(queue.size())
            {
                int num = queue.front();
                queue.pop_front();
                visited[num] = true;
                for (int j = 0; j < graph[num].size(); j++)
                {
                    if (!visited[graph[num][j]])
                        queue.push_back(graph[num][j]);
                }
            }
        }
    }
    return count;
}



int main()
{

    vector<Circle> circles;
    cin >> n;
    
    circles.resize(n);
    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++)
    {
        double x, y, r;     cin >> x >> y >> r;
        Circle temp(x, y, r);
        for (int j = 0; j < circles.size(); j++)
        {
            if (circles[j].IsTouched(temp))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        circles.push_back(temp);
    }

    cout << DFS() << endl;

    return 0;
}