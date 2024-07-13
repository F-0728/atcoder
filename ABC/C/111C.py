from collections import Counter

N = int(input())

v = list(map(int, input().split()))

even = []
odd = []

for i in range(N):
    if i % 2 == 0:
        even.append(v[i])
    else:
        odd.append(v[i])

cEven = Counter(even)
cOdd = Counter(odd)

if len(cEven) == 1 and len(cOdd) == 1:
    if cEven.most_common()[0][0] == cOdd.most_common()[0][0]:
        print(N // 2)
    else:
        print(0)
    exit()

ans = N

if len(cEven) == 1:
    if cEven.most_common()[0][0] == cOdd.most_common()[0][0]:
        ans -= N / 2
        ans -= cOdd.most_common()[1][1]
    else:
        ans -= cOdd.most_common()[0][1]
        ans -= N / 2

if len(cOdd) == 1:
    if cEven.most_common()[0][0] == cOdd.most_common()[0][0]:
        ans -= N / 2
        ans -= cEven.most_common()[1][1]
    else:
        ans -= cEven.most_common()[0][1]
        ans -= N / 2

if len(cEven) > 1 and len(cOdd) > 1:
    if cEven.most_common()[0][0] != cOdd.most_common()[0][0]:
        ans = N - cEven.most_common()[0][1] - cOdd.most_common()[0][1]
    else:
        tmp1 = N - cEven.most_common()[0][1] - cOdd.most_common()[1][1]
        tmp2 = N - cEven.most_common()[1][1] - cOdd.most_common()[0][1]
        ans = min(tmp1, tmp2)

print(int(ans))
