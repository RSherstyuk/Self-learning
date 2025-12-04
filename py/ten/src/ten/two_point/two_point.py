def two_point(arr: list[int], target: int) -> list[int]:
    l = 0
    r = len(arr) - 1
    while l < r:
        cur_sum = arr[l] + arr[r]
        if cur_sum < target:
            l += 1
        elif cur_sum > target:
            r -= 1
        else:
            return [arr[l], arr[r]]

    return [-1,-1]
