// https://leetcode.com/problems/binary-tree-right-side-view/

//1. Using a map for each level
//Time  : nLog(n)
//Space : n
class Solution {
public:
    map<int, int> m;
    vector<int> rightSideView(TreeNode* root) {
        fillViewMap(root, 0);
        vector<int> result;
        for(auto it=m.begin();it!=m.end();it++) {
            result.push_back(it->second);
        }
        
        return result;
    }
    
    void fillViewMap(TreeNode* node, int depth) {
        if(node==NULL) {
            return;
        }

        //if for a level, there is nothing filled then the first node to fall here is the rightest in the given level
        if(m[depth] == 0) {
            m[depth] = node->val; 
        }

        //for left view reverse two statements
        inorder(node->right, depth+1);
        inorder(node->left, depth+1);
    }
};


//2. Using a globalDepth
//Time  : n
//Space : n, for recursive calls
class Solution {
public:
    vector<int> result;
    int globalDepth = 0; 
    vector<int> rightSideView(TreeNode* root) {
        fillViewMap(root, 1);
        return result;
    }
    
    void fillViewMap(TreeNode* node, int localDepth) {
        if(node==NULL) {
            return;
        }
        
        //this will only encounter the nodes coming for the first time on a level
        if(localDepth > globalDepth) {
            result.push_back(node->val);
            globalDepth++;
        }

        //for left view reverse two statements
        inorder(node->right, localDepth+1);
        inorder(node->left, localDepth+1);
    }
};