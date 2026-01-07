package org.exercise.game.character.equipment.system;

public class ElfEquipmentFactory implements RaceEquipmentFactory {

    @Override
    public Armor createArmor() {
        return new ElfArmor();
    }

    @Override
    public Mount createMount() {
        return new ElfMount();
    }

    @Override
    public Weapon createWeapon() {
        return new ElfWeapon();
    }

}
