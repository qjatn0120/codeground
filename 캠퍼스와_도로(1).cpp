#include <bits/stdc++.h>

using namespace std;

const int inf = 987654321;
const int MX = 1005;

int T, N, M;
bool b[MX];

struct Dijkstra{

    vector <pair<int, int> > adj[MX];
    int dist[MX];

    void Clear(){
        for(int i = 1; i <= N; i++) dist[i] = inf;
    }

    void AddEdge(int a, int b, int c){
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    void solve(int S){
        priority_queue <pair<int, int> > pq;
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int pos = pq.top().second, cost = -pq.top().first;
            pq.pop();
            if(dist[pos] != cost) continue;
            for(auto next : adj[pos]){
                int nPos = next.first;
                int nCost = cost + next.second;
                if(nCost < dist[nPos]){
                    dist[nPos] = nCost;
                    pq.push({-nCost, nPos});
                }
            }
        }
    }
}dij;

void solve(){
    for(int i = 1; i <= N; i++) b[i] = false;
    for(int S = 1; S <= N; S++){
        dij.Clear();
        dij.solve(S);
        for(int p = 1; p <= N; p++){
            if(p == S) continue;
            for(auto adj : dij.adj[p]){
                if(dij.dist[p] + adj.second == dij.dist[adj.first]){b[p] = true;break;}
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    for(int rep = 1; rep <= T; rep++){
        scanf("%d %d", &N, &M);
        for(int i = 1; i <= N; i++) dij.adj[i].clear();
        int A, B, C;
        for(int i = 1; i <= M; i++) scanf("%d %d %d", &A, &B, &C), dij.AddEdge(A, B, C);
        solve();
        int cnt = 0;
        printf("Case #%d\n", rep);
        for(int i = 1; i <= N; i++) if(!b[i]) cnt++;
        printf("%d", cnt);
        for(int i = 1; i <= N; i++) if(!b[i]) printf(" %d", i);
        printf("\n");
    }
}
