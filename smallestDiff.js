function smallestDifference(arr1, arr2) {
  arr1.sort(function(a, b) {return a - b})
  arr2.sort(function(a, b) {return a - b})

  var minDiffSoFar = Infinity
  var theTwoNumbers = []
  for (var i1 = 0, i2 = 0; i1 < arr1.length && i2 < arr2.length; )
  {
    var currDiff = Math.abs(arr1[i1] - arr2[i2])
    if (currDiff < minDiffSoFar) {
      minDiffSoFar = currDiff
      theTwoNumbers = [arr1[i1], arr2[i2]]
    }

    if (arr1[i1] == arr2[i2]) {
      return [arr1[i1], arr2[i2]]
    }
    else if (arr1[i1] < arr2[i2]) {
      i1++
    }
    else {
      i2++
    }
  }
  return theTwoNumbers
}

console.log( smallestDifference([10, 0, 20, 25, 2200], [1005, 1006, 1014, 1032, 1031]) ) // [25, 1005]))
