#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class AdjacencyMatrix {
private:
    int n;
    int **adj;
    int **adj2;
    int size;
    int MaxSize;
public:
    AdjacencyMatrix(int n) {
        this->size=0;
        this->n = n;
        adj2=NULL;
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
        if (i > n) {
            n=n+1;
            adj2=new int * [n+1];
            for (int l = 0; l <= n; ++l) {
                adj2[l]=new int[n+1];
                for (int j = 0; j <=n ; ++j) {
                    adj2[l][j]=0;
                }

            }
            for (int j = 0; j <= n-1; ++j) {
                for (int k = 0; k <= n-1 ; ++k) {
                    adj2[j][k]=adj[j][k];
                }
            }
            int **buff=adj;

            for (int m = 0; m <=n-1 ; ++m) {
                delete[]adj[m];
            }
            delete[]adj;
            adj = new int *[n + 1];
            for (int i = 0; i <= n; i++) {
                adj[i] = new int[n + 1];
                for (int j = 0; j <= n; j++) {
                    adj[i][j] = 0;
                }
            }
            for (int i1 = 0; i1 <= n ; ++i1) {
                for (int j = 0; j <=n ; ++j) {
                   adj[i1][j]=adj2[i1][j];
                }
            }
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

            for (int k = 0; k <= n; k++) {
                adj[k][i] = 0;
                adj[i][k] = 0;
            }

            for (int j = i+1; j <= n; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (k < i) {
                        adj[j - 1][k] = adj[j][k];
                        adj[k][j-1] = adj[k][j];
                    } else {
                        if(k==i+1)
                        adj[j-1][k-1]=adj[i][k];
                        if (k!=i){

                        adj[j - 1][k-1] = adj[j][k];
                        adj[k-1][j-1] = adj[k][j];
                    }}
                }
            }
            for (int k = 0; k <= n; k++) {
                adj[k][n] = 0;
                adj[n][k] = 0;
            }
        }
    }

    int add_arc(int top1, int top2, int v) {
        int i = 1;
        int j = 1;
        if ((top1 == top2) || (top1 == 0) || (top2 == 0)) {
            return 1;
        }
        while (adj[0][i] != top2 && i != n) {
            i++;
        }
        while (adj[j][0] != top1 && j != n) {
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
        cout << endl;


        cout<<adj[0][0]<<"  ";
        for (int k = 0; k <= n; ++k) {
            if(adj[0][k]!=0)
                cout<<adj[0][k] << "  ";
        }
        cout<<endl;
        for (int i = 1; i <= n; i++) {
            if(adj[i][0]!=0){
                cout<<adj[i][0]<<"  ";
            for (int j = 1; j <= n; j++)
                if((adj[0][j]!=0))
                cout << adj[i][j] << "  ";
            cout << endl;
        }}
        cout << endl;
    }


    void BFS(int start)
    {

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);

        // Set source as visited
        visited[start] = true;

        int vis;
        bool isHere = false;

        for (int u = 1; u < n + 1; u++){
            if (start == adj[u][0]) isHere = true;
        }

        if (isHere == false) {
            cout << endl;
            cout << "Doesn't exist";
            cout << endl;}
        else
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

    }}

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
    AdjacencyMatrix adj(7);

    for (int i = 0; i <10 ; ++i) {
        adj.add_top(i);
    }

   /* adj.add_top(3);
    adj.add_top(4);
    adj.add_top(5);
    adj.add_top(6);
    adj.add_top(1);
    adj.add_top(2);
    adj.add_top(9);
    adj.add_top(14);

    adj.add_arc(1, 4, 1);
    adj.add_arc(1, 3, 1);
    adj.add_arc(2, 6, 1);
    adj.add_arc(2, 7, 10);
    adj.add_arc(4, 5, 1);
      adj.add_arc(1, 2, 1);
      adj.add_arc(2, 3, 1);
      adj.add_arc(2, 5, 1);
      adj.add_arc(2, 6, 1);
      adj.add_arc(2, 7, 1);
    adj.add_arc(4, 5, 1);
    adj.add_arc(5, 6, 1);
*/
    adj.add_arc(1,2,1);
    adj.add_arc(1,3,1);
    adj.add_arc(2,4,1);
    adj.add_arc(4,5,1);
    adj.add_arc(4,6,1);
    adj.add_arc(3,5,1);
    adj.add_arc(3,8,1);
    adj.add_arc(5,8,1);
    adj.add_arc(5,7,1);
    adj.add_arc(6,7,1);
    adj.add_arc(8,9,1);
    adj.add_arc(8,7,1);
    adj.display();

    adj.BFS(1);
    adj.del_top(5);
    adj.display();
    adj.add_top(20);
    adj.display();

    adj.BFS(1);
    adj.BFS(5);

    return 0;

}
