package org.exercise.payment.gateway.integration;

public interface PaymentGatewayFactory {
    InvoiceGenerator createInvoiceGenerator();

    PaymentProcessor createPaymentProcessor();

    RefundProcessor createRefundProcessor();
}
