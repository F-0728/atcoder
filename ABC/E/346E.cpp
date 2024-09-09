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
    ll H, W, M;
    cin >> H >> W >> M;

    ll countRow = W;
    vector<bool> rowPainted(H, false);
    ll countCol = H;
    vector<bool> colPainted(W, false);
    map<ll, ll> count;
    vvll query(M);
    rep(i, M) {
        ll t, a, x;
        cin >> t >> a >> x;
        a--;
        query[i] = {t, a, x};
    }
    reverse(query.begin(), query.end());

    rep(i, M) {
        ll t = query[i][0];
        ll a = query[i][1];
        ll x = query[i][2];
        if (t == 1) {
            if (!rowPainted[a]) {
                rowPainted[a] = true;
                count[x] += countRow;
                countCol -= 1;
            }
        } else {
            if (!colPainted[a]) {
                colPainted[a] = true;
                count[x] += countCol;
                countRow -= 1;
            }
        }
    }

    vpll ans;
    ll unPainted = H * W;
    for (auto [k, v] : count) {
        if (v == 0) continue;
        ans.push_back({k, v});
        unPainted -= v;
    }
    sort(ans.begin(), ans.end());
    if (unPainted > 0) {
        if (ans[0].first == 0) {
            ans[0].second += unPainted;
        } else {
            ans.push_back({0, unPainted});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size()) { cout << ans[i].first << " " << ans[i].second << endl; }

    return 0;
}
