#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int init_dep) : _amount(init_dep)
{
	static int	nbacc;
	
	this->_accountIndex = nbacc; 
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
			<< "index:" << this->_accountIndex
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

int Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	
}
