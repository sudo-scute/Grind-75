// basically find the first occurrence of element
int firstBadVersion(int n) {
    int s = 1;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        if (isBadVersion(mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
