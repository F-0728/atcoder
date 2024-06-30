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

vector<string> S;
vll ans;
void calc(vector<ll> L, ll k) {
    if (L.size() == 1) {
        ans.at(L.at(0)) = k - 1;
        return;
    }
    if (L.size() == 0) return;
    vvll next(26);
    rep(i, L.size()) {
        if (S.at(L.at(i)).size() <= k) {
            ans.at(L.at(i)) = k;
            continue;
        }
        next.at(S.at(L.at(i)).at(k) - 'a').push_back(L.at(i));
    }
    rep(i, 26) {
        calc(next.at(i), k + 1);
    }
}

int main() {
    ll N;
    cin >> N;
    S.resize(N);
    rep(i, N) cin >> S.at(i);
    ll maxLen = 0;
    rep(i, N) maxLen = max(maxLen, (ll)S.at(i).size());
    ans.resize(N);
    vll start;
    rep(i, N) {
        start.push_back(i);
    }
    calc(start, 0);
    rep(i, N) {
        cout << ans.at(i) << endl;
    }

    return 0;
}
