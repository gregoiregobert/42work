#include <unistd.h>

int	main()
{
	int h = 456;

	write(1, &h, 4);
}
