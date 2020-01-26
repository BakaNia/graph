#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;
public:
    AdjacencyMatrix(int n) {
        this->n = n;
        adj = new int *[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new int[n + 1];
            for (int j = 0; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
    }


    bool Search(int top) {
        int i = 1;
        while (adj[0][i] != top && i < n + 1) {
            i++;
        }
        if (i == n + 1) {
            return false;
        } else {
            if (adj[0][i] == top) {
                return true;
            }
        }

    }

    int add_top(int top) {
        int i = 1;
        while (adj[0][i] != 0 && i < n + 1) {
            if (adj[0][i] == top) {
                return 1;
            }
            i++;
        }
        if (i == n + 1) {
            return 1;
        }
        adj[0][i] = top;
        adj[i][0] = top;
    }

    int del_top(int top) {
        if (this->Search(top) == true) {
            int i = 1;
            while (adj[0][i] != top && i < n + 1) {
                i++;
            }
            if (i == n + 1) {
                return 1;
            }
            for (int k = 0; k <= n; k++) {
                adj[k][i] = 0;
                adj[i][k] = 0;
            }
        }
    }

    int add_arc(int top1, int top2, int v) {
        int i = 1;
        int j = 1;
        if ((top1 == top2) || (top1 == 0) || (top2 == 0)) {
            return 1;
        }
        while (adj[0][i] != top2 && i < n + 1) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 1) {
            j++;
        }
        if (i == n + 1) {
            return 1;
        }
        if (j == n + 1) {
            return 1;
        }
        if ((adj[j][i] == 0) && (adj[i][j] == 0) && (v != 0)) {
            adj[j][i] = v;
            adj[i][j] = v;
        }

    }

    int del_arc(int top1, int top2) {
        int i = 1;
        int j = 1;
        if (top1 == top2) {
            return 1;
        }
        while (adj[0][i] != top2 && i < n + 1) {
            i++;
        }
        while (adj[j][0] != top1 && j < n + 1) {
            j++;
        }
        if (i == n + 1) {
            return 1;
        }
        if (j == n + 1) {
            return 1;
        }
        if ((adj[j][i] != 0) && (adj[i][j] != 0)) {
            adj[j][i] = 0;
            adj[i][j] = 0;
        }
    }


    void display() {

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++)
                cout << adj[i][j] << "  ";
            cout << endl;

        }
        cout << endl;
    }


    void BFS(int start)
    {
        vector<bool> visited(n, false);
        vector<int> q;
        q.push_back(start);

        // Set source as visited
        visited[start] = true;

        int vis;
        while (!q.empty()) {
            vis = q[0];

            // Print the current node
            cout << vis << " ";
            q.erase(q.begin());

            // For every adjacent vertex to the current vertexOOOO
            for (int j = 1; j < n + 1; j++)
                for (int i = 1; i < n + 1; i++){
                    if (adj[0][j] != 0 && (!visited[adj[0][j]]) && (adj[i][0] == vis) && (adj[i][j] != 0)) {


                            // Push the adjacent node to the queue
                            q.push_back(adj[0][j]);

                            // Set
                            visited[adj[0][j]] = true;

                    }
                }

        }
    }

    void BFSq(int start)
    {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);

        // Set source as visited
        visited[start] = true;

        int vis;
        while (!q.empty()) {
            vis = q.front();

            // Print the current node
            cout << vis << " ";
            q.pop();

            // For every adjacent vertex to the current vertexOOOO
            for (int j = 1; j < n + 1; j++)
                for (int i = 1; i < n + 1; i++){
                    if (adj[0][j] != 0 && (!visited[adj[0][j]]) && (adj[i][0] == vis) && (adj[i][j] != 0)) {


                        // Push the adjacent node to the queue
                        q.push(adj[0][j]);

                        // Set
                        visited[adj[0][j]] = true;

                    }
                }

        }
    }

    /*int myBFS(int start) {
        queue<int> Queue;
        int k = 0;
        bool isVisit;
        int *visited = new int[n]; // вершины графа
        for (int i = 0; i < n + 1; i++)
            visited[i] = 0;

        AdjacencyMatrix S(n);
        int q = start;
        Queue.push(q);
        visited[0] = q;
        while (!Queue.empty()){
            int node = Queue.front();
            Queue.pop();

            for (int i = 1; i <= n + 1; i++) {
                for (int j = 1; j <= n + 1; j++) {//заполняем строку массива

                    if ((adj[q][j] != 0) && (q != j)) {
                        Queue.push(adj[0][j]); // добавляем ее в очередь
                        visited[j] = adj[0][j]; // отмечаем вершину как помеченную
                    }
                }
            }
        }
            for ( int y=0; y < n + 1; y++){
                cout << visited[y];
                cout << " ";
            }
    }*/

};




int main() {
    AdjacencyMatrix adj(8);
    adj.add_top(16);
    adj.add_top(40);
    adj.add_top(2);
    adj.add_top(4);
    adj.add_top(6);
    adj.add_top(8);
    adj.add_top(10);
    adj.add_top(20);
    adj.add_arc(2, 4, 4);
    adj.add_arc(4, 8, 2);
      adj.add_arc(10, 6, 4);
      adj.add_arc(8, 10, 4);
      adj.add_arc(16, 20, 4);
      adj.add_arc(20, 40, 4);
      adj.add_arc(6, 16, 4);
      adj.add_arc(2, 40, 4);

    adj.display();
   // adj.del_top(4);
   // adj.display();
   // adj.del_arc(8,10);
   // adj.display();
    adj.BFSq(20);

    return 0;

}