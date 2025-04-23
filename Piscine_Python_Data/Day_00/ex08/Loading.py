import sys
import shutil


def hide_cursor():
    sys.stdout.write("\033[?25l")
    sys.stdout.flush()


def show_cursor():
    sys.stdout.write("\033[?25h")
    sys.stdout.flush()


def ft_tqdm(n):
    lenth = len(n)
    fill = '█'
    remains = ' '
    terminal_width, _ = shutil.get_terminal_size()
    total = terminal_width - 39

    for i, _ in enumerate(n):
        progress = (i / lenth) * total
        rest = total - progress + 1
        percent = (i / lenth) * 100
        hide_cursor()
        if i == 0:
            rest = total - progress
        print(f"{percent: 3.0f}%|{int(progress) * fill}\
              {int(rest) * remains}| {i}/{lenth}  ", end='\r')
        yield i

    print(f"100%|{total * fill}| {lenth}/{lenth}  ", end="\r", flush=True)
    print()
    show_cursor()
