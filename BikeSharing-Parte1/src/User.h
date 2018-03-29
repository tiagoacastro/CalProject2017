#ifndef USER_H_
#define USER_H_

#include <string>
using namespace std;

enum PaymentMethod { CreditCard, PayPal };

class User {

private:
    PaymentMethod paymentMethod;
    string paymentInformation;

public:
    /**
	 * User constructor
     * @param paymentMethod			    payment method
     * @param paymentInformation		payment information(creditcard number or paypal email)
	 */
    User(PaymentMethod paymentMethod, string paymentInformation);
    /**
    * Getter which returns the payment method
    * @return payment method
    */
    const PaymentMethod &getPaymentMethod() const;
    /**
    * Getter which returns the payment information (creditcard number or paypal email)
    * @return payment information
    */
    const string &getPaymentInformation() const;
};


#endif /*USER_H_*/
