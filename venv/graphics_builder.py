import matplotlib.pyplot as plt

with open("/Users/albina/Desktop/Study/ИНФА/sem_3/lab_sorts/venv/bubble_sort_random_data.txt") as bubbleF:
    rand_xb, rand_yb = [], []
    for line in bubbleF.readlines():
        string = list(map(float, line.split()))
        rand_xb.append(string[0])
        rand_yb.append(string[1])

with open("/Users/albina/Desktop/Study/ИНФА/sem_3/lab_sorts/venv/shell_sort_random_data.txt") as bubbleF:
    rand_xs, rand_ys = [], []
    for line in bubbleF.readlines():
        string = list(map(float, line.split()))
        rand_xs.append(string[0])
        rand_ys.append(string[1])

with open("/Users/albina/Desktop/Study/ИНФА/sem_3/lab_sorts/venv/shell_sort_sorted_data.txt") as bubbleF:
    sort_xs, sort_ys = [], []
    for line in bubbleF.readlines():
        string = list(map(float, line.split()))
        sort_xs.append(string[0])
        sort_ys.append(string[1])


with open("/Users/albina/Desktop/Study/ИНФА/sem_3/lab_sorts/venv/bubble_sort_sorted_data.txt") as bubbleF:
    sort_xb, sort_yb = [], []
    for line in bubbleF.readlines():
        string = list(map(float, line.split()))
        sort_xb.append(string[0])
        sort_yb.append(string[1])

fig, (ax1, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(8, 4))
if any(rand_xb):
    ax1.plot(rand_xb, rand_yb, label="bubble sort")
    ax2.plot(sort_xb, sort_yb, label="bubble sort")
if any(rand_xs):
    ax1.plot(rand_xs, rand_ys, label="shell sort")
    ax2.plot(sort_xs, sort_ys, label="shell sort")

ax1.set_title("Random sequence")
ax2.set_title("Sorted sequence")

ax1.set_xlabel("elements")
ax1.set_ylabel("time, s")
ax2.set_ylabel("time, s")
ax2.set_xlabel("elements")


ax1.legend()
ax2.legend()
plt.show()
