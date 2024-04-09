#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

bool all_even(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() { 
    int N;
    cin >> N;
    vector<int> nums;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    while (all_even(nums)) {
        for (int i = 0; i < N; i++) {
            nums[i] /= 2;
        }
        count++;
    }
    cout << count << endl;
}
