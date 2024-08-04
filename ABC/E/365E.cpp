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
    vvll bit(30, vll(N));
    rep(i, 30) {
        rep(j, N) {
            bit.at(i).at(j) = A.at(j) & (1 << i);
        }
    }

    vvll cXOR(30, vll(N + 1));
    rep(i, 30) {
        rep(j, N) {
            cXOR.at(i).at(j + 1) = cXOR.at(i).at(j) ^ bit.at(i).at(j);
        }
    }
    ll sum = 0;
    rep(i, N) {
        sum += A.at(i);
    }

    ll ans = 0;
    rep(i, 30) {
        ll count0 = 0;
        ll count1 = 0;
        rep(j, N + 1) {
            if (cXOR.at(i).at(j) == 0) {
                count0++;
            } else {
                count1++;
            }
        }
        ans += (1 << i) * count0 * count1;
    }
    
    cout << ans - sum << endl;

    return 0;
}
