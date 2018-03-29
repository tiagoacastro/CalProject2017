#include "User.h"

User::User(PaymentMethod paymentMethod, string paymentInformation){
    this->paymentMethod = paymentMethod;
    this->paymentInformation = paymentInformation;
}

const PaymentMethod &User::getPaymentMethod() const {
    return paymentMethod;
}

const string &User::getPaymentInformation() const {
    return paymentInformation;
}

