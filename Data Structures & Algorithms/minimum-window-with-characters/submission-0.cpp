class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Frequency of characters needed
        for (char c : t)
            need[c]++;

        int required = need.size(); // Number of distinct characters
        int formed = 0;

        int left = 0, right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            // Current character requirement satisfied
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try to shrink the window
            while (left <= right && formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                // Window is no longer valid
                if (need.count(ch) && window[ch] < need[ch])
                    formed--;

                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};