#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v = vector<vector<int>>(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (b > a) {
            swap(a, b);
        }
        v[a - 1].push_back(b - 1);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].size() == 1) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
