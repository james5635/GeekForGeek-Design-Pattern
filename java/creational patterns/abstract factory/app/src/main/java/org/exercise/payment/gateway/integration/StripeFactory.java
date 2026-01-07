package org.exercise.payment.gateway.integration;

public class StripeFactory implements PaymentGatewayFactory {

    @Override
    public InvoiceGenerator createInvoiceGenerator() {
        return new StripeInvoiceGenerator();
    }

    @Override
    public PaymentProcessor createPaymentProcessor() {
        return new StripePaymentProcessor();
    }

    @Override
    public RefundProcessor createRefundProcessor() {
        return new StripeRefundProcessor();
    }

}
