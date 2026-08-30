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
    TreeNode* deleteNodeWithKey(TreeNode* root, int key) {
    if (root==nullptr)return nullptr;
    if (root->val==key) {
        // Node has 0 children
        if (root->left ==nullptr && root->right == nullptr) {
            root = nullptr;
        }
        // If 0 children its leaf node, it should point to nullptr
        // Node has 1 children
        // Replace the node with the one children having value
        else if (root->left !=nullptr &&root-> right ==nullptr) {
            root = root->left;
        }
        else if ( root-> right !=nullptr &&  root-> left ==nullptr) {
            root = root -> right;
        }
        // Node has 2 children
        // find the lowest number in right subtree and then swap it to root and delete that last node
        else {
            TreeNode* temp = root->right;
            while (temp->left!=nullptr) {
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNodeWithKey(root->right, temp->val);
        }
    }
    else if (root->val>key) {
       root->left =  deleteNodeWithKey(root->left, key);
    }else {
        root->right =  deleteNodeWithKey(root->right, key);
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    return deleteNodeWithKey(root, key);
}
};