class Solution {
public:
vector<vector<int>> result;
void backtrack(vector<int>& candidates, int target, int index, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            temp.push_back(candidates[i]);

            // Move to next index (no reuse)
            backtrack(candidates, target - candidates[i], i + 1, temp);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        backtrack(candidates, target, 0, temp);

        return result;
    }
};
