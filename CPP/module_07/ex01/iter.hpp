#ifndef ITER_HPP
# define ITER_HPP

template<class T>
void	iter(T *adr, size_t n, void (*func)(T &elem))
{
	for (size_t i = 0; i < n; i++)
		(*func)(adr[i]);
}

#endif