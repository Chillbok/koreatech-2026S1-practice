#include <iostream>
using std::endl; using std::cin; using std::cout;
#include <vector>
using std::vector;
#include <queue>

typedef std::pair<int, int> pii; // {weight, node}

void test() {
    int N, E;
    if (!(cin >> N >> E)) return;

    vector<pii> adj[101];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<bool> visited(N, false);
    std::priority_queue<pii, vector<pii>, std::greater<pii>> pq;

    // 0번 노드부터 시작 (그래프가 연결 그래프라고 명시됨)
    pq.push({0, 0});
    
    int totalWeight = 0;
    int count = 0;

    while (!pq.empty()) {
        int w = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;

        visited[curr] = true;
        totalWeight += w;
        count++;

        if (count == N) break;

        for (auto& next : adj[curr]) {
            int nextW = next.first;
            int nextNode = next.second;
            if (!visited[nextNode]) {
                pq.push({nextW, nextNode});
            }
        }
    }
    cout << totalWeight << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) test();
    return 0;
}