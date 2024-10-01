#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

const ll MAX = 2000005;
mint fact[MAX], factInv[MAX], inv[MAX];

void init() {
    ll MOD = mint::mod();
    fact[0] = fact[1] = 1;
    factInv[0] = factInv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++) {
        fact[i] = fact[i - 1] * i;
        inv[i] = MOD - inv[MOD % i] * (MOD / i);
        factInv[i] = factInv[i - 1] * inv[i];
    }
}

mint nPr(ll n, ll r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[n - r];
}

mint nCr(ll n, ll r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[r] * factInv[n - r];
}

int main() {
    ll N;
    cin >> N;

    vector<mint> ans(N, 0);
    init();

    for (ll i = 1; i <= N; i++) {
        for (ll k = 1; k <= N; k++) {
            mint com = nCr(N - (k - 1) * (i - 1), i);
            if (com == 0) break;
            ans.at(k - 1) += com;
        }
    }

    rep(i, N) {
        cout << ans[i].val() << endl;
    }

    return 0;
}
