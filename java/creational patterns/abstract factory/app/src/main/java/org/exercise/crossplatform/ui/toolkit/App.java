package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class App {
    public static void main(String[] args) {
        log.info("========= Linux =========");
        var linux = new Client(Client.OS.Linux);
        linux.getButton().render();
        linux.getButton().resize();
        linux.getCheckbox().render();
        linux.getCheckbox().check();
        linux.getTextfield().render();
        linux.getTextfield().changeTextColor();

        log.info("========= Windows =========");
        var windows = new Client(Client.OS.Windows);
        windows.getButton().render();
        windows.getCheckbox().render();
        windows.getTextfield().render();

        log.info("========= MacOS =========");
        var macos = new Client(Client.OS.MacOS);
        macos.getButton().render();
        macos.getCheckbox().render();
        macos.getTextfield().render();
    }
}
