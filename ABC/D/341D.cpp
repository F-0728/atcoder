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
    ll N, M, K;
    cin >> N >> M >> K;
    ll q = (N * M) / gcd(N, M);
    ll l = 0;
    ll r = INF;
    ll mid = (l + r) / 2;
    while (r - l > 1){
        if ((mid / N) + (mid / M) - 2 * (mid / q) < K) {
            l = mid;
        } else {
            r = mid;
        }
        mid = (l + r) / 2;
    }
    cout << r << endl;

    return 0;
}
