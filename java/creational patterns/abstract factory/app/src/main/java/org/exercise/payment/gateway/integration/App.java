package org.exercise.payment.gateway.integration;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class App {
    public static void main(String[] args) {
        log.info("========= PayPal =========");
        var paypal = new Client(Client.Provider.PayPal);
        log.info(paypal.getInvoiceGenerator().getDescription());
        log.info(paypal.getPaymentProcessor().getDescription());
        log.info(paypal.getRefundProcessor().getDescription());

        log.info("========= Stripe =========");
        var stripe = new Client(Client.Provider.Stripe);
        log.info(stripe.getInvoiceGenerator().getDescription());
        log.info(stripe.getPaymentProcessor().getDescription());
        log.info(stripe.getRefundProcessor().getDescription());

    }
}
