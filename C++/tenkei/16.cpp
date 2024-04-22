#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    vector<ll> nums(3);
    rep(i, 3) { cin >> nums[i]; }
    sort(nums.rbegin(), nums.rend());
    ll A, B, C;
    A = nums[0];
    B = nums[1];
    C = nums[2];
    vector<ll> ans;

    for (int i = 9999; i >= 0; i--) {
        for (int j = 9999 - i; j >= 0; j--) {
            ll k = (N - (A * i + B * j)) / C;
            if (k >= 0 && (N - (A * i + B * j)) % C == 0) {
                ans.push_back(i + j + k);
            }
        }
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
    return 0;
}
