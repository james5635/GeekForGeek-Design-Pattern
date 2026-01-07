package org.exercise.payment.gateway.integration;


public class PayPalInvoiceGenerator implements InvoiceGenerator{

    @Override
    public String getDescription() {
        return "paypal " + DESCRIPTION;
    }
   
}
