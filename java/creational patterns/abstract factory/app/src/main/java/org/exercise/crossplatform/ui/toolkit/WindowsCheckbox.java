package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class WindowsCheckbox  implements Checkbox{@Override
    public void render() {
        log.info("windows checkbox is rendering");
    }

    @Override
    public void check() {

        log.info("windows checbox is checking");
    }

}
