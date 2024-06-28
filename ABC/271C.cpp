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
    vll A(N);
    map<ll, ll> mp;
    rep(i, N) {
        ll input;
        cin >> input;
        if (mp.count(input) > 0) {
            A.at(i) = INF;
        } else {
            mp[input] = 1;
            A.at(i) = input;
        }
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    ll idx = 0;
    while (1) {
        if (idx >= A.size()) {
            break;
        }
        if (A.at(idx) == ans + 1) {
            ans++;
            idx++;
            continue;
        }
        if (A.size() - idx < 2) {
            break;
        }
        A.pop_back();
        A.pop_back();
        ans++;
    }
    cout << ans << endl;

    return 0;
}
