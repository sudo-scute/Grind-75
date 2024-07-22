int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            int curr = (min(height[i], height[j]) * (j - i));
            ans = max(ans, curr);
            if (height[i] < height[j]) {
                i++;
            } else if (height[i] > height[j]) {
                j--;
            } else {
                i++;
                j--;
            }
        }
        return ans;
}
