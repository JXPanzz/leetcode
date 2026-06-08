#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// LeetCode 128. Longest Consecutive Sequence
// Time: O(n), Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int ans = 0;

        for (int x : hash) {
            // 只从「序列起点」开始探索，避免重复
            if (hash.count(x - 1)) continue;

            int cur = x;
            while (hash.count(cur + 1)) {
                cur++;
            }
            ans = max(ans, cur - x + 1);
        }
        return ans;
    }
};

// ─── 测试 ───────────────────────────────────────────────
struct TestCase {
    vector<int> nums;
    int expected;
};

int main() {
    Solution s;
    vector<TestCase> tests = {
        {{100, 4, 200, 1, 3, 2},     4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2},                3},
        {{},                           0},
        {{5},                          1},
        {{1, 2, 3, 4, 5},             5},
        {{9, 1, -3, 2, 4, 8, 3, -1, 6, -2, 0, 7, 5}, 13},  // 包含负数，-3 到 9 共 13
    };

    bool allPass = true;
    for (int i = 0; i < (int)tests.size(); i++) {
        auto& t = tests[i];
        int result = s.longestConsecutive(t.nums);
        bool pass = (result == t.expected);
        if (!pass) allPass = false;

        cout << "Test " << i + 1
             << "  nums=[";
        for (int j = 0; j < (int)t.nums.size(); j++) {
            if (j) cout << ",";
            cout << t.nums[j];
        }
        cout << "]  expect=" << t.expected
             << "  output=" << result
             << "  " << (pass ? "PASS" : "FAIL") << endl;
    }

    cout << endl;
    if (allPass) {
        cout << "All " << tests.size() << " test cases passed!" << endl;
    } else {
        cout << "Some tests FAILED." << endl;
        return 1;
    }
    return 0;
}
