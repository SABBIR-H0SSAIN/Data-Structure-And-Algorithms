// Problem Link: https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* findSuccessor(TreeNode* root){
        root=root->right;
        while(root && root->left) root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else{

            if(!root->left && !root->right) return nullptr;

            if(root->left &&!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            if(root->right && !root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }

            TreeNode* successor = findSuccessor(root);
            root->val = successor->val;
            root->right = deleteNode(root->right,successor->val);
            
        }

        return root;
    }
};
