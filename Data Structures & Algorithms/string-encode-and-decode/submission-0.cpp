class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));
            j++; // skip '#'

            res.push_back(s.substr(j, len));
            i = j + len;
        }

        return res;
    }
};