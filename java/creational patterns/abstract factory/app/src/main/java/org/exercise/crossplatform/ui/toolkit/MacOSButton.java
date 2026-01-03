package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class MacOSButton implements Button {@Override
    public void render() {
        log.info("macos button is rendering...");
    }

    @Override
    public void resize() {
        log.info("macos button is resizing...");
    }

}
