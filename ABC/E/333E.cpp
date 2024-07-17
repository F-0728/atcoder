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
    vvll portion(N);
    vll ans;
    vpll query(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        b--;
        query.at(i) = {a, b};
    }
    ll counter = 0;
    rep(i, N) {
        auto [t, x] = query.at(i);
        if (t == 1) {
            portion.at(x).push_back(counter);
            ans.push_back(0);
            counter++;
        } else {
            if (portion.at(x).empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                ll p = portion.at(x).back();
                portion.at(x).pop_back();
                ans.at(p) = 1;
            }
        }
    }
    ll ansMax = 0;
    counter = 0;
    ll tmp = 0;
    rep(i, N) {
        auto [t, x] = query.at(i);
        if (t == 1) {
            if (ans.at(counter) == 1) {
                tmp++;
            }
            counter++;
        } else {
            tmp--;
        }
        ansMax = max(ansMax, tmp);
    }
    cout << ansMax << endl;
    outv(ans);

    return 0;
}
