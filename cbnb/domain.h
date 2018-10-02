#ifndef DOMAIN_H_INCLUDED
#define DOMAIN_H_INCLUDED

#include <stdexcept>

using namespace std;

class Agency{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class Bank{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class AccommodationCapacity{

private:
    string amount;

    void validate(int) throw (invalid_argument);

public:

    void SetAmount(int) throw (invalid_argument);

    int GetAmount() const {
        return amount;
    }
};


class DailyFee{

private:
    string value;

    void validate(int) throw (invalid_argument);

public:

    void SetValue(int) throw (invalid_argument);

    int GetValue() const {
        return value;
    }
};

class Date{

private:
    string value;

    void validate(int) throw (invalid_argument);

public:

    void SetValue(int) throw (invalid_argument);

    int GetValue() const {
        return value;
    }
};

class ExpirationDate{

private:
    string value;

    void validate(int) throw (invalid_argument);

public:

    void SetValue(int) throw (invalid_argument);

    int GetValue() const {
        return value;
    }
};

class State{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class Identifier{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class Name{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class CreditCardNumber{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class CheckingAccount{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class Password{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

class AccommodationType{

private:
    string code;

    void validate(int) throw (invalid_argument);

public:

    void SetCode(int) throw (invalid_argument);

    int GetCode() const {
        return code;
    }
};

#endif // DOMAIN_H_INCLUDED
