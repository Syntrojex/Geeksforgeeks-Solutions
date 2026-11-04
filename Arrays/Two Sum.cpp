class Solution {
	public:
	bool twoSum(vector<int>& arr, int target) {
		
		sort(arr.begin(), arr.end());
		
		int left = 0;
		int right = arr.size() - 1;
		
		while (left < right)
			{
			if (arr[left]+arr[right] == target)
				{
				return true;
			}
			
			else if (arr[left]+arr[right]<target)
				{
				left++;
			}
			
			else
				{
				right--;
			}
		}
		
		return false;
	}
};
