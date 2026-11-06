class Solution {
	public:
	int missingNum(vector<int>& arr) {
		
		int n = arr.size() + 1;  // kio k size total count de raha jo n-1 hota ha 
		
		int actualSum = (n*(n + 1))/2;
		
		int sum = 0;
		
		for (int i :arr)
			{
			sum += i;
		}
		
		return actualSum - sum;
		
	}
};
