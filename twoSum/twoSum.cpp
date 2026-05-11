#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    // 在数组中找到和为 target 的两个数，返回它们的下标
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // 值 -> 下标
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            // 检查另一半是否已经在哈希表中
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            // 将当前值和下标存入哈希表
            map[nums[i]] = i;
        }
        return {};
    }
};

// 测试辅助函数
void runTest(Solution& sol, vector<int> nums, int target, vector<int> expected) {
    auto result = sol.twoSum(nums, target);
    bool pass = (result == expected) ||
                (result.size() == 2 &&
                 result[0] == expected[1] &&
                 result[1] == expected[0]);
    cout << "nums = [";
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i) cout << ", ";
        cout << nums[i];
    }
    cout << "], target = " << target << " => ["
         << result[0] << ", " << result[1] << "] "
         << (pass ? "PASS" : "FAIL") << endl;
}

int main() {
    Solution sol;

    // 5 组测试用例
    runTest(sol, {2, 7, 11, 15}, 9, {0, 1});
    runTest(sol, {3, 2, 4}, 6, {1, 2});
    runTest(sol, {3, 3}, 6, {0, 1});
    runTest(sol, {1, 5, 9, 3}, 8, {1, 3});
    runTest(sol, {0, 4, -2, 6}, 4, {0, 1});
}
