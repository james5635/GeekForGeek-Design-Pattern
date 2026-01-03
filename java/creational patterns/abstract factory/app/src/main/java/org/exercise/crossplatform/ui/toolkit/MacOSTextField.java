package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class MacOSTextField implements TextField {
    @Override
    public void render() {
        log.info("macos textfield is rendering...");
    }

    @Override
    public void changeTextColor() {
        log.info("macos textfield is chaning text color...");
    }

}
