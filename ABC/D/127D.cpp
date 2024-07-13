#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A[i];

    vpll additional(M);
    rep(i, M) {
        ll B, C;
        cin >> B >> C;
        additional[i] = make_pair(C, B);
    }

    sort(additional.begin(), additional.end(), greater<pair<ll, ll>>());
    sort(A.rbegin(), A.rend());

    ll ans = 0;
    ll counter = 0;
    ll idx1 = 0, idx2 = 0;
    while (counter < N) {
        if (idx2 >= M) {
            ans += A[idx1];
            counter++;
            idx1++;
            continue;
        }
        if (A[idx1] >= additional[idx2].first) {
            ans += A[idx1];
            counter++;
            idx1++;
            // cout << "current ans: " << ans << endl;
        } else {
            ans += additional[idx2].first * min(additional[idx2].second, N - counter);
            counter += min(additional[idx2].second, N - counter);
            idx2++;
        }
    }
    

    cout << ans << endl; 

    return 0;
}
