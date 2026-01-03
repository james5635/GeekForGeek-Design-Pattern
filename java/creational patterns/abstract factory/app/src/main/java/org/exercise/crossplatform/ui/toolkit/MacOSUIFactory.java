package org.exercise.crossplatform.ui.toolkit;

public class MacOSUIFactory implements UIFactory {

    @Override
    public Button createButton() {
        return new MacOSButton();
    }

    @Override
    public Checkbox createCheckbox() {

        return new MacOSCheckbox();
    }

    @Override
    public TextField createTextField() {
        return new MacOSTextField();
    }

}
