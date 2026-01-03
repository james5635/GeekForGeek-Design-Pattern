package org.exercise.furniture.store;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Client {
    private Chair chair;
    private Sofa sofa;
    private CoffeeTable coffeeTable;
    private FurnitureFactory furnitureFactory;

    enum Style {
        Modern,
        Victorian
    }

    Client(Style s){
        switch(s){
            case Modern:
                furnitureFactory = new ModernFurnitureFactory();
                break;
            case Victorian:
                furnitureFactory = new VictorianFurnitureFactory();
                break;
            default:
                break;
        }
        chair = furnitureFactory.createChair();
        sofa = furnitureFactory.createSofa();
        coffeeTable = furnitureFactory.createCoffeeTable();
    }
}
