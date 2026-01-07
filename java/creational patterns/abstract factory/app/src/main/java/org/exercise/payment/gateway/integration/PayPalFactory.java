package org.exercise.payment.gateway.integration;

public class PayPalFactory implements PaymentGatewayFactory {

    @Override
    public InvoiceGenerator createInvoiceGenerator() {
        return new PayPalInvoiceGenerator();
    }

    @Override
    public PaymentProcessor createPaymentProcessor() {
        return new PayPalPaymentProcessor();
    }

    @Override
    public RefundProcessor createRefundProcessor() {
        return new PayPalRefundProcessor();
    }

}
