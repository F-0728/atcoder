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
    vpll range(N);
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        range.at(i) = {l, r};
    }
    double ans = 0;
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            ll cnt = 0;
            ll sumComb = (range.at(i).second - range.at(i).first + 1) * (range.at(j).second - range.at(j).first + 1);
            for (ll k = range.at(i).first; k <= range.at(i).second; k++) {
                for (ll l = range.at(j).first; l <= range.at(j).second; l++) {
                    if (k > l) {
                        cnt++;
                    }
                }
            }
            ans += (double)cnt / sumComb;
        }
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
