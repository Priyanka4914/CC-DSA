class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Count how many tasks have maximum frequency
        int maxCount = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        // Formula
        int answer = (maxFreq - 1) * (n + 1) + maxCount;

        // We cannot have answer smaller than total tasks
        return max(answer, (int)tasks.size());
    }
};