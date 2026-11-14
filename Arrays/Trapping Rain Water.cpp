class Solution {
	public:
	int maxWater(vector<int> &arr) {
		
		int left = 0;
		int right = arr.size() - 1;
		
		int leftMax = 0;
		int rightMax = 0;
		
		int ans = 0;
		
		while (left<right)
			{
			leftMax = max(leftMax, arr[left]);
			rightMax = max(rightMax, arr[right]);
			
			if (leftMax<rightMax)
				{
				ans += min(leftMax, rightMax) - arr[left];
				left++;
			}
			
			else
				{
				ans += min(leftMax, rightMax) - arr[right];
				right--;
			}
		}
		
		return ans;
		
	}
};
