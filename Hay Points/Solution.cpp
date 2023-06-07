#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m = 0, n = 0;
    unordered_map<string, int> values;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string tmp;
        int tmp_i = 0;
        cin >> tmp >> tmp_i;
        values[tmp] = tmp_i;
    }
    int res = 0;
    string output;
    for (int i = 0; i < n; i++) {
        string word;
        while (cin >> word) {
            if (word == ".") {
                break;
            }
            res += values[word];
        }
        output += to_string(res) + "\n";
        res = 0;
    }
    cout << output;
    return 0;
}

