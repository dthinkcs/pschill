function twoNumberSum(arr, targetNumber) {
    var seen = {};
    for (var n of arr) {
        if ((targetNumber - n) in seen) {
            var twoNums = [n, targetNumber - n];
            twoNums.sort(function (val1, val2) {return Number(val1) - Number(val2)});
            return twoNums;
        }
        seen[n] = twoNums;
    }
    return [];
}



console.log(twoNumberSum([1, 2, 3, 4, 5, 6], 6));
