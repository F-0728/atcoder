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

vpll nums;
vll minSteps(1000005, INF);
void rotate(ll x, ll hand) {
    ll pow = 1;
    ll s = to_string(x).size();
    rep(i, s - 1) { pow *= 10; }
    rep(i, s - 1) {
        x = x / pow + (x % pow) * 10;
        if (x / pow > 0 && minSteps.at(x) > hand + i + 1) {
            nums.push_back({x, hand + i + 1});
            minSteps.at(x) = min(minSteps.at(x), hand + i + 1);
        } else
            return;
    }
}

int main() {
    ll a, N;
    cin >> a >> N;
    nums.push_back({N, 0});
    rotate(N, 0);
    minSteps.at(N) = 0;
    // outv(nums);
    ll ans = INF;
    while (!nums.empty()) {
        pll p = nums.back();
        nums.pop_back();
        ll num = p.first;
        ll hand = p.second;
        if (num == 1) {
            ans = min(ans, hand);
            continue;
        }
        rotate(num, hand);
        if (num % a == 0 && minSteps.at(num / a) > hand + 1) {
            nums.push_back({num / a, hand + 1});
            minSteps.at(num / a) = min(minSteps.at(num / a), hand + 1);
        }
        // rep(i, nums.size()) {
        //     cout << nums[i].first << " " << nums[i].second << endl;
        // }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
