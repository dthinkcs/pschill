// TLE 
// 9
// 75 131 977 305 220 957 47 56 840
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool fn(int* arr, int n, int sumByTwo, map<pair<int, int>, int>& memo, int sumSoFar = 0) 
{
    if (memo.count({sumSoFar, n}) != 0) {
        return memo[{sumSoFar, n}];
    }

    if (sumSoFar > sumByTwo) {
        //return false;
        memo[{sumSoFar, n}] = false;
        return false;
    }

    if (sumSoFar == sumByTwo) {
        // return true;
        memo[{sumSoFar, n}] = true;
        return true;
    }
    
    if (n == 0) {
        return false;
    }
    // leave it or take it
    memo[{sumSoFar, n}] = fn(arr + 1, n - 1, sumByTwo, memo, sumSoFar) 
            || fn(arr + 1, n - 1, sumByTwo, memo, sumSoFar + arr[0]);
    return memo[{sumSoFar, n}];
}

int main() {
	// code CORNER CASE CONSIDER empty array
	int T;
	cin >> T;
	while (T--) {
    	int n;
    	cin >> n;
    	int arr[101];
    	for (int i = 0; i < n; i++) {
    	    cin >> arr[i];
    	}
    	int total = accumulate(arr, arr + n, 0);
    	map<pair<int, int>, int> memo;
    	if (total % 2 != 0) {
    	    cout << "NO" << endl;
    	}
    	else if (fn(arr, n, total / 2, memo)) {
    	    cout << "YES" << endl;
    	} else {
    	    cout << "NO" << endl;
    	}
	}
	return 0;
}
