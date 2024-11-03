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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    vpll garbage(N);
    rep(i, N) {
        cin >> garbage.at(i).first >> garbage.at(i).second;
    }

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll t, d;
        cin >> t >> d;
        t--;
        ll q = d / garbage.at(t).first;
        ll r = d % garbage.at(t).first;
        if (r <= garbage.at(t).second) {
            cout << q * garbage.at(t).first + garbage.at(t).second << endl;
        } else {
            cout << (q + 1) * garbage.at(t).first + garbage.at(t).second << endl;
        }
    }

    return 0;
}
