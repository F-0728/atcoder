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
    string S;
    cin >> S;
    ll N = S.size();
    ll diffCount = 0;
    rep(i, N / 2) {
        if (S.at(i) != S.at(N - 1 - i)) {
            diffCount++;
        }
    }
    if (diffCount >= 2) {
        cout << 25 * N << endl;
    } else if (diffCount == 0) {
        if (N % 2 == 0) {
            cout << 25 * N << endl;
        } else {
            cout << 25 * (N - 1) << endl;
        }
    } else {
        ll ans = 25 * (N - 2);
        cout << ans + 24 * 2 << endl;
    }

    return 0;
}
