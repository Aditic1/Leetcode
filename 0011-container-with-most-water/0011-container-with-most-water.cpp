class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int left = 0, right = height.size() - 1;

        while (left < right){
            int current_area = min(height[left], height[right]) * (right - left);
            answer = max(answer, current_area);
            (height[left]<=height[right])?left++:right--;
        }
        return answer;
    }
};