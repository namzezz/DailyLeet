class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        
        // Initialize the total waiting time and the current time
        long long total_waiting_time = 0;
        int current_time = 0;

        for (int i = 0; i < n; ++i) {
            // Get the arrival time and processing time of the current customer
            int arrival_time = customers[i][0];
            int processing_time = customers[i][1];

            // Update the current time to be the max of the arrival time and current time
            current_time = max(current_time, arrival_time) + processing_time;

            // Calculate the waiting time for the current customer
            total_waiting_time += (current_time - arrival_time);
        }

        // Return the average waiting time
        return (double)total_waiting_time / n;
    }
};