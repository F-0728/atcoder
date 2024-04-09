#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> s;
    unordered_map<string, int> m;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.push_back(str.substr(3, str.size()));
    }
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        m[str] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (m[s[i]] == 1) {
            ans += 1;
        }
    }
    cout << ans << endl;
}
