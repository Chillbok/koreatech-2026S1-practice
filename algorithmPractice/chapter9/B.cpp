#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

int parent[1001];

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionNodes(int u, int v) {
    int rootU = findParent(u);
    int rootV = findParent(v);

    if (rootU != rootV) {
        parent[rootU] = rootV;
        return true;
    }
    return false;
}

void test() {
    int N;
    if (!(cin >> N)) return;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    int resU = 0, resV = 0;
    
    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        
        if (!unionNodes(u, v)) {
            resU = u;
            resV = v;
        }
    }

    cout << resU << " " << resV << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        test();
    }

    return 0;
}