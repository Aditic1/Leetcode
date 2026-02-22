class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = height[0], rightMax = height[n-1];
        int totalCap = 0;

        while(left <= right){
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if(leftMax <= rightMax){
                totalCap+=max(0, leftMax - height[left]);
                left++;
            }else if(leftMax > rightMax){
                totalCap+=max(0, rightMax - height[right]);
                right--;
            }
        }
        return totalCap;
    }
};