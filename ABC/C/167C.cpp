#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N, M, X;
    cin >> N >> M >> X;
    vvll book(N, vll(M, 0));
    vll cost(N, 0);
    rep(i, N) {
        cin >> cost[i];
        rep(j, M) { cin >> book[i][j]; }
    }

    vvll bitSearch;
    rep(i, 1 << N) {
        vll tmp;
        rep(j, N) {
            if (i >> j & 1) {
                tmp.push_back(j);
            }
        }
        bitSearch.push_back(tmp);
    }

    ll ans = INF;
    for (vll v : bitSearch) {
        vll algo(M, 0);
        rep(i, v.size()) {
            rep(j, M) {
                algo[j] += book[v[i]][j];
            }
        }
        bool flag = true;
        rep(i, M) {
            if (algo[i] < X) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ll c = 0;
            for (ll i : v) {
                c += cost[i];
            }
            ans = min(ans, c);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
