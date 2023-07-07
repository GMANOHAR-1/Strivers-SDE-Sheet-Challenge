 
int singleNonDuplicate(vector<int>& arr)
{
    int n = arr.size();
    int low = 0, high = n - 1, mid;

    // Do binary search
    while (low < high) {

        // Calculate mid
        mid = (low + high) / 2;

        // Update low and high
        if ((mid % 2 == 1 and arr[mid] == arr[mid - 1]) or (mid % 2 == 0 and arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return arr[low];
}
