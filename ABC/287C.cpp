#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

bool is_connected(dsu d, int N) {
    for (int i = 1; i < N; i++) {
        if (d.leader(i) != d.leader(0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> degs(N, 0);
    dsu d(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        degs[u - 1]++;
        degs[v - 1]++;
        d.merge(u - 1, v - 1);
    }
    int count1 = count(degs.begin(), degs.end(), 1);
    int count2 = count(degs.begin(), degs.end(), 2);

    if (count1 == 2 && count2 == N - 2 && is_connected(d, N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
