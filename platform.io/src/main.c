/*
 * Rad Pro
 * STM32 Main module
 *
 * (C) 2022-2024 Gissio
 *
 * License: MIT
 */

#include "adc.h"
#include "buzzer.h"
#include "comm.h"
#include "datalog.h"
#include "debug.h"
#include "display.h"
#include "events.h"
#include "flash.h"
#include "game.h"
#include "keyboard.h"
#include "measurements.h"
#include "menu.h"
#include "power.h"
#include "pulseled.h"
#include "rng.h"
#include "rtc.h"
#include "settings.h"
#include "system.h"
#include "tube.h"
#include "vibrator.h"
#include "view.h"

int main(void)
{
    // Initialize system

    initSystem();
    initEvents();
    initFlash();
    initSettings();
    initPower();
// +++ TEST
    setPower(true);
    initBuzzer();
    initPulseLED();
// +++ TEST
    debugBeep();
    initComm();
    debugBeep();
    initRTC();
    debugBeep();
    initADC();
    debugBeep();
    initTube();
    debugBeep();
    initKeyboard();
    debugBeep();
    initBuzzer();
    debugBeep();
    initDisplay();
    debugBeep();
#if defined(PULSE_LED)
    initPulseLED();
#endif
    debugBeep();
#if defined(VIBRATOR)
    initVibrator();
#endif
    debugBeep();

#if defined(TEST_MODE)

    setPower(true);
    runTestMode();

#else

    initMeasurements();
    initGame();
    initDatalog();

    // Power loop

    while (true)
    {
        // Wait for power key event

#if defined(SDLSIM)

        static bool firstStart = true;
        while ((getKeyboardEvent() != EVENT_KEY_POWER) && !firstStart)
        {
            sleep(1);

            dispatchDisplayEvents();
        }
        firstStart = false;

#else

        while (getKeyboardEvent() != EVENT_KEY_POWER)
        {
            sleep(1);

            dispatchDisplayEvents();
        }

#endif

        // Power on

        setPower(true);

        if (!verifyFlash())
        {
            drawNotification("WARNING",
                             "Firmware checksum failure.",
                             true);
            refreshDisplay();
            triggerDisplay();
#if defined(DISPLAY_MONOCHROME)
            setDisplay(true);
#endif

            playSystemAlert();

            sleep(1000);
        }

        drawNotification(FIRMWARE_NAME,
                         FIRMWARE_VERSION,
                         true);
        refreshDisplay();
        triggerDisplay();
#if defined(DISPLAY_MONOCHROME)
        setDisplay(true);
#endif

        sleep(1000);

        setTubeHV(true);
        setEventHandling(true);
        setCommEnabled(true);

        writeDatalog();

        // UI loop

        setMeasurementView(0);

        while (!isPowerOffRequested())
        {
            sleep(1);

            updateGame();
            dispatchEvents();
        }

        setPowerOffRequest(false);

        // Power off

        writeDatalog();
        writeSettings();

        setCommEnabled(false);
        setEventHandling(false);
        setTubeHV(false);

#if defined(DISPLAY_MONOCHROME)
        setDisplay(false);
#endif

        setPower(false);
    }

#endif
}
