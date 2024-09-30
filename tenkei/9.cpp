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
    vpll points(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double ans = 0;
    rep(i, N) {
        pll mid = points[i];
        vector<double> args;

        rep(j, N) {
            pll p = points[j];
            if (p == mid) continue;
            ll dx = p.first - mid.first;
            ll dy = p.second - mid.second;
            double arg = atan2(dy, dx) * 180 / M_PI;
            if (arg < 0) arg += 360;
            args.push_back(arg);
        }
        sort(args.begin(), args.end());

        ll M = args.size();
        rep(j, M) {
            double now = args[j];
            double next = args[j] + 180;
            if (next >= 360) next -= 360;
            ll idx1 =
                lower_bound(args.begin(), args.end(), next) - args.begin();
            ll idx2 =
                upper_bound(args.begin(), args.end(), next) - args.begin() - 1;
            if (idx1 == M) idx1 = 0;
            double arg1 = args[idx1] - now;
            if (arg1 < 0) arg1 += 360;
            if (arg1 > 180) arg1 = 360 - arg1;
            ans = max(ans, arg1);
            if (idx2 < 0) idx2 += M;
            double arg2 = args[idx2] - now;
            if (arg2 < 0) arg2 += 360;
            if (arg2 > 180) arg2 = 360 - arg2;
            ans = max(ans, arg2);
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
