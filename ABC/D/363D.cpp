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
    ll N;
    cin >> N;
    if (N <= 10) {
        cout << N - 1 << endl;
        return 0;
    }
    if (N <= 19) {
        ll ans = (N + 1) % 10;
        cout << ans * 11 << endl;
        return 0;
    }
    ll max = 90;
    ll count = 3;
    N -= 19;
    while (N - max >= 0) {
        N -= max;
        if (count % 2 == 0) {
            max *= 10;
        }
        count++;
    }

    ll rem = N - max;
    ll ans = 1;
    rep(i, ceil(count / 2.0)) { ans *= 10; }
    ans += rem - 1;
    string ansS = to_string(ans);
    ll half = ansS.size();
    if (count % 2 == 0) {
        rep(i, half) { ansS += ansS.at(half - 1 - i); }
    } else {
        rep(i, half - 1) { ansS += ansS.at(half - 2 - i); }
    }
    cout << ansS << endl;

    return 0;
}
