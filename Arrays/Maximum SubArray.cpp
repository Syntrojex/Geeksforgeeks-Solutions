// Kadane Algorithm

class Solution {
	public:
	int maxSubarraySum(vector<int> &arr) {
		int currSum = 0;
		int maxSum = INT_MIN;
		
		for (int i = 0; i<arr.size(); i++)
			{
			currSum += arr[i];
			
			maxSum = max(currSum, maxSum);
			
			// kio k array me negative elements b ho skte hain or currSum -ve  ja skta ha isi liye negative krne se acha 0 rk diya
			if (currSum<0)
				{
				currSum = 0;
			}
		}
		
		return maxSum;
		
	}
};
