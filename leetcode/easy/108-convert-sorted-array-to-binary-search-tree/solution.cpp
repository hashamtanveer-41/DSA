/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convertArrayToBST(vector<int>& nums, int left, int right) {
   if (left>right)return nullptr;
    int mid = ((right + left) /2);
    TreeNode* root = new TreeNode(nums[mid]);
    root->right = convertArrayToBST(nums, mid+1, right);
    root->left = convertArrayToBST(nums, left, mid-1);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    return convertArrayToBST(nums, 0, n-1);
}
};