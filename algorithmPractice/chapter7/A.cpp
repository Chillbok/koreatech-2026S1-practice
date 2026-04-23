#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void test() {
	int N, E; cin >> N >> E;
	
	vector<vector<int>> adj(N);
	vector<int> in_degree(N, 0);

	for (int i = 0; i < E; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		in_degree[v]++;
	}
	
	vector<int> q;
	for (int i = 0; i < N; ++i) if (in_degree[i] == 0) q.push_back(i);
	
	int visited_nodes = 0;
	while (!q.empty()) {
		int curr = q.back();
		q.pop_back();
		visited_nodes++;
		
		for (int x : adj[curr]) {
			in_degree[x]--;
			if (in_degree[x] == 0) q.push_back(x);
		}
	}
	
	if (visited_nodes == N) cout << "false" << endl;
	else cout << "true" << endl;
}

int main() {
	int T; cin >> T;
	while (T--) test();
	return 0;
}