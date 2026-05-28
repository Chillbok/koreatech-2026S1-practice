#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
#include <climits>

const int INF = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<vector<int>> dist(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) dist[i][i] = 0;

        for (int i = 0; i < E; i++) {
            int S, D, W;
            cin >> S >> D >> W;
            if (W < dist[S][D])
                dist[S][D] = W;
        }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        if (dist[i][k] + dist[k][j] < dist[i][j])
                            dist[i][j] = dist[i][k] + dist[k][j];

        bool neg = false;
        for (int i = 0; i < N; i++)
            if (dist[i][i] < 0) { neg = true; break; }

        if (neg) {
            cout << -1 << "\n";
            continue;
        }

        bool found = false;
        int bestVal = 0, bestS = -1, bestD = -1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || dist[i][j] == INF) continue;
                if (!found || dist[i][j] > bestVal ||
                    (dist[i][j] == bestVal && (i < bestS || (i == bestS && j < bestD)))) {
                    bestVal = dist[i][j];
                    bestS = i;
                    bestD = j;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "0 0 0\n";
        } else {
			cout << bestS << " " << bestD << " " << bestVal << "\n";
        }
    }

    return 0;
}