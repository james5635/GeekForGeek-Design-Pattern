package org.exercise.payment.gateway.integration;

public class PayPalPaymentProcessor implements PaymentProcessor {

    @Override
    public String getDescription() {
        return "paypal " + DESCRIPTION;
    }
    
}
