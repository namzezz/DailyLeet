class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> m;

        for (int i : hand) {
            m[i]++;
        }

        for (int i = 0; i < hand.size(); i++) {

            if (m[hand[i]] == 0)
                continue;

            else {

                for (int j = 0; j < groupSize; j++) {
                    int grp = hand[i] + j;
                    if (m[grp] == 0)
                        return false;
                    m[grp]--;
                }
            }
        }

        return true;
    }
};