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

vll nums;
ll MAX = 1e10;

void addNum() {
    queue<ll> q;
    q.push(0);
    while (!q.empty()) {
        ll n = q.front();
        q.pop();
        if (n > 0) {
            nums.push_back(n);
        }
        if (n < MAX) {
            q.push(n * 10 + 3);
            q.push(n * 10 + 5);
            q.push(n * 10 + 7);
        }
    }
}

int main() {
    ll N;
    cin >> N;
    addNum();
    ll ans = 0;
    rep(i, nums.size()) {
        string numstr = to_string(nums[i]);
        if (numstr.find("3") == string::npos) nums[i] = MAX;
        if (numstr.find("5") == string::npos) nums[i] = MAX;
        if (numstr.find("7") == string::npos) nums[i] = MAX;
    }
    sort(nums.begin(), nums.end());
    rep(i, nums.size()) {
        if (nums[i] > N) {
            cout << ans << endl;
            return 0;
        }
        // cout << nums[i] << endl;
        ans++;
    }
    

    return 0;
}
