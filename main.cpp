/* 
    GardenWatch

    Remote control system to monitor greenhouse objects
    access, temp, humidity etc

    Main Controller Device : Nucleo-F429Z1
    processor : ARM M4
    language : c++
    mbed Microcontroller Library
    Copyright (c) 2018 ARM Limited
    SPDX-License-Identifier: Apache-2.0

*/

#include "mbed.h"
#include "ThisThread.h"
#include "stats_report.h"
#include <iostream>
#include <string>

DigitalOut led1(LED1);

#define SLEEP_TIME                  1000 // (msec)
#define PRINT_AFTER_N_LOOPS         20

/*
    class to control all IO on control ports



 */
class gpio{
public:
    void toggle_port(int port_no){


    }

private:


};

/*
    class to read and set temperature
    inside greenhouse


 */
class atd{
public:
    int get_sample_count(int port_no){
        int r = 0;

        return r;
    }


private:


};


/*
    local display is via a lcd 4x20
    


 */
class lcd{
public:
    int write_line(int line, std::string msg){
        int r = 0;

        return r;
    }


private:


};

/*
    class to control transfers to nodes in Garden
    transfer is by Digi XBee devices in digimesh packets


 */
class xbee_usart{
public:
    std::string build_packet(std::string data){
        std::string s;

        return s;
    }
private:


};



// main() runs in its own thread in the OS
int main()
{
    xbee_usart *xb = new xbee_usart();
    xb->build_packet("hello world");

    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);

    int count = 0;
    while (true) {
        // Blink LED and wait 0.5 seconds
        led1 = !led1;
        ThisThread::sleep_for(SLEEP_TIME);

        if ((0 == count) || (PRINT_AFTER_N_LOOPS == count)) {
            // Following the main thread wait, report on the current system status
            sys_state.report_state();
            count = 0;
        }
        ++count;
    }

    delete(xb);
}

