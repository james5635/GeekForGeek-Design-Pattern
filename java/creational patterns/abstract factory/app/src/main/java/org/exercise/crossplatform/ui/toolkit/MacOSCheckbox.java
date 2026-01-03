package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class MacOSCheckbox implements Checkbox {
    @Override
    public void render() {
        log.info("macos checkbox is rendering...");
    }

    @Override
    public void check() {
        log.info("macos checkbox is checking...");
    }

}
