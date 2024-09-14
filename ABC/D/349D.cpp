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
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll L, R;
    cin >> L >> R;

    vll pow2(61);
    pow2[0] = 1;
    rep(i, 60) { pow2[i + 1] = pow2[i] * 2; }

    vpll ans;
    ll now = L;
    while (now < R) {
        ll count2 = 0;
        ll n = now;
        while (n % pow2[count2 + 1] == 0 && count2 < 60 && n + pow2[count2 + 1] <= R) {
            count2++;
        }
        // cout << now << " " << count2 << endl;
        ans.push_back({now, now + pow2[count2]});
        now += pow2[count2];
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
