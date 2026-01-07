package org.exercise.game.character.equipment.system;

public class OrcEquipmentFactory implements RaceEquipmentFactory {

    @Override
    public Armor createArmor() {
        return new OrcArmor();
    }

    @Override
    public Mount createMount() {
        return new OrcMount();
    }

    @Override
    public Weapon createWeapon() {
        return new OrcWeapon();
    }

}
