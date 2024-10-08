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
    rep(i, N) {
        cin >> A[i];
    }

    ll l = 0, r = 1;
    ll ans = 0;
    while (r < N) {
        r = l + 1;
        while (r < N && A[r] - A[r - 1] == A[l + 1] - A[l]) {
            r++;
        }
        // cout << l << " " << r << endl;
        ll n = r - l;
        // cout << n * (n - 1) / 2 << endl;
        ans += n * (n - 1) / 2;
        // if (n <= 2) {
        //     ans++;
        // }
        l = r - 1;
    }

    cout << ans + N << endl;

    return 0;
}
