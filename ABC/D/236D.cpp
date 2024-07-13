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

vvll chemistry;
vector<bool> used;
vpll pairs;
ll dfs(ll N) {
    if (pairs.size() == N) {
        ll sum = 0;
        rep(i, N) {
            sum ^= chemistry.at(pairs.at(i).first).at(pairs.at(i).second);
        }
        return sum;
    }

    ll pair1;
    rep(i, N * 2) {
        if (!used.at(i)) {
            pair1 = i;
            break;
        }
    }
    used.at(pair1) = true;

    ll res = -INF;
    rep(i, N * 2) {
        if (!used.at(i)) {
            pairs.push_back({pair1, i});
            used.at(i) = true;
            res = max(res, dfs(N));
            pairs.pop_back();
            used.at(i) = false;
        }
    }
    used.at(pair1) = false;
    return res;
}

int main() {
    ll N;
    cin >> N;
    chemistry.resize(N * 2, vll(N * 2));
    used.resize(N * 2, false);
    rep(i, N * 2) {
        for (ll j = i + 1; j < N * 2; j++) {
            ll num;
            cin >> num;
            chemistry.at(i).at(j) = num;
            chemistry.at(j).at(i) = num;
        }
    }
    ll ans = dfs(N);
    cout << ans << endl;
    
    return 0;
}
