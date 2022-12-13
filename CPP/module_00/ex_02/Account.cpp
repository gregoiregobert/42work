#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	add_zero(int nb)
{
	if (nb < 10)
		std::cout << 0;
	std::cout << nb;
}

void Date(void)
{
	time_t actuel = time(0);
	tm *ltm = localtime(&actuel);

	std::cout << "[" << ltm->tm_year + 1900;
	add_zero(ltm->tm_mon);
	add_zero(ltm->tm_mday);
	std::cout << "_";
	add_zero(ltm->tm_hour);
	add_zero(ltm->tm_min);
	add_zero(ltm->tm_sec);
	std::cout << "] ";
}

Account::Account(int init_dep) : _amount(init_dep)
{
	static int	nbacc;

	this->_accountIndex = nbacc;
	Date();
	std::cout << "index:" << nbacc
			<< ";amount:" << _amount 
			<< ";created"
			<< std::endl;
	nbacc++;

	Account::_nbAccounts += 1;
	Account::_totalAmount += init_dep;
}

Account::~Account(void)
{
	Date();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << _amount 
			<< ";closed"
			<< std::endl;

	Account::_nbAccounts -= 1;
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
	Date();
	std::cout << "accounts:" << Account::_nbAccounts
		<< ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits
		<< ";withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;

}

void	Account::makeDeposit( int deposit )
{
	Date();
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex
			<< ";p_amout:" << this->_amount
			<< ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount
			<< ";nb_deposit:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Date();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amout:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (0);
	}
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
			<< ";amout:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Date();
	std::cout << "index:" << this->_accountIndex
		<< ";amout:" << this->_amount
		<< ";deposit:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}
