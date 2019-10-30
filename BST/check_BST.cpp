// https://leetcode.com/problems/validate-binary-search-tree/


//1. Check the inorder traversal, if the previouslt traversed in less than the current
//Time  : n
//Space : n, due to recursive solution
class Solution {
public:
    long prev = LONG_MIN;
    bool isValidBST(TreeNode* node) {
        if(node==NULL) return true;
        if(!isValidBST(node->left)) return false;
        if(prev>=node->val) return false;
        else prev = node->val;
        if(!isValidBST(node->right)) return false;
        return true;
    }
};