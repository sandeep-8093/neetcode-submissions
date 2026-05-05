class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int index, vector<int>& temp) {
        // Base case
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);

            // Stay at same index (reuse allowed)
            backtrack(candidates, target - candidates[i], i, temp);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtrack(nums, target, 0, temp);
        return result;
    }
};
