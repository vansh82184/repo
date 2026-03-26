#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long hoursNeeded(vector<int>& piles, long long k) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k; 
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (hoursNeeded(piles, mid) <= h) {
                high = mid;        
            }
            else {
                low = mid + 1;     
            }
        }

        return low;
    }
};

int main() {
    Solution obj;

    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << "Minimum eating speed: " << obj.minEatingSpeed(piles, h);

    return 0;
}