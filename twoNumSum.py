def twoNumberSum(arr, targetSum):
    seen = set()
    for n in arr:
        if targetSum - n in seen:
            return sorted([n, targetSum - n])#return sorted(n, targetSum - n)
        seen.add(n)
    return []
