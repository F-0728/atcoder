def carpet(x):
    if x == 0:
        return [["#"]]
    else:
        prev = carpet(x-1)
        res = []
        for i in range(3 ** (x - 1)):
            res.append(prev[i] + prev[i] + prev[i])
        for i in range(3 ** (x - 1)):
            res.append(prev[i] + ["." for _ in range(3 ** (x - 1))] + prev[i])
        for i in range(3 ** (x - 1)):
            res.append(prev[i] + prev[i] + prev[i])
        return res
        


n = int(input())
ans = carpet(n)
for i in range(3 ** n):
    print("".join(ans[i]))
