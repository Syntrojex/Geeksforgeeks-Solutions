/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	
	void inorder(Node*root, vector<int>&nums)
	{
		if (root == nullptr)
			{
			return;
		}
		
		inorder(root->left, nums);
		nums.push_back(root->data);
		inorder(root->right, nums);
	}
	
	bool isBST(Node* root) {
		vector<int> nums;
		
		inorder(root, nums);
		
		for (int i = 1; i<nums.size(); i++)
			{
			if (nums[i] <= nums[i - 1])
				{
				return false;
			}
		}
		
		return true;
		
	}
};

