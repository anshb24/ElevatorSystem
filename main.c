#include <stdio.h>
#include "header1.h"
int main()
{
    int state = 1; // state for the state machine
    setupGPIO();
    while (1)
    {
        switch (state)
        {

        case 1: // Idle State - Floor 1
            setLED(F1, ON);
            delay(5000);
            if (checkBot(OPEN_PB))
            {
                setLED(OPEN_L, ON);
                delay(15000);
                setLED(OPEN_L, OFF);
                delay(5000);
                if (checkBot(CLOSE_PB))
                {
                    setLED(CLOSE_L, ON);
                    delay(15000);
                    setLED(CLOSE_L, OFF);
                    state = 2;
                }
                else if (!checkBot(CLOSE_PB))
                {
                    delay(10000);
                    setLED(CLOSE_L, ON);
                    delay(15000);
                    setLED(CLOSE_L, OFF);
                    state = 2;
                }
            }
            else if (checkBot(PB2))
            {
                backpoint1:
                setLED(F1, OFF);
                setLED(F2, ON);
                delay(5000);
                if (checkBot(MOVE_PB))
                {
                    setLED(MOVE_L, ON);
                    delay(5000);
                    setLED(MOVE_L, OFF);
                    state = 3;
                }
                else if (!checkBot(MOVE_PB))
                {
                    goto backpoint1;
                }
            }
            else if (checkBot(PB3))
            {
                backpoint2:
                setLED(F1, OFF);
                setLED(F3, ON);
                delay(5000);
                if (checkBot(MOVE_PB))
                {
                    setLED(MOVE_L, ON);
                    delay(10000);
                    setLED(MOVE_L, OFF);
                    state = 5;
                }
                else if (!checkBot(MOVE_PB))
                {
                    goto backpoint2;
                }

                else if (!checkBot(OPEN_PB) & !checkBot(PB2) & !checkBot(PB3))
                {
                    state = 1;
                }
                break;

            case 2:  // Transition State for Floor 1
                delay(5000);
                if (checkBot(PB2))
                {
                    backpoint3:
                    setLED(F1, OFF);
                    setLED(F2, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 3;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint3;
                    }
                }
                else if (checkBot(PB3))
                {
                    backpoint4:
                    setLED(F1, OFF);
                    setLED(F3, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(10000);
                        setLED(MOVE_L, OFF);
                        state = 5;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint4;
                    }
                }
                else if (checkBot(OPEN_PB))
                {
                    setLED(OPEN_L, ON);
                    delay(15000);
                    setLED(OPEN_L, OFF);
                    delay(5000);
                    if (checkBot(CLOSE_PB))
                    {
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 2;
                    }
                    else if (!checkBot(CLOSE_PB))
                    {
                        delay(10000);
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 2;
                    }
                }
                else if (!checkBot(PB2) & !checkBot(PB3) & !checkBot(OPEN_PB))
                {
                    state = 2;
                }
                break;

            case 3: // Idle State - Floor 2
                delay(3000); 
                if (checkBot(OPEN_PB))
                {
                    setLED(OPEN_L, ON);
                    delay(15000);
                    setLED(OPEN_L, OFF);
                    delay(5000);
                    if (checkBot(CLOSE_PB))
                    {
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 4;
                    }
                    else if (!checkBot(CLOSE_PB))
                    {
                        delay(10000);
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 4;
                    }
                }
                else if (checkBot(PB1))
                {
                    backpoint5:
                    setLED(F2, OFF);
                    setLED(F1, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 1;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint5;
                    }
                }
                else if (checkBot(PB3))
                {
                    backpoint6:
                    setLED(F2, OFF);
                    setLED(F3, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 5;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint6;
                    }
                }
                
                else if (!checkBot(OPEN_PB)&!checkBot(PB1)&!checkBot(PB3))
                {
                    state = 3;
                }
                break;

            case 4: // Transition State - Floor 2
                delay(5000);
                if (checkBot(PB1))
                {
                    backpoint7:
                    setLED(F2, OFF);
                    setLED(F1, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 1;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint7;
                    }
                }
                else if (checkBot(PB3))
                {
                    backpoint8:
                    setLED(F2, OFF);
                    setLED(F3, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 5;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint8;
                    }
                }
                else if (checkBot(OPEN_PB))
                {
                    setLED(OPEN_L, ON);
                    delay(15000);
                    setLED(OPEN_L, OFF);
                    delay(5000);
                    if (checkBot(CLOSE_PB))
                    {
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 4;
                    }
                    else if (!checkBot(CLOSE_PB))
                    {
                        delay(10000);
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 4;
                    }
                }
                else if (!checkBot(PB1) & !checkBot(PB3) & !checkBot(OPEN_PB))
                {
                    state = 4;
                }
                break;

            case 5: // Idle State - FLoor 3
                delay(3000); //
                if (checkBot(OPEN_PB))
                {
                    setLED(OPEN_L, ON);
                    delay(15000);
                    setLED(OPEN_L, OFF);
                    delay(5000);
                    if (checkBot(CLOSE_PB))
                    {
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 6;
                    }
                    else if (!checkBot(CLOSE_PB))
                    {
                        delay(10000);
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 6;
                    }
                }
                else if (checkBot(PB1))
                {
                    backpoint9:
                    setLED(F3, OFF);
                    setLED(F1, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(10000);
                        setLED(MOVE_L, OFF);
                        state = 1;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint9;
                    }
                }
                else if (checkBot(PB2))
                {
                    backpoint10:
                    setLED(F3, OFF);
                    setLED(F2, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 3;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint10;
                    }
                }
                else if (!checkBot(OPEN_PB)&!checkBot(PB1)&!checkBot(PB2))
                {
                    state = 5;
                }
                break;

            case 6: // Transition STate - Floor 3
                delay(5000);
                if (checkBot(PB1))
                {
                    backpoint11:
                    setLED(F3, OFF);
                    setLED(F1, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(10000);
                        setLED(MOVE_L, OFF);
                        state = 1;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint11;
                    }
                }
                else if (checkBot(PB2))
                {
                    backpoint12:
                    setLED(F3, OFF);
                    setLED(F2, ON);
                    delay(5000);
                    if (checkBot(MOVE_PB))
                    {
                        setLED(MOVE_L, ON);
                        delay(5000);
                        setLED(MOVE_L, OFF);
                        state = 3;
                    }
                    else if (!checkBot(MOVE_PB))
                    {
                        goto backpoint12;
                    }
                }
                else if (checkBot(OPEN_PB))
                {
                    setLED(OPEN_L, ON);
                    delay(15000);
                    setLED(OPEN_L, OFF);
                    delay(5000);
                    if (checkBot(CLOSE_PB))
                    {
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 6;
                    }
                    else if (!checkBot(CLOSE_PB))
                    {
                        delay(10000);
                        setLED(CLOSE_L, ON);
                        delay(15000);
                        setLED(CLOSE_L, OFF);
                        state = 6;
                    }
                }
                else if (!checkBot(PB1) & !checkBot(PB2) & !checkBot(OPEN_PB))
                {
                    state = 6;
                }
                break;
            }
        }
    }
}
