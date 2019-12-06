// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// I could not come with an approach while solving it

// 1.
// The idea is to mark the path which is having either of the required nodes while doing a deplth first traversal
// so imgaine you are standing on the node and when you look below, you can only say that okay, this path has p, or q
// by looking at what traversal has returned.
// if both sides of the travesal, for a node, is returning the NOT NULL values, the  defth first traversal makes sure
// that it is also the lowest node that is common between retunned nodes. 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return (left!=NULL)?left:right;
    }
};