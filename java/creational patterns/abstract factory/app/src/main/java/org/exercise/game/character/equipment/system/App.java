package org.exercise.game.character.equipment.system;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class App {
    public static void main(String[] args) {
        
        log.info("========= Elf =========");
        var elf = new Client(Client.CharacterRace.Elf);
        elf.getArmor().setName("Elf armor");
        elf.getMount().setName("Hawkstriders");
        elf.getWeapon().setName("sword");
        log.info(elf.getArmor().getName());
        log.info(elf.getMount().getName());
        log.info(elf.getWeapon().getName());

        log.info("========= Orc =========");
        var orc = new Client(Client.CharacterRace.Orc);
        orc.getArmor().setName("Orc armor");
        orc.getMount().setName("wolves");
        orc.getWeapon().setName("mace");
        log.info(orc.getArmor().getName());
        log.info(orc.getMount().getName());
        log.info(orc.getWeapon().getName());

    }
}
