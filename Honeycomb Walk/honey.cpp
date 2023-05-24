#include <iostream>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int maxSize = 19;
    constexpr int middle = (maxSize / 2) + 1;

    array<array<array<array<int, maxSize>, maxSize>, maxSize>, maxSize> dp{};

    dp[middle][middle][middle][0] = 1;

    for(int step = 1; step < maxSize; step++){
        for(int q = 1; q < maxSize - 1; q++){
            for(int r = 1; r < maxSize - 1; r++){
                for(int s = 1; s < maxSize - 1; s++){
                    dp[q][r][s][step] = dp[q - 1][r + 1][s][step - 1] + dp[q + 1][r - 1][s][step - 1] +
                                        dp[q][r - 1][s + 1][step - 1] + dp[q][r + 1][s - 1][step - 1] +
                                        dp[q + 1][r][s - 1][step - 1] + dp[q - 1][r][s + 1][step - 1];
                }
            }
        }
    }

    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int steps = 0;
        cin >> steps;
        cout << dp[middle][middle][middle][steps] << endl;
    }
    return 0;
}

