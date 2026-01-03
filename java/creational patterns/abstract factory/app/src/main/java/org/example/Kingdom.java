package org.example;

import org.example.Kingdom.FactoryMaker.KindomType;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Kingdom {
    private King king;
    private Castle castle;
    private Army army;

    public static class FactoryMaker {
        public enum KindomType {
            ELF, ORC
        }

        public static KingdomFactory makeFactory(KindomType type) {
            return switch (type) {
                case ELF -> new ElfKindomFactory();
                case ORC -> new OrcKingdomFactory();
            };
        }
    }

}
