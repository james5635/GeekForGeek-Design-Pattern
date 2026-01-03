package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class WindowsButton implements Button {
    @Override
    public void render() {
        log.info("windows button is rendering...");
    }

    @Override
    public void resize() {
        log.info("windows button is resizing...");
    }

}
