class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit =0;
        int min =prices[0];
        for (int i=1;i<prices.size();i++){
            if(min>=prices[i]){
                min = prices[i];
            }else{
                maxprofit= max(maxprofit , prices[i]-min);
            }
        }
        return maxprofit;
    }
};
