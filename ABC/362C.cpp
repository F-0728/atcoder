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
    vpll LR(N);
    ll sumL = 0;
    ll sumR = 0;
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        LR[i] = {l, r};
        sumL += l;
        sumR += r;
    }
    if (sumL > 0 || sumR < 0) {
        cout << "No" << endl;
        return 0;
    }
    ll lack = -sumL;
    vll ans(N);
    rep(i, N) {
        ll l = LR[i].first;
        ll r = LR[i].second;
        if (lack >= r - l) {
            ans[i] = r;
            lack -= r - l;
        } else {
            ans[i] = lack + l;
            lack = 0;
        }
    }
    Yes;
    outv(ans);

    return 0;
}
