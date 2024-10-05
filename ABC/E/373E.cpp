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
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vll A(N);
    rep(i, N) cin >> A[i];

    ll rem = K;
    rep(i, N) rem -= A[i];

    if (N == M) {
        rep(i, N) {
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }

    vll idx(N);
    rep(i, N) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](ll i, ll j) {
        return A[i] < A[j];
    });
    sort (A.begin(), A.end());

    vll cSum(N + 1, 0);
    rep(i, N) {
        cSum[i + 1] = cSum[i] + A[i];
    }

    vll ans(N, -1);
    rep(i, N) {
        ll l = -1, r = rem + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll rIdx = upper_bound(A.begin(), A.end(), A[i] + mid) - A.begin();
            ll lIdx = N - M;
            if (i >= N - M) lIdx--;

            ll count = 0;
            if (rIdx > lIdx) {
                count += (rIdx - lIdx) * (A[i] + mid + 1) - (cSum[rIdx] - cSum[lIdx]);
            }
            if (lIdx <= i && i < rIdx) {
                count--;
            } else {
                count += mid;
            }
            if (count <= rem) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == rem) {
            ans[idx[i]] = -1;
        } else {
            ans[idx[i]] = r;
        }
    }

    rep(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
