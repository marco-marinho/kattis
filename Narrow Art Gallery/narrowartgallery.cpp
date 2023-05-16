#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N;
    int k;
    while (cin >> N >> k && N + k != 0) {
        vector<vector<int>> vals(N, vector<int>(2, 0));
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(k + 1, vector<int>(3, INT_MIN)));
        dp[0][0][0] = 0;

        for (int i = 0; i < N; i++) {
            cin >> vals[i][0] >> vals[i][1];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= k - 1; j++) {
                dp[i][j][0] =
                        max(max(dp[i - 1][j][0], dp[i - 1][j][1]), dp[i - 1][j][2]) + vals[i - 1][0] + vals[i - 1][1];
                dp[i][j + 1][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + vals[i - 1][1];
                dp[i][j + 1][2] = max(dp[i - 1][j][0], dp[i - 1][j][2]) + vals[i - 1][0];
            }
            dp[i][k][0] = max(max(dp[i - 1][k][0], dp[i - 1][k][1]), dp[i - 1][k][2]) + vals[i - 1][0] + vals[i - 1][1];
        }

        cout << max(max(dp[N][k][0], dp[N][k][1]), dp[N][k][2]) << endl;

    }
}
