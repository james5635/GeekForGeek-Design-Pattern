package org.exercise.furniture.store;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class App {
    public static void main(String[] arg) {

        log.info("========= Modern =========");
        var modern = new Client(Client.Style.Modern);
        modern.getChair().setMaterial("wood");
        modern.getCoffeeTable().setWeight(11);
        modern.getSofa().setColor("Blue");
        log.info(modern.getChair().getMaterial());
        log.info(modern.getSofa().getColor());
        log.info(String.valueOf(modern.getCoffeeTable().getWeight()));

        log.info("========= Modern =========");
        var victorian = new Client(Client.Style.Victorian);
        victorian.getChair().setMaterial("plastic");
        victorian.getSofa().setColor("red");
        victorian.getCoffeeTable().setWeight(18);
        log.info(victorian.getChair().getMaterial());
        log.info(victorian.getSofa().getColor());
        log.info(String.valueOf(victorian.getCoffeeTable().getWeight()));
    }
}
