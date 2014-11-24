#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;


class Account
{


private:
    int id;
    string name;
    string lastname;
    bool sex;
    int age;
    double balance;


public:
    Account();

    Account(int id, string name, string lastname, bool sex, int age, double balance);

    string getName() const;
    void setName(const string &value);
    string getLastname() const;
    void setLastname(const string &value);
    bool getSex() const;
    void setSex(bool value);
    int getAge() const;
    void setAge(int value);
    double getBalance() const;
    void setBalance(double value);
    int getId() const;
    void setId(int value);
};

#endif // ACCOUNT_H
