package org.exercise.payment.gateway.integration;

public class PayPalRefundProcessor implements RefundProcessor {

    @Override
    public String getDescription() {
        return "paypal " + DESCRIPTION;
    }

}
