from time import sleep
import sys
from tqdm import tqdm

def hide_cursor():
    sys.stdout.write("\033[?25l")
    sys.stdout.flush()

def show_cursor():
    sys.stdout.write("\033[?25h")
    sys.stdout.flush()



def ft_tqdm(n):
	lenth = len(n)
	fill = '='
	remains = ' '
	total = 73

	for i, _ in enumerate(n):
		progress = (i / lenth) * total
		rest = total - progress
		percent = i / len(n) * 100
		hide_cursor()
		if (progress > 50):
			progress = 50
		print(f" {int(percent)}%|{int(progress) * fill}{int(rest) * remains}| {i}/{lenth}", end="\r")
		yield i
	print(f"100%|{total * fill}| {len(n)}/{lenth}", end="\r")
	yield 1
	print()
	show_cursor()
	

# if __name__ == '__main__':
# 	for i in ft_tqdm(range(8)):
# 		sleep(0.5)
# 	for i in tqdm(range(8)):
# 		sleep(0.5)



	

