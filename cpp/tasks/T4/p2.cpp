#include <iostream>
#include <ctime>

class Account
{
private:
    static int _nbAccounts;
    static double _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;

    static void _displayTimestamp(void); // Displays the current timestamp (will be used in displayAccountsInfos)

    int _accountIndex;
    double _amount;
    int _nbDeposits;
    int _nbWithdrawals;

public:
    static int getNbAccounts(void);         /* Returns the number of accounts*/
    static double getTotalAmount(void);     /* Returns the total amount of all accounts*/
    static int getNbDeposits(void);         /* Returns the number of deposits*/
    static int getNbWithdrawals(void);      /* Returns the number of withdrawals*/
    static void displayAccountsInfos(void); /* Displays the number of accounts, the total amount of deposits, the total number of withdrawals, and the total amount of all accounts*/

    Account(double initial_deposit);

    void makeDeposit(double deposit);
    bool makeWithdrawal(double withdrawal);
    void checkAmount(void) const;
    void displayStatus(void) const;

    ~Account(void);
};

/*Static member initialization*/
int Account::_nbAccounts = 0;
double Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
/****************************************************************************************************************************************************/

int Account::getNbAccounts(void) { return _nbAccounts; }
double Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(double initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(double deposit)
{
    _displayTimestamp();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(double withdrawal)
{
    _displayTimestamp();
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

void Account::checkAmount(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "_" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "] ";
}

int main()
{
    Account acc1(100);
    acc1.makeDeposit(50);
    acc1.makeWithdrawal(30);
    acc1.checkAmount();
    acc1.displayStatus();

    Account acc2(200);
    acc2.makeDeposit(100);
    acc2.makeWithdrawal(150);
    acc2.checkAmount();
    acc2.displayStatus();

    Account::displayAccountsInfos();

    return 0;
}
