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
			<< std::endl;
}

static int	Account::getNbAccounts( void )
{
	return (this->_nbAccounts);
}

static int	getTotalAmount( void )
{

}

static void	displayAccountsInfos( void )
{

}
