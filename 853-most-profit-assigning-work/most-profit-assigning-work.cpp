class Solution {
public:
    struct diffpro {
        int diffi;
        int profit;
    };

    static bool comp(diffpro val1, diffpro val2) {
        return val1.diffi < val2.diffi;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<diffpro> labour(difficulty.size());
        for (int i = 0; i < labour.size(); i++) {
            labour[i].diffi = difficulty[i];
            labour[i].profit = profit[i];
        }

        sort(labour.begin(), labour.end(), comp);

        sort(worker.begin(), worker.end());

        int totalProfit = 0, maxProfit = 0, j = 0;

        for (int i = 0; i < worker.size(); i++) {
            while (j < labour.size() && labour[j].diffi <= worker[i]) {
                maxProfit = max(maxProfit, labour[j].profit);
                j++;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};