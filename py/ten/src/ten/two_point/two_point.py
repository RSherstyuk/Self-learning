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

def reverse_string(s: str) -> None:
    l = 0
    r = len(s) - 1
    temp = list(s)

    while(l < r):
        temp[l], temp[r] = temp[r], temp[l]
        l += 1
        r -= 1

    list(temp)

def isPoll(s: str) -> bool:
    ss = s
    reverse_string(s)
    return ss == s

def three_sum(arr: list[int]) -> list[int]:
    return []
