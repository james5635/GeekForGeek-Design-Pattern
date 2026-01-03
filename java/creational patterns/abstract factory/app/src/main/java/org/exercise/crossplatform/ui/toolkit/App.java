package org.exercise.crossplatform.ui.toolkit;

public class App {
    public static void main(String[] args) {
        var linux = new Client(Client.OS.Linux);
        linux.getButton().render();
        linux.getButton().resize();
        linux.getCheckbox().render();
        linux.getCheckbox().check();
        linux.getTextfield().render();
        linux.getTextfield().changeTextColor();

        var windows = new Client(Client.OS.Windows);
        windows.getButton().render();
        windows.getCheckbox().render();
        windows.getTextfield().render();

        var macos = new Client(Client.OS.MacOS);
        macos.getButton().render();
        macos.getCheckbox().render();
        macos.getTextfield().render();
    }
}
