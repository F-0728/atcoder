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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    sort(A.begin(), A.end());
    ll M = A.at(N - 1);
    vll count(M + 1, 0);
    rep(i, N) {
        count.at(A.at(i))++;
    }
    set<pll> s;
    rep(i, M) {
        rep(j, M / (i + 1)) {
            s.insert(pll(i + 1, j + 1));
        }
    }
    ll ans = 0;
    for (pll p : s) {
        ll j = p.first;
        ll k = p.second;
        ans += count.at(j) * count.at(k) * count.at(j * k);
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
