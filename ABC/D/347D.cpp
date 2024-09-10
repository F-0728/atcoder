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
    ll a, b, C;
    cin >> a >> b >> C;

    ll c = popcount((unsigned long long) C);

    if (a + b < c) {
        cout << -1 << endl;
        return 0;
    }

    ll A = 0;
    ll B = 0;
    if ((a + b - c) % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    ll both = (a + b - c) / 2;
    a -= both;
    b -= both;
    rep(i, 60) {
        if (C & (1LL << i)) {
            if (a > 0) {
                A += 1LL << i;
                a--;
            } else {
                B += 1LL << i;
                b--;
            }
        } else {
            if (both > 0) {
                A += 1LL << i;
                B += 1LL << i;
                both--;
            }
        }
    }
    if (a > 0 || b > 0 || both > 0) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << A << " " << B << endl;

    return 0;
}
