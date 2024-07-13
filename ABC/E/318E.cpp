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
    vll left(N + 1, 0);
    vll right(N + 1, 0);
    rep(i, N) {
        right.at(A.at(i))++;
    }
    ll ans = 0;
    ll res = 0;
    rep(i, N - 1) {
        if (i == 0) {
            right.at(A.at(i))--;
            continue;
        }
        // if (i == 9 || i == 8) {
        //     cout << "l: ";
        //     outv(left);
        //     cout << "r: ";
        //     outv(right);
        // }
        res += right.at(A.at(i - 1));
        res -= left.at(A.at(i));
        left.at(A.at(i - 1))++;
        right.at(A.at(i))--;
        if (A.at(i - 1) == A.at(i)) res--;
        // if (i == 9 || i == 8) cout << "res: " << res << endl;
        ans += res - left.at(A.at(i)) * right.at(A.at(i));
    }
    cout << ans << endl;
    return 0;
}
