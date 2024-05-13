#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

vector<vector<ll>> G(100001);
vector<ll> color(100001, -1);

void dfs(ll v, ll c) {
    color[v] = c;
    for (ll u : G[v]) {
        if (color[u] == -1) {
            dfs(u, 1 - c);
        }
    }
}

int main() {
    ll N;
    cin >> N;
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1, 0);

    ll count0 = 0, count1 = 0;
    for (ll i = 1; i < N; i++) {
        if (color[i] == 0) {
            count0++;
        } else {
            count1++;
        }
    }
    ll counter = 0;
    ll i = 1;
    if (count0 > count1) {
        while (counter < N / 2 && i < N) {
            if (color[i] == 0) {
                cout << i << " ";
                counter++;
            }
            i++;
        }
        return 0;
    } else {
        while (counter < N / 2 && i < N) {
            if (color[i] == 1) {
                cout << i << " ";
                counter++;
            }
            i++;
        }
        return 0;
    }

    return 0;
}
