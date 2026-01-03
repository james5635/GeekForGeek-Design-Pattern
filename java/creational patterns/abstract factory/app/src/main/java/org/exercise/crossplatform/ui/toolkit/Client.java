package org.exercise.crossplatform.ui.toolkit;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class Client {
    private Button button;
    private Checkbox checkbox;
    private TextField textfield;
    private UIFactory uiFactory;

    enum OS {
        Windows,
        MacOS,
        Linux
    }

    public Client(OS os) {
        switch (os) {
            case Windows:
                uiFactory = new WindowsUIFactory();
                break;
            case MacOS:
                uiFactory = new MacOSUIFactory();
                break;
            case Linux:
                uiFactory = new LinuxUIFactory();
                break;
            default:
                break;
        }
        button = uiFactory.createButton();
        checkbox = uiFactory.createCheckbox();
        textfield = uiFactory.createTextField();
    }

}
