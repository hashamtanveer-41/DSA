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
int findLeftHeightOfTree(TreeNode* root) {
    if (root==nullptr)return 0;
    int left = findLeftHeightOfTree(root->left);
    return 1+ left;
}
bool reachSpecificNodeFromBits(TreeNode* root, int number, int h){
    if (root==nullptr)return false;
    if (h==0)return true;
    int leftmostBit = (number >> (h - 1)) & 1;
    if (leftmostBit==0) {
        return reachSpecificNodeFromBits(root->left,number, h-1);
    }
    return reachSpecificNodeFromBits(root->right, number, h-1);
}
int countNodes(TreeNode* root) {
    int h =  findLeftHeightOfTree(root) -1;
    int res = 0;
    // h is indexed form 0 to height or is level wise
    int range = pow(2, h)-1;
    int i = 0;
    while (i>=0 && i<=range) {
        int search = (i + range) /2;
        bool is = reachSpecificNodeFromBits(root, search, h);
        if (is) {
            i = search+1;
            res = max(res, 1+search);
        }else
            range = search -1;
    }
    for (int j= 0; j<h; j++) {
        res += pow(2, j);
    }
    return res;
}
};