class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        double ans;
        for(int i:nums1){
            nums.push_back(i);
        }
        for(int j:nums2){
            nums.push_back(j);
        }
        sort(nums.begin(), nums.end());
        int n= nums.size();
        cout<<n;
        if(n%2==0){
            ans =(double)(nums[n/2] + nums[(n-1)/2])/2;
        }
        else {
            ans = nums[(n-1)/2];
        }
        return ans;
    }
};
