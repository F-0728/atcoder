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
    vll A(K);
    rep(i, K) {
        cin >> A.at(i);
    }
    ll M = A.size();
    ll ans = 0;
    if (M % 2 == 0) {
        rep(i, M / 2) {
            ans += A.at(i * 2 + 1) - A.at(i * 2);
        }
        cout << ans << endl;
        return 0;
    }
    vll cSumL(M / 2 + 1, 0);
    vll cSumR(M / 2 + 1, 0);
    rep(i, M / 2) {
        cSumL.at(i + 1) = cSumL.at(i) + A.at(i * 2 + 1) - A.at(i * 2);
        cSumR.at(i + 1) = cSumR.at(i) + A.at(M - 1 - 2 * i) - A.at(M - 2 - 2 * i);
    }
    ll ansMin = INF;
    rep(i, M / 2 + 1) {
        ansMin = min(ansMin, cSumL.at(i) + cSumR.at(M / 2 - i));
    }
    cout << ansMin << endl;

    return 0;
}
