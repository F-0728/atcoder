#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    unordered_map<ll, ll> hash;
    rep(i, N) cin >> a[i];
    ll left = 0, right = 0;
    ll ans = 0;
    ll counter = 0;
    while (right < N) {
        hash[a[right]]++;
        while (hash.size() > K) {
            hash[a[left]]--;
            if (hash[a[left]] == 0) {
                hash.erase(a[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }

    cout << ans << endl;

    return 0;
}
