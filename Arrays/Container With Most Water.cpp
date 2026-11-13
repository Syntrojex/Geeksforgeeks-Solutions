class Solution {
	public:
	int maxWater(vector<int> &arr) {
		int currWater = 0;
		int maxWater = 0;
		
		int left = 0;
		int right = arr.size() - 1;
		
		while (left<right)
			{
			int width = right - left;
			
			int height = min(arr[left], arr[right]);
			
			currWater = width*height;
			
			maxWater = max(maxWater, currWater);
			
			if (arr[left]<arr[right])
				{
				left++;
			}
			
			else
				{
				right--;
			}
		}
		
		return maxWater;
		
	}
};
