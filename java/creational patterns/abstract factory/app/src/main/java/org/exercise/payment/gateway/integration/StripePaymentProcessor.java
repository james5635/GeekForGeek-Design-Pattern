package org.exercise.payment.gateway.integration;

public class StripePaymentProcessor implements PaymentProcessor{

    @Override
    public String getDescription() {
        return "stripe " + DESCRIPTION;
    }
    
}
