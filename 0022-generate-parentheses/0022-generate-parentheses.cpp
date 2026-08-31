class Solution {
public:

void Paran(int open , int close , int n , string res, vector<string>&ans){
    if(open == n && close == n){
        ans.push_back(res);
        return;
    }
    if(open < n ) Paran(open + 1 , close , n , res + "(" , ans);
    if(close < open) Paran(open , close + 1 , n , res +")" , ans);
}

vector<string> generateParenthesis(int n) {
   vector<string>ans;
   string res;
   Paran(0 , 0 , n ,res, ans);
   return ans;
}
};