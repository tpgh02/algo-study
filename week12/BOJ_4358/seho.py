import sys
lines = sys.stdin.readlines()
trees = {}

total = 0

for line in lines:
    tree = line.strip()
    if trees.get(tree) is None:
        trees[tree] = 1
    else:
        trees[tree] += 1
    total += 1

name = sorted(trees.keys())

for tree in name :
    print(tree, end=" ")
    print("{:.4f}".format(trees[tree] / total * 100))