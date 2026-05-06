class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int left = 0;
        int right = height.size()-1;
        int leftMax= 0;
        int rightMax = 0;
        while(left<=right){
            if(height[left]<height[right]){
                if(height[left]>leftMax){
                    leftMax= max(leftMax, height[left]);
                }else{
                    water += leftMax - height[left];
                }
                left++;
            }else if(height[left]>=height[right]){
                if(height[right]>rightMax){
                    rightMax= max(rightMax, height[right]);
                }else{
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};
