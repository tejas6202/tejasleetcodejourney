class Solution {
public:
    void Combo(string digits, int index, vector<string>& ans, string mapping[],
               string output) {

        if (index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            Combo(digits, index + 1, ans, mapping, output);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        string mapping[10] = {" ",   " ",   "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        Combo(digits, 0, ans, mapping, output);
        return ans;
    }
};