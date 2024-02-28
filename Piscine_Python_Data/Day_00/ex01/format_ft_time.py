import time
from datetime import datetime

timestamp = time.time()

formatted_date = datetime.fromtimestamp(timestamp).strftime('%b %d %Y')

formatted_second = f"{timestamp:,.4f} or {timestamp:.2e} in scientific notation"

print(f"Seconds since Jaunary 1, 1970: {formatted_second}")
print(formatted_date)