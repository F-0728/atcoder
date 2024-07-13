#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

const ll MAX = 2000005;
mint fact[MAX], factInv[MAX], Inv[MAX];

void init() {
    ll MOD = mint::mod();
    fact[0] = fact[1] = 1;
    factInv[0] = factInv[1] = 1;
    Inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fact[i] = fact[i - 1] * i;
        Inv[i] = MOD - Inv[MOD%i] * (MOD / i);
        factInv[i] = factInv[i - 1] * Inv[i];
    }
}

mint nPr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[n - r];
}

mint nCr(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * factInv[k] * factInv[n - k];
}

int main() {
    ll X, Y;
    cin >> X >> Y;
    if ((X + Y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll move = (X + Y) / 3;
    ll x = X - move;
    ll y = Y - move;
    if (x < 0 || y < 0) {
        cout << 0 << endl;
        return 0;
    }
    init();
    cout << nCr(move, min(x, y)).val() << endl;

    return 0;
}
