import os
import sys

list = {
     0 : 'Prediction',
     1 : 'Truth'
}


for i in range(len(sys.argv) - 1):
    with open(f"{os.getcwd()}/{sys.argv[i + 1]}", 'r') as file:
        list[i] = [line.strip() for line in file.readlines()]

p_jedi = sum(1 for p in  list[0] if p == 'Jedi')
p_sith = 100 - p_jedi

t_jedi = sum(1 for t in list[1] if t == 'Jedi')
t_sith = 100 - t_jedi

print('p_jedi', p_jedi, 'p_sith', p_sith, 't_jedi', t_jedi, 't_sith', t_sith)

accuracy = sum(1 for t, p in zip(list[0], list[1]) if t == p) / len(list[1])


