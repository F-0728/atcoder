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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vll grundy(1e5 + 5, 0);
    rep(i, 1e5 + 5) {
        set<ll> s;
        if (i - X >= 0) s.insert(grundy.at(i - X));
        if (i - Y >= 0) s.insert(grundy.at(i - Y));
        ll g = 0;
        while (s.count(g)) g++;
        grundy.at(i) = g;
    }
    ll XOR = 0;
    rep(i, N) {
        XOR ^= grundy.at(A.at(i));
    }
    if (XOR) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
