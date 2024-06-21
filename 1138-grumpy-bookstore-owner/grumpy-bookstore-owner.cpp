class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentWindowSatisfaction = 0;

        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSatisfaction += customers[i];
            } else if (i < minutes) {
                currentWindowSatisfaction += customers[i];
            }
        }

        maxExtraSatisfaction = currentWindowSatisfaction;

        for (int i = minutes; i < customers.size(); ++i) {
            currentWindowSatisfaction += customers[i] * grumpy[i];
            // take care of duplicates when sliding window, for eg in
            // 1,2,3,4,5,6 if we calculate till i=2 that is 1,2,3 and move
            // window to right by 1 index then 2,3,4 will be in the window but
            // the sum of 2 and 3 might have already be added
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
            maxExtraSatisfaction = max(maxExtraSatisfaction, currentWindowSatisfaction);
        }

        return initialSatisfaction + maxExtraSatisfaction;
    }
};