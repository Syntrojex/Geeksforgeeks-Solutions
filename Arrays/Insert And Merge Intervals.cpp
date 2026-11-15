class Solution {
	public:
	vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
	vector<int> &newInterval) {
		
		int index = intervals.size();
		
		for (int i = 0; i<intervals.size(); i++)
			{
			if (newInterval[0]<intervals[i][0])
				{
				index = i;
				break;
			}
		}
		
		intervals.insert(intervals.begin() + index, newInterval);
		
		for (int i = 1; i<intervals.size();)
			{
			if (intervals[i - 1][1] >= intervals[i][0])
				{
				intervals[i - 1][0] = min(intervals[i - 1][0], intervals[i][0]);
				intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
				
				intervals.erase(intervals.begin() + i);
				
			}
			
			else
				{
				i++;
			}
		}
		
		return intervals;
	}
};
