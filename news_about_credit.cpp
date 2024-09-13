#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numNodes, degree[105], totalEdges, remainingEdges;
bool visited[105];
vector<pair<int, int> > connections;

struct Node
{
    int degree, index;
} nodes[105];

bool compare(Node x, Node y)
{
    if (x.degree != y.degree)
        return x.degree > y.degree;
    return x.index < y.index;
}

int main()
{
    cin >> numNodes;
    remainingEdges = numNodes - 1;

    for (int i = 1; i <= numNodes; i++)
    {
        cin >> degree[i];
        totalEdges += degree[i];
    }

    if (degree[1] == 0 || totalEdges < numNodes - 1)
    {
        cout << -1;
        return 0;
    }

    visited[1] = true;
    while (remainingEdges > 0)
    {
        for (int i = 1; i <= numNodes; i++)
        {
            if (visited[i])
            {

                for (int j = 2; j <= numNodes; j++)
                {
                    nodes[j].degree = degree[j];
                    nodes[j].index = j;
                }

                sort(nodes + 2, nodes + numNodes + 1, compare);

                for (int j = 2; j <= numNodes && degree[i] > 0; j++)
                {
                    if (!visited[nodes[j].index])
                    {
                        degree[i]--;
                        remainingEdges--;
                        visited[nodes[j].index] = true;
                        connections.push_back(make_pair(i, nodes[j].index));

                        if (remainingEdges == 0)
                        {
                            cout << connections.size() << "\n";
                            for (int k = 0; k < connections.size(); k++)
                                cout << connections[k].first << " " << connections[k].second << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
