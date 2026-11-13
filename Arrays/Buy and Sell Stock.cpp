class Solution {
	public:
	int maxProfit(vector<int> &prices) {
		int result = 0;
		int minBuy = prices[0];
		
		for (int i = 0; i<prices.size(); i++)
			{
			minBuy = min(minBuy, prices[i]);
			
			result = max(result, prices[i]-minBuy);
		}
		
		return result;
		
	}
};
