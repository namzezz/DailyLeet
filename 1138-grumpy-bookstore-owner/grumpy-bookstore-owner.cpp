class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }

        int maxsum = 0;
        int rsum = 0;

        for (int i = 0; i <= customers.size() - minutes; i++) {
            for (int j = i; j < i + minutes; j++) {
                //if he wasnt grumpy at this index then additional sum ye hota
                if (grumpy[j] == 1) {
                    rsum += customers[j];
                }
            }
            if (rsum > maxsum) {
                maxsum = rsum;
            }
            rsum = 0;
        }

        return sum + maxsum;
    }
};
