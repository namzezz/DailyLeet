struct item {
    int profit;
    int capital;
};

class Solution {
public:
    static bool comp(item a, item b) { return a.capital < b.capital; }

    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<item> items(n);

        for (int i = 0; i < n; i++) {
            items[i].profit = profits[i];
            items[i].capital = capital[i];
        }

        sort(items.begin(), items.end(), comp);

        priority_queue<int> maxProfit;
        int index = 0;

        for (int i = 0; i < k; i++) {
            while (index < n && items[index].capital <= w) {
                maxProfit.push(items[index].profit);
                index++;
            }

            if (maxProfit.empty()) {
                break;
            }

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};



/*Sure, let's walk through an example to visualize how the max-heap (priority queue) works in this context. 

### Example

Suppose we have the following projects:

- Profits: `[1, 2, 3, 5]`
- Capital: `[0, 1, 1, 2]`
- Initial capital: `w = 0`
- Maximum number of projects: `k = 3`

### Step-by-Step Execution

1. **Initialization**:
   - Combine profits and capital into a vector of items:
     ```
     items = [{profit: 1, capital: 0}, {profit: 2, capital: 1}, {profit: 3, capital: 1}, {profit: 5, capital: 2}]
     ```
   - Sort items by capital in ascending order:
     ```
     items = [{profit: 1, capital: 0}, {profit: 2, capital: 1}, {profit: 3, capital: 1}, {profit: 5, capital: 2}]
     ```
   - Initialize an empty max-heap (priority queue) for profits:
     ```
     maxProfit = []
     ```

2. **First Iteration (`k = 3`)**:
   - Current capital `w = 0`
   - Add all projects that can be started with `w = 0` to the max-heap:
     - Project with profit 1 and capital 0:
       ```
       maxProfit = [1]
       ```
   - Select the most profitable project (top of the max-heap):
     ```
     w += maxProfit.top()  // w = 0 + 1 = 1
     maxProfit.pop()       // maxProfit = []
     ```
   - Decrement `k`:
     ```
     k = 2
     ```

3. **Second Iteration (`k = 2`)**:
   - Current capital `w = 1`
   - Add all projects that can be started with `w = 1` to the max-heap:
     - Project with profit 2 and capital 1:
       ```
       maxProfit = [2]
       ```
     - Project with profit 3 and capital 1:
       ```
       maxProfit = [3, 2]
       ```
   - Select the most profitable project (top of the max-heap):
     ```
     w += maxProfit.top()  // w = 1 + 3 = 4
     maxProfit.pop()       // maxProfit = [2]
     ```
   - Decrement `k`:
     ```
     k = 1
     ```

4. **Third Iteration (`k = 1`)**:
   - Current capital `w = 4`
   - Add all projects that can be started with `w = 4` to the max-heap:
     - Project with profit 5 and capital 2:
       ```
       maxProfit = [5, 2]
       ```
   - Select the most profitable project (top of the max-heap):
     ```
     w += maxProfit.top()  // w = 4 + 5 = 9
     maxProfit.pop()       // maxProfit = [2]
     ```
   - Decrement `k`:
     ```
     k = 0
     ```

### Result

The final capital after selecting the most profitable projects up to `k` times is `w = 9`.

### Summary

- The max-heap allows us to efficiently select the most profitable project we can afford at each step.
- By sorting the projects by capital requirements and using a max-heap for profits, we ensure that at each step, we only consider projects that we can start with the current capital and always pick the most profitable one available.
*/