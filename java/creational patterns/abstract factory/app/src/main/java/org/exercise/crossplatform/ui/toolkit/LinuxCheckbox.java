package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class LinuxCheckbox implements Checkbox {
    @Override
    public void render() {
        log.info("linux checkbox is rendering...");
    }

    @Override
    public void check() {
        log.info("linux checkbox is checking...");
    }

}
