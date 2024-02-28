import time
import sys

def ft_tqdm(lst: range):
    total = len(lst)
    length = 20
    fill_char = ''
    prefix = 'Progress:'
    end = '\r'

    def format_bar(progress):
        completed = int(length * progress / total)
        remaining = length - completed
        bar = fill_char * completed + '-' * remaining
        return f"{prefix} |{bar}| {progress}/{total}"

    last_progress = 0

    for i, _ in enumerate(lst, start=1):
        progress = min(i, total)
        if progress != last_progress or progress == total:
            bar_str = format_bar(progress)
            print(bar_str.ljust(length + len(prefix) + 16), end=end)
            last_progress = progress
        yield i
        time.sleep(0.005)  # Simulate some work

    print('')  # Ensure the next print goes to a new line

# Example usage:
if __name__ == "__main__":
    for elem in ft_tqdm(range(333)):
        time.sleep(0.005)
