class Solution {
public:
    
    string encode(vector<string>& strs) {
        string encoded = "";

        for (int i = 0; i < strs.size(); i++) {
            encoded += to_string(strs[i].size());
            encoded += '#';
            encoded += strs[i];
        }

        return encoded;
    }

   
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {

            
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            
            j++;

            result.push_back(s.substr(j, len));

            i = j + len;
        }

        return result;
    }
};