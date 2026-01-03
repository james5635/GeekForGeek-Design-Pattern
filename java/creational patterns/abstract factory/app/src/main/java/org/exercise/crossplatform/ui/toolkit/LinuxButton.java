package org.exercise.crossplatform.ui.toolkit;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class LinuxButton implements Button{
    @Override
    public void render(){
        log.info("linux button is rendering...");
    }

    @Override
    public void resize() {
        log.info("linux button is resizing.");
    }
}