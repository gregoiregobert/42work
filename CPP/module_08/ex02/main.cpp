#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	MutantStack<int>::it it;
	MutantStack<int>::it ite;

	std::cout << std::endl << "___________________________" << std::endl
			<< "\033[1m|      top stack test     |\033[0m" << std::endl
			<< "|_________________________|" << std::endl;

	mstack.push(5);
	mstack.push(17);

	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::cout << "top stack : " << mstack.top() << std::endl;

	std::cout << std::endl << "___________________________" << std::endl
			<< "\033[1m|     size stack test     |\033[0m" << std::endl
			<< "|_________________________|" << std::endl;

	mstack.pop();

	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::cout << "stack size : " << mstack.size() << std::endl;

	std::cout << std::endl << "___________________________" << std::endl
			<< "\033[1m|        stack view       |\033[0m" << std::endl
			<< "|_________________________|" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	it = mstack.begin();
	ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return 0;
}