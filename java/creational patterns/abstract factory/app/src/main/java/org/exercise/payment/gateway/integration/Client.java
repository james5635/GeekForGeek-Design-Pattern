package org.exercise.payment.gateway.integration;

import lombok.Getter;

@Getter
public class Client {
    private InvoiceGenerator invoiceGenerator;
    private PaymentProcessor paymentProcessor;
    private RefundProcessor refundProcessor;
    private PaymentGatewayFactory paymentGatewayFactory;

    enum Provider {
        PayPal,
        Stripe
    }

    Client(Provider p) {
        switch (p) {
            case PayPal:
                paymentGatewayFactory = new PayPalFactory();
                break;
            case Stripe:
                paymentGatewayFactory = new StripeFactory();
                break;
            default:
                break;
        }
        invoiceGenerator = paymentGatewayFactory.createInvoiceGenerator();
        paymentProcessor = paymentGatewayFactory.createPaymentProcessor();
        refundProcessor = paymentGatewayFactory.createRefundProcessor();
    }
}
