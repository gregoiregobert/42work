import time
from datetime import datetime

times = time.time()

formatted_date = datetime.fromtimestamp(times).strftime('%b %d %Y')

formatted_second = f"{times:,.4f} or {times:.2e} in scientific notation"

print(f"Seconds since Jaunary 1, 1970: {formatted_second}")
print(formatted_date)
