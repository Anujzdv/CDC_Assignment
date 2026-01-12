class Bank {
    vector<long long> money;

public:
    Bank(vector<long long>& balance) {
        money = balance;
    }

    bool transfer(int from, int to, long long amount) {
        if (from < 1 || to < 1 || from > money.size() || to > money.size())
            return false;

        if (money[from - 1] < amount)
            return false;

        money[from - 1] -= amount;
        money[to - 1] += amount;
        return true;
    }

    bool deposit(int account, long long amount) {
        if (account < 1 || account > money.size())
            return false;

        money[account - 1] += amount;
        return true;
    }

    bool withdraw(int account, long long amount) {
        if (account < 1 || account > money.size())
            return false;

        if (money[account - 1] < amount)
            return false;

        money[account - 1] -= amount;
        return true;
    }
};


/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */