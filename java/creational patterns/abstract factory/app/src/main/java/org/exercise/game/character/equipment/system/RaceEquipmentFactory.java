package org.exercise.game.character.equipment.system;

public interface RaceEquipmentFactory {
    Armor createArmor();

    Mount createMount();

    Weapon createWeapon();
}
