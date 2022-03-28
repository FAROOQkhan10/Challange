n, m = [int(i) for i in input().split()]
my_col = [0] + [int(i) for i in input().split()]
my_cutoff = [-1] + [-1 for i in range(n)]
my_set = set()
my_list = []
for i in range(m):
    id, p, q, r, s = input().split(",")
    id = int(id[8:])
    p = float(p)
    q = int(q[2:])
    r = int(r[2:])
    s = int(s[2:])
    my_list.append([p, id, 1, q])
    my_list.append([p, id, 2, r])
    my_list.append([p, id, 3, s])
my_list.sort(key=lambda x: (-x[0], x[1], x[2]))

for i in my_list:
    if i[1] not in my_set:
        if my_col[i[3]] > 0:
            my_col[i[3]] -= 1
            my_cutoff[i[3]] = i[0]
            my_set.add(i[1])
my_col = [[my_col[i], i, my_cutoff[i]] for i in range(1, len(my_col))]
my_col.sort(key=lambda x:(-x[0], x[1], x[2]))
s = 0
for i in my_list:
    if i[1] not in my_set:
        while s < len(my_col) and my_col[s][0] <= 0:
            s += 1
        if s < len(my_col):
            my_col[s][0] -= 1
            if my_col[s][2] == -1:
                my_col[s][2] = 100
            my_col[s][2] = min(my_col[s][2], i[0])
            my_set.add(i[1])
my_col.sort(key=lambda x:-x[2])

for i in my_col:
    if i[2] != -1:
        print("C-" + str(i[1]), i[2])
    else:
        print("C-" + str(i[1]), "n/a")