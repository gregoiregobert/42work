#include "Account.hpp"
#include <iostream>

Account::Account(int init_dep) : _amount(init_dep)
{
	static int	nbacc;
	
	_accountIndex = nbacc; 
	std::cout << "[20220212_173025] "
			<< "index:" << nbacc
			<< ";amount:" << _amount 
			<< ";created"
			<< std::endl;
	nbacc++;
}

Account::~Account(void)
{
	std::cout << "[20220212_173025] "
			<< "index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";closed"
			<< getNbAccounts()
			<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

// static void	displayAccountsInfos( void )
// {

// }
