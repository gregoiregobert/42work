import os
import sys

list = {
     0 : 'Prediction',
     1 : 'Truth'
}

for i in range(len(sys.argv) - 1):
    with open(f"{os.getcwd()}/{sys.argv[i + 1]}", 'r') as file:
        list[i] = [line.strip() for line in file.readlines()]

rp = sum(1 for t, p in zip(list[0], list[1]) if p == 'Jedi' and t == 'Jedi')
print('rp', rp)

wp = sum(1 for t, p in zip(list[0], list[1]) if p == 'Jedi' and t == 'Sith')
print('wp', wp)

rn = sum(1 for t, p in zip(list[0], list[1]) if p == 'Sith' and t == 'Sith')
print('rn', rn)

wn = sum(1 for t, p in zip(list[0], list[1]) if p == 'Sith' and t == 'Jedi')
print('wn', wn)

accuracy = sum(1 for t, p in zip(list[0], list[1]) if t == p) / len(list[1])

Confusion_matirx = [[rp, wp],
                    [rn, wn]]

