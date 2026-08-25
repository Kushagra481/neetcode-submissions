class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequencies
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Store {frequency, number}
        vector<pair<int, int>> freq;

        for(auto c : mp) {
            freq.push_back({c.second, c.first});
        }

        // Sort by frequency
        sort(freq.rbegin(), freq.rend());

        vector<int> result;

        for(int i = 0; i < k; i++) {
            result.push_back(freq[i].second);
        }

        return result;
    }
};