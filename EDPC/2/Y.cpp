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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
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
    ll H, W, N;
    cin >> H >> W >> N;
    vpll wall(N + 1);
    rep(i, N) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        wall[i] = {r, c};
    }
    wall[N] = {H, W};
    sort(wall.begin(), wall.end());

    init();

    vector<mint> dp(N, 0);
    rep(i, N) {
        ll r = wall.at(i).first;
        ll c = wall.at(i).second;
        mint all = nCr(r + c, r);
        mint sub = 0;
        rep(j, i) {
            ll rdiff = r - wall.at(j).first;
            ll cdiff = c - wall.at(j).second;
            sub += dp.at(j) * nCr(rdiff + cdiff, rdiff);
        }
        dp.at(i) = all - sub;
    }

    // rep(i, N) {
    //     cout << dp.at(i).val() << " ";
    // }
    // cout << endl;

    mint ans = nCr(H + W - 2, H - 1);
    rep(i, N) {
        ll r = wall.at(i).first;
        ll c = wall.at(i).second;
        ll rdiff = H - r - 1;
        ll cdiff = W - c - 1;
        ans -= dp.at(i) * nCr(rdiff + cdiff, rdiff);
    }

    cout << ans.val() << endl;

    return 0;
}
