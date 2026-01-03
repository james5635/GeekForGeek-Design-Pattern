package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class LinuxTextField implements TextField{

    @Override
    public void render() {
        log.info("linux textfield is rendering...");
    }

    @Override
    public void changeTextColor() {
        log.info("linux textfield is changing text color...");
    }

}
