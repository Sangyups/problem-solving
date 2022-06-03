def solution(p, n, arr):
    size = n
    is_reversed = 0
    remove_cnt = [0, 0]
    for func in p:
        if func == "D":
            if size <= 0:
                return "error"
            remove_cnt[is_reversed] += 1
            size -= 1
        elif func == "R":
            is_reversed = is_reversed ^ 1
    if remove_cnt[1] == 0:
        remove_cnt[1] = -n

    arr = arr[remove_cnt[0]: -remove_cnt[1]]
    if is_reversed:
        arr.reverse()

    answer = "[" + ",".join(arr) + "]"

    return answer


def main():
    T = int(input())
    while T:
        p = input()
        n = int(input())
        arr = input()[1:-1]
        if arr:
            arr = arr.split(",")
        else:
            arr = []
        print(solution(p, n, arr))
        T -= 1
    return


main()
