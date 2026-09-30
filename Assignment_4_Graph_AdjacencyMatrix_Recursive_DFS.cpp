#include <iostream>
using namespace std;

class Graph
{
private:
    int vertices;
    int adj[20][20];
    bool visited[20];

public:
    Graph()
    {
        vertices = 0;

        for (int i = 0; i < 20; i++)
        {
            visited[i] = false;

            for (int j = 0; j < 20; j++)
                adj[i][j] = 0;
        }
    }

    void createGraph()
    {
        int edges;
        int source, destination;

        cout << "\nEnter number of vertices: ";
        cin >> vertices;

        if (vertices <= 0 || vertices > 20)
        {
            cout << "Invalid number of vertices." << endl;
            vertices = 0;
            return;
        }

        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;

            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0;
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "\nEnter edges (source destination):" << endl;

        for (int i = 0; i < edges; i++)
        {
            cout << "Edge " << i + 1 << ": ";
            cin >> source >> destination;

            if (source >= 0 && source < vertices &&
                destination >= 0 && destination < vertices)
            {
                // Undirected graph
                adj[source][destination] = 1;
                adj[destination][source] = 1;
            }
            else
            {
                cout << "Invalid vertex number. Enter this edge again." << endl;
                i--;
            }
        }

        cout << "\nGraph created successfully." << endl;
    }

    void displayGraph()
    {
        if (vertices == 0)
        {
            cout << "\nGraph is not created." << endl;
            return;
        }

        cout << "\nAdjacency Matrix:" << endl;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << adj[i][j] << " ";

            cout << endl;
        }
    }

    void DFS(int start)
    {
        visited[start] = true;
        cout << start << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adj[start][i] == 1 && !visited[i])
                DFS(i);
        }
    }

    void performDFS(int start)
    {
        if (vertices == 0)
        {
            cout << "\nGraph is not created." << endl;
            return;
        }

        if (start < 0 || start >= vertices)
        {
            cout << "\nInvalid starting vertex." << endl;
            return;
        }

        for (int i = 0; i < vertices; i++)
            visited[i] = false;

        cout << "\nDFS Traversal: ";
        DFS(start);
        cout << endl;
    }
};

int main()
{
    Graph graph;

    int choice;
    int startVertex;

    do
    {
        cout << "\n===================================";
        cout << "\n      GRAPH USING ADJACENCY MATRIX";
        cout << "\n===================================";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Perform DFS";
        cout << "\n4. Exit";
        cout << "\n===================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                graph.createGraph();
                break;

            case 2:
                graph.displayGraph();
                break;

            case 3:
                cout << "\nEnter starting vertex: ";
                cin >> startVertex;

                graph.performDFS(startVertex);
                break;

            case 4:
                cout << "\nProgram terminated." << endl;
                break;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
