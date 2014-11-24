#include "account.h"


int Account::getId() const
{
    return id;
}

void Account::setId(int value)
{
    id = value;
}
Account::Account()
{
}

Account::Account(int id, string name, string lastname, bool sex, int age, double balance):
    id(id), name(name), lastname(lastname), sex(sex), age(age), balance(balance)
{

}



string Account::getName() const
{
    return name;
}

void Account::setName(const string &value)
{
    name = value;
}

string Account::getLastname() const
{
    return lastname;
}

void Account::setLastname(const string &value)
{
    lastname = value;
}

bool Account::getSex() const
{
    return sex;
}

void Account::setSex(bool value)
{
    sex = value;
}

int Account::getAge() const
{
    return age;
}

void Account::setAge(int value)
{
    age = value;
}

double Account::getBalance() const
{
    return balance;
}

void Account::setBalance(double value)
{
    balance = value;
}



