 
#include <climits>

long getTrappedWater(long *arr, int n){

    //Reference point.
    int peak = 0;

    // Result.
    long ans = 0L;


    if (n == 0) {
        return 0L;
    }

    long peakVal = arr[0];

    // Moving left to right.
    for (int i = 0; i < n; i++) {
        if (arr[i] >= peakVal) {
            peak = i;
            peakVal = arr[i];
        }
    }

    // Initialising a min value.
    long maxSoFar = LONG_MIN;
    long countSubmerged = 0L;
    long submergedArea = 0L;

    // Traversing over a peak.
    for (int i = 0; i <= peak; i++) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    // Initialising a min value.
    maxSoFar = LONG_MIN;
    countSubmerged = 0L;
    submergedArea = 0L;

    // Moving right to left.
    for (int i = n - 1; i >= peak; i--) {
        if (arr[i] >= maxSoFar) {

            // Calculation.
            ans += (countSubmerged * maxSoFar - submergedArea);
            maxSoFar = arr[i];
            countSubmerged = 0L;
            submergedArea = 0L;
        }

        else {
            submergedArea += arr[i];
            countSubmerged++;
        }
    }

    return ans;
}
