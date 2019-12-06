// https://leetcode.com/problems/largest-number/
// Given a list of non negative integers, arrange them such that they form the largest number.

// Input: [3,30,34,5,9]
// Output: "9534330"

// Time complexity : O(nlgn)
// Space complexity: O(n)
class Solution {
public:
    //this compare function returns the bigger value formed after appending two numbers
    struct StringComp{
        bool operator()(const string s1, const string s2) {
            string one2=s1+s2;
            string two1=s2+s1;
            
            return one2>two1;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> nstr;
        for(int i=0;i<nums.size();i++) {
            nstr.push_back(to_string(nums[i]));
        }
        
        sort(nstr.begin(), nstr.end(), StringComp());
        string result="";
        for(int i=0;i<nstr.size();i++) {
            result+=nstr[i];
        }

        //special case for [0,....0]
        //for reducing all 0 string to single 0
        int i=0;
        while(result[i]=='0') i++;
        if(i==result.size()) return "0";
        
        return result;
    }
};