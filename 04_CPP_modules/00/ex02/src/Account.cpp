/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:12:25 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/12/05 10:12:25 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// attributs non membres, donc pas à initialiser dans le constructeur (seule manière de les initialiser ci-dessous)
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return ( Account::_nbAccounts );
}

int	Account::getTotalAmount( void )
{
	return ( Account::_totalAmount );
}

int	Account::getNbDeposits( void )
{
	return ( Account::_totalNbDeposits );
}

int	Account::getNbWithdrawals( void )
{
	return ( Account::_totalNbWithdrawals );
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
	return ;
}

Account::Account( int initial_deposit ) : _accountIndex( _nbAccounts ), _amount( initial_deposit ), _nbDeposits( 0 ), _nbWithdrawals( 0 )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created";
	std::cout << std::endl;
	_nbAccounts += 1;
	_totalAmount += _amount;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed";
	std::cout << std::endl;
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	return ;
}

void	Account::makeDeposit( int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if ( withdrawal > _amount )
	{
		std::cout << "withdrawal:refused" << std::endl;
		return ( false );
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return ( true );
	}
}

int	Account::checkAmount( void ) const
{
	return ( _amount );
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return ;
}

void	Account::_displayTimestamp( void ) // keyword "static" ne doit être renseigné que dans le header, pas dans la définition
{
	time_t		rawtime;
	struct tm	*timeinfo;
	char		timestamp[16];

	time( &rawtime );
	timeinfo = localtime( &rawtime );
	strftime( timestamp, 16, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << timestamp << "] ";
	return ;
}