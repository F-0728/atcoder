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
    ll N, K;
    cin >> N >> K;
    vvll students(5005, vll(5005, 0));
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        students.at(a).at(b)++;
    }
    rep(i, 5005) {
        rep(j, 5004) { students.at(i).at(j + 1) += students.at(i).at(j); }
    }
    rep(i, 5004) {
        rep(j, 5005) { students.at(i + 1).at(j) += students.at(i).at(j); }
    }
    ll ans = 0;
    rep(i, 5001) {
        rep(j, 5001) {
            ans = max(ans,
                      students.at(i).at(j) - students.at(min(i + K + 1, 5000LL)).at(j) -
                          students.at(i).at(min(j + K + 1, 5000LL)) +
                          students.at(min(i + K + 1, 5000LL)).at(min(j + K + 1, 5000LL)));
        }
    }
    cout << ans << endl;
    return 0;
}
