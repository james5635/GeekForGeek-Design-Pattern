package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class WindowsTextField implements TextField {
    @Override
    public void render() {
        log.info("windows textfield is rendering");
    }

    @Override
    public void changeTextColor() {
        log.info("windows textfield is changing text color");
    }

}
