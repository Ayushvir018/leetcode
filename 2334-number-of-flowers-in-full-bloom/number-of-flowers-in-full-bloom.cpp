
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {
        vector<int> starts, ends;

        for (auto& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> answer;

        for (int t : people) {
            int started = upper_bound(starts.begin(), starts.end(), t)
                          - starts.begin();

            int ended = lower_bound(ends.begin(), ends.end(), t)
                        - ends.begin();

            answer.push_back(started - ended);
        }

        return answer;
    }
};
