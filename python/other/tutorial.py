import itertools

itr1 = itertools.count(5)
for i in itr1:
    print(i)
    if i == 1000:
        break

itr2 = itertools.cycle("ABC")
for i, j in enumerate(itr2):
    print(i, j)
    if i == 1000:
        break

itr3 = itertools.chain("ABC", range(1, 2))
for i in itr3:
    print(i)

itr4 = itertools.compress("ABCDE", [1, 0, 1, 0, 1])
for i in itr4:
    print(i)

p = lambda x: x < 5
l = [1, 3, 4, 5, 1, 4, 9, 1]
itr5 = itertools.dropwhile(p, l)
for i in itr5:
    print(i)

itr6 = itertools.takewhile(p, l)
for i in itr6:
    print(i)

for k, g in itertools.groupby(sorted("AAAABBBBVVVVDDDDEEEEAAACC")):
    print(k, [i for i in g])

tpls = [(2, 3), (3, 4)]
itr7 = itertools.starmap(lambda x, y: x * y, tpls)
[print(i) for i in itr7]

ls = range(0, 3)
tee1, tee2, = itertools.tee(ls)
[print(i) for i in tee1]
[print(i) for i in tee1]
[print(i) for i in tee2]
