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
    vector<string> s(N);
    rep(i, N) {
        cin >> s[i];
    }
    string before = s[0];
    rep(i, N - 2) {
        string S = s[i + 1];
        if (before == "sweet") {
            if (S == "sweet" && i != N - 2) {
                No;
                return 0;
            }
        }
        before = S;
    }
    Yes;

    return 0;
}
