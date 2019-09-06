def subarraySort(arr):
    # [1, 2, 3, 6, 5, 8 0]
    firstMessUp, secondMessUp = None, None
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            firstMessUp = i
            break
    for i in range(len(arr) - 1, 0, -1):
        if arr[i - 1] > arr[i]:
            secondMessUp = i
            break
    if firstMessUp is None or secondMessUp is None: # firstMessUp
        return [-1, -1]
    arrMessedUp = arr[firstMessUp: secondMessUp + 1]
    minima = min(arrMessedUp)
    maxima = max(arrMessedUp)
    startIdx, endIdx = -1, -1
    for i in range(len(arr)):
        if minima < arr[i]:
            startIdx = i
            break
    for i in range(len(arr) -1, - 1, -1):
        if maxima > arr[i]:
            endIdx = i
            break
    return [startIdx, endIdx]

import unittest

class TestProgram(unittest.TestCase):
    def test_case_1(self):
        self.assertEqual(subarraySort([1, 2]), [-1, -1])

    def test_case_2(self):
        self.assertEqual(subarraySort([2, 1]), [0, 1])

    def test_case_3(self):
        self.assertEqual(subarraySort([1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]), [3, 9])

    def test_case_4(self):
        self.assertEqual(subarraySort([1, 2, 4, 7, 10, 11, 7, 12, 7, 7, 16, 18, 19]), [4, 9])

unittest.main()
