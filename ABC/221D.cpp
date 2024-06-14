#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
    ll N;
    cin >> N;
    vpll events;
    rep(i, N) {
        ll A, B;
        cin >> A >> B;
        events.push_back({A, 1});
        events.push_back({A + B, -1});
    }
    sort(events.begin(), events.end());
    vll ans(N + 1, 0);
    ll cnt = 0;
    rep(i, 2 * N) {
        cnt += events[i].second;
        if (i < 2 * N - 1) {
            ans.at(cnt) += events[i + 1].first - events[i].first;
        }
    }
    rep(i, N) {
        cout << ans.at(i + 1) << " ";
    }

    return 0;
}
