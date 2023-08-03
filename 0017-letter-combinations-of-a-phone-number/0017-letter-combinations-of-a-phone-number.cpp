class Solution {
public:
    void solve(int idx,vector<string>&ans,string &digits,unordered_map<char,string>mp,string &temp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string var1 = mp[ch];
        for(int i = 0 ; i < var1.size() ; i++){
            temp.push_back(var1[i]);
            solve(idx+1,ans,digits,mp,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map<char,string> mp;
        vector<string> ans;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        solve(0,ans,digits,mp,temp);

        return ans;
        
    }
};