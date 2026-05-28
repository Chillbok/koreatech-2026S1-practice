#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int W, N;
        cin >> W >> N;

        vector<int> k(N);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> k[i];
            sum += k[i];
        }

        if ((W + sum) % 2 != 0 || W + sum < 0) {
            cout << 0 << "\n";
            continue;
        }

        int target = (W + sum) / 2;
        if (target > sum) {
            cout << 0 << "\n";
            continue;
        }

        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = target; j >= k[i]; j--) {
                dp[j] += dp[j - k[i]];
            }
        }

        cout << dp[target] << "\n";
    }

    return 0;
}