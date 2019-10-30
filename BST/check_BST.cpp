//https://leetcode.com/problems/validate-binary-search-tree/
//1,2 submited
//More solutions: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

//1. Check the inorder traversal, if the previouslt traversed in less than the current
//While dealing with int ranges, considering INT_MIN and INT_MAX was giving errors as if you want to so something when value goes to
//INF+1(it is converted to INF_MIN) and -INF-1(converted to INF_MAX). So long takes the argument as it is.
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

//2. Using min max while traversing
//Concept is, if you are going to left, then the allowed range of the node changes to [parent's min, parent's value -1]
//Same goes for right node, allowed range is, [parent's value +1, parent's max]
//For root, any value is welcomed so, the range is [-INF, +INF].
//While dealing with int ranges, considering INT_MIN and INT_MAX was giving errors as if you want to so something when value goes to
//INF+1(it is converted to INF_MIN) and -INF-1(converted to INF_MAX). So long takes the argument as it is.
//Time  : n
//Space : n, due to recursive solution

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
    bool checkBST(TreeNode* node, long min, long max) {
        
        if(node == NULL) return true;
        
        if(node->val < min || node->val > max) return false;
        
        bool isLeftBST, isRightBST;
        isLeftBST = checkBST(node->left, (long)min, (long)node->val-1);
        if(!isLeftBST) return false;
        isRightBST = checkBST(node->right, (long)node->val+1, (long)max);
        if(!isRightBST) return false;
        
        return true;
    }
};

//3. Someone did the above in one line

bool isValidBST(TreeNode* n, long lo = LONG_MIN, long hi = LONG_MAX) {
	return !n || (n->val > lo && n->val < hi && isValidBST(n->left, lo, n->val) && isValidBST(n->right, n->val, hi));
}