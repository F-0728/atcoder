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
    ll N, K;
    cin >> N >> K;
    vll A(N);
    rep(i, N) cin >> A.at(i);

    vll dp(K + 1, 0);
    rep(i, K + 1){
        rep(j, N){
            if (i - A.at(j) >= 0 && dp.at(i - A.at(j)) == 0) {
                dp.at(i) = 1;
            }
        }
    }
    if (dp.at(K) == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    

    return 0;
}
