package org.exercise.payment.gateway.integration;

public class StripeInvoiceGenerator implements InvoiceGenerator{

    @Override
    public String getDescription() {
        return "stripe " + DESCRIPTION;
    }
    
}
