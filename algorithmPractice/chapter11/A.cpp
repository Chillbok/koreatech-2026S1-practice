#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int W, N;
        cin >> W >> N;
        vector<int> v(N);
        vector<int> w(N);

		for (int i = 0; i < N; ++i) {
			cin >> v[i] >> w[i];
		}

        vector<int> dp(W + 1, 0);

        for (int i = 0; i < N; i++) {
            for (int j = W; j >= w[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
            }
        }

        cout << dp[W] << "\n";
    }

    return 0;
}