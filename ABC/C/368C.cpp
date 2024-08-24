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
    vll H(N);
    rep(i, N) cin >> H.at(i);

    ll t = 0;
    rep(i, N) {
        ll q = H.at(i) / 5;
        t += 3 * q;
        H.at(i) -= 5 * q;
        while (H.at(i) > 0) {
            t++;
            if (t % 3 == 0) {
                H.at(i) -= 3;
            } else {
                H.at(i) -= 1;
            }
        }
    }
    cout << t << endl;

    return 0;
}
