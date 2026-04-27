class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    int n = nums.size();

    // left and right pointers for the window
    int left = 0, right = k - 1;

    while (right < n) {
        // find max in current window [left, right]
        int windowMax = nums[left];
        for (int i = left; i <= right; i++) {
            windowMax = max(windowMax, nums[i]);
        }
        result.push_back(windowMax);

        // slide window
        left++;
        right++;
    }

    return result;
    }
};
