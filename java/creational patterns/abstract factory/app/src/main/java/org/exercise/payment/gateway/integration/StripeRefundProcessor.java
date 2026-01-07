package org.exercise.payment.gateway.integration;

public class StripeRefundProcessor implements RefundProcessor {

    @Override
    public String getDescription() {
        return "stripe " + DESCRIPTION;
    }

}
