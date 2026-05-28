#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        int G, M;
        string X, Y;
        cin >> G >> M >> X >> Y;

        int n = X.size();
        int m = Y.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++) dp[i][0] = i * G;
        for (int j = 1; j <= m; j++) dp[0][j] = j * G;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int match = dp[i-1][j-1] + (X[i-1] == Y[j-1] ? 0 : M);
                int gapX  = dp[i-1][j] + G;
                int gapY  = dp[i][j-1] + G;

                dp[i][j] = std::min({match, gapX, gapY});
            }
        }

        cout << dp[n][m] << "\n";
    }

    return 0;
}