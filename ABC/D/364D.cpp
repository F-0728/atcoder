#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace atcoder;

using ll = long long;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>

int main() {
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    vector<pll> query(Q);
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        query.at(i) = make_pair(x, y);
    }

    vll ans(Q);
    rep(i, Q) {
        ll b = query.at(i).first;
        ll k = query.at(i).second;

        if (lower_bound(A.begin(), A.end(), b) == A.end()) {
            ans.at(i) = b - A.at(N - k);
            continue;
        } else if (upper_bound(A.begin(), A.end(), b) == A.begin()) {
            ans.at(i) = A.at(k - 1) - b;
            continue;
        }

        ll l = 0, r = INF;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll left = lower_bound(A.begin(), A.end(), b - mid) - A.begin();
            ll right = upper_bound(A.begin(), A.end(), b + mid) - A.begin();
            ll count = right - left;

            if (count >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ll left = A.at(lower_bound(A.begin(), A.end(), b - r) - A.begin());
        ll right = A.at(upper_bound(A.begin(), A.end(), b + r) - A.begin() - 1);
        ans.at(i) = max(abs(left - b), abs(right - b));
    }

    rep(i, Q) {
        cout << ans[i] << endl;
    }

    return 0;
}
