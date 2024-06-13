class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        priority_queue<int> pq1, pq2;

        for (int i = 0; i < n; i++) {
            pq1.push(seats[i]);
            pq2.push(students[i]);
        }

        int count = 0;

        while (!pq1.empty()) {
            int top1 = pq1.top();
            int top2 = pq2.top();
            count += abs(top2 - top1);
            pq1.pop();
            pq2.pop();
        }

        return count;
    }
    
};