#include "Account.hpp"
#include <iostream>
#include <ctime>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void    Account::_displayTimestamp()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    char time[20];
    std::strftime(time, sizeof(time), "[%Y%m%d_%H%M%S]", now);
    std::cout<<time<<" ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount
    <<";created"<<std::endl;
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount
    <<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals
    <<std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _nbDeposits++;
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount
    <<";deposit:"<<deposit<<";amount:"<<_amount + deposit
    <<";nb_deposits:"<<_nbDeposits<<std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount < withdrawal)
    {
        std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount
        <<";withdrawal:refused"<<std::endl;
        return 0;
    }
    _nbWithdrawals++;
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount
    <<";withdrawal:"<<withdrawal<<";amount:"<<_amount - withdrawal
    <<";nb_withdrawals:"<<_nbWithdrawals<<std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return 1;
}

int Account::checkAmount() const
{
    return _amount;
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount
    <<";deposits:"<<_totalNbDeposits<<";withdrawals:"
    <<_totalNbWithdrawals<<std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount
    <<";closed"<<std::endl;
}