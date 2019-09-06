function subarraySort(arr) {
  var firstMessUp = null;
  for (var i = 0; i < arr.length - 1; i++) {
    if (arr[i] > arr[i + 1] ) {
      firstMessUp = i;
      break;
    }
  }

  var secondMessUp = null;
  for (var i = arr.length - 1; i >= 1; i--) {
    if (arr[i - 1] > arr[i]) {
      secondMessUp = i;
    }
  }

  if (firstMessUp === null || secondMessUp === null) {
    return [-1, -1];
  }

  var arrMessedUp = arr.slice(firstMessUp, secondMessUp + 1);
  // ES6 syntax
  const minima = Math.min(...arrMessedUp)
  const maxima = Math.max(...arrMessedUp)
  var firstIdx = -1;
  var secondIdx = -1;
  for (let i = 0; i < arr.length; i++) {
    if (minima < arr[i]) {
      firstIdx = i; // BUG firstIdx = minima
      break;
    }
  }

  for (let i = arr.length - 1; i >= 0; i--) {
    if (maxima > arr[i]) {
      secondIdx = i;
      break;
    }
  }
  return [firstIdx, secondIdx];
}

console.log(subarraySort([2, 1])) // [0, 1])
console.log(subarraySort([1, 2, 4, 7, 10, 11, 7, 12, 7, 7, 16, 18, 19])) // [4, 9])
