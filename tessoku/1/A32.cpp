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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<bool> dp(N + 1, false);
    rep(i, N + 1) {
        if (i >= A && !dp.at(i - A)) {
            dp.at(i) = true;
        }
        if (i >= B && !dp.at(i - B)) {
            dp.at(i) = true;
        }
    }
    if (dp.at(N)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    // outv(dp);

    return 0;
}
