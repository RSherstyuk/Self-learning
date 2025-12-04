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

    return [-1, -1]


def reverse_string(s: str) -> None:
    l = 0
    r = len(s) - 1
    temp = list(s)

    while l < r:
        temp[l], temp[r] = temp[r], temp[l]
        l += 1
        r -= 1

    list(temp)


def isPoll(s: str) -> bool:
    ss = s
    reverse_string(s)
    return ss == s


def three_sum(nums: list[int]) -> list[list[int]]:
    nums.sort()

    result: list[list[int]] = []
    n = len(nums)

    for i in range(n):

        if i > 0 and nums[i] == nums[i - 1]:
            continue

        target = -nums[i]
        left = i + 1
        right = n - 1

        while left < right:
            current_sum = nums[left] + nums[right]

            if current_sum == target:
                result.append([nums[i], nums[left], nums[right]])

                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1

                left += 1
                right -= 1

            elif current_sum < target:
                left += 1
            else:
                right -= 1

    return result


def sorted_squares(arr: list[int]) -> list[int]:
    n = len(arr)
    l = 0
    r = n - 1
    result = [0] * n
    pos = n - 1

    while l <= r:
        lSq = arr[l] * arr[l]
        rSq = arr[r] * arr[r]

        if lSq > rSq:
            result[pos] = lSq
            l += 1
        else:
            result[pos] = rSq
            r -= 1

        pos -= 1

    return result
