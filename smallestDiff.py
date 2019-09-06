def smallestDifference(arr1, arr2):
    # assuming arrays are not of size 0
    arr1.sort()
    arr2.sort()

    i1 = 0
    i2 = 0
    minDiffSoFar = float('inf')
    theTwoNumbers = []
    while i1 < len(arr1) and i2 < len(arr2):
        currDiff = abs(arr1[i1] - arr2[i2])
        if currDiff < minDiffSoFar:
            minDiffSoFar = currDiff
            theTwoNumbers = [arr1[i1], arr2[i2]]
        if arr1[i1] == arr2[i2]:
            return [arr1[i1], arr2[i2]]
        elif arr1[i1] < arr2[i2]:
            i1 += 1
        else:
            i2 += 1
    
    return theTwoNumbers

import unittest

class TestProgram(unittest.TestCase):

    def test_case_1(self):
        self.assertEqual(smallestDifference([-1, 5, 10, 20, 3], [26, 134, 135, 15, 17]), [20, 17])



    def test_case_2(self):
        self.assertEqual(smallestDifference([-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17]), [28, 26])



    def test_case_3(self):

        self.assertEqual(smallestDifference([10, 0, 20, 25], [1005, 1006, 1014, 1032, 1031]), [25, 1005])

    def test_case_4(self):
        self.assertEqual(smallestDifference([10, 0, 20, 25, 2200], [1005, 1006, 1014, 1032, 1031]), [25, 1005])

unittest.main()
