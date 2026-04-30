class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
      }  
      for(auto key : mp){
        if(key.second>1){
            return key.first;
        }
      }
      return -1;
    }
};
