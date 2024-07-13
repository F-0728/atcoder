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
    sort(A.begin(), A.end());
    vll count(A.at(N - 1) + 1, 0);
    rep(i, N) {
        count.at(A.at(i))++;
    }
    ll count2 = 0;
    ll count3 = 0;
    rep(i, N) {
        if (count.at(A.at(i)) > 1) {
            count2++;
            if (count.at(A.at(i)) > 2) {
                count3++;
            }
        }
    }
    ll ans = N * (N - 1) * (N - 2) / 6;
    ll duplicated = 0;
    for (ll i = 0; i < count.size(); i++) {
        if (count.at(i) > 1) {
            duplicated += (count.at(i) * (count.at(i) - 1) / 2) * (N - count.at(i));
            if (count.at(i) > 2) {
                duplicated += (count.at(i) * (count.at(i) - 1) * (count.at(i) - 2) / 6);
            }
        }
    }
    ans -= duplicated;
    cout << ans << endl;

    return 0;
}
