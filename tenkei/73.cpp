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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

vector<vector<mint>> dp(100005, vector<mint>(4, 1));

void dfs(ll v, ll p, vvll& G, vector<char>& c) {
    // cout << v << " " << p << endl;
    if (c.at(v) == 'a') {
        if (G.at(v).size() == 1 && p != -1) {
            dp.at(v).at(0) = dp.at(v).at(1) = dp.at(v).at(3) = 0;
        }
        for (ll next : G.at(v)) {
            if (next == p) continue;
            dfs(next, v, G, c);
            dp.at(v).at(2) *= (dp.at(next).at(0) - dp.at(next).at(1)) + dp.at(next).at(2);
            dp.at(v).at(0) *= dp.at(next).at(2) + dp.at(next).at(3) + 2 * (dp.at(next).at(0) - dp.at(next).at(1));
            dp.at(v).at(1) *= (dp.at(next).at(2) + dp.at(next).at(0) - dp.at(next).at(1));
            dp.at(v).at(3) = 0;
        }
    } else {
        if (G.at(v).size() == 1 && p != -1) {
            dp.at(v).at(0) = dp.at(v).at(1) = dp.at(v).at(2) = 0;
        }
        for (ll next : G.at(v)) {
            if (next == p) continue;
            dfs(next, v, G, c);
            dp.at(v).at(3) *= (dp.at(next).at(0) - dp.at(next).at(1)) + dp.at(next).at(3);
            dp.at(v).at(0) *= dp.at(next).at(2) + dp.at(next).at(3) + 2 * (dp.at(next).at(0) - dp.at(next).at(1));
            dp.at(v).at(1) *= (dp.at(next).at(3) + dp.at(next).at(0) - dp.at(next).at(1));
            dp.at(v).at(2) = 0;
        }
    }
}

int main() {
    ll N;
    cin >> N;
    vector<char> c(N);
    rep(i, N) cin >> c.at(i);

    vvll G(N);
    rep(i, N-1){
        ll A, B;
        cin >> A >> B;
        A--; B--;
        G.at(A).push_back(B);
        G.at(B).push_back(A);
    }
    dfs(0, -1, G, c);

    mint ans = 0;
    ans += dp.at(0).at(0);
    ans -= dp.at(0).at(1);

    cout << ans.val() << endl;
    
    // rep(i, N) {
    //     cout << dp.at(i).at(0).val() << " " << dp.at(i).at(1).val() << " " << dp.at(i).at(2).val() << " " << dp.at(i).at(3).val() << endl;
    // }
    return 0;
}
