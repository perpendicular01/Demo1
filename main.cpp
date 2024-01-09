/*
5 6
1 2 2
1 4 1
2 3 4
4 3 3
3 5 1
2 5 5

0 2 4 1 5

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
const long long INF = 2e18;

int n, m;
int visited[N];
long long d[N];
vector<pair <int, int>> adjList[N];

void disjkstra(int src){
    for(int i=1; i<=n; i++){
        d[i] = INF;
        visited[i] = 0;
    }

    d[src] = 0;

    for(int i=1; i<=n; i++){
        int selected_node = -1;

        for(int j=1; j<=n; j++){
            if(visited[j])
                continue;

            if(selected_node==-1  ||  d[selected_node] > d[j])
                selected_node = j;
        }
        visited[selected_node] = 1;

        for(auto i : adjList[selected_node]){
            int node = i.first;
            int weight = i.second;

            if(d[selected_node]+weight  <  d[node]){
                d[node] = d[selected_node]+weight;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int src = 1;
    disjkstra(src);

    for(int i=1; i<=n; i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
