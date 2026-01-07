package org.exercise.game.character.equipment.system;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Client {
    private Armor armor;
    private Mount mount;
    private Weapon weapon;
    private RaceEquipmentFactory raceEquipmentFactory;

    enum CharacterRace {
        Elf,
        Orc
    }

    Client(CharacterRace cr) {
        switch (cr) {
            case Elf:
                raceEquipmentFactory = new ElfEquipmentFactory();
                break;
            case Orc:
                raceEquipmentFactory = new OrcEquipmentFactory();
                break;
            default:
                break;
        }
        armor = raceEquipmentFactory.createArmor();
        mount = raceEquipmentFactory.createMount();
        weapon = raceEquipmentFactory.createWeapon();
    }
}
