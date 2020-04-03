Disinfecting Box Build Instruction
By Steven Feng, March 26, 2020

## Introduction
Description:
In this project, we are trying to build a disinfecting container using UV-C bulbs to disinfect personal devices, such as your phone, wallet and more. This is particularly useful during the coronavirus pandemic because coronavirus can live on surfaces for up to 72 hours [1]. Thus, as a result, you can easily recontaminate your hands by touching personal devices that may have traces of coronavirus and get infected despite frequently washing your hands. 

According to a research paper by Meecahn and Wilson, 2006 [2], it takes about 12.5 minutes for it to be germicidal, so for extra safety precaution, we will up the timer to 15 minutes (900 seconds). 

### Source:
[1] The Guardian (2020), How long does coronavirus live on different surfaces. Retrieved from  https://www.theguardian.com/us-news/2020/mar/31/how-long-does-coronavirus-live-on-different-surfaces 

[2] P. J. Meechan, et al (2006) Use of Ultraviolet Lights in Biological Safety Cabinets: A Contrarian View.  Retrieved from https://www.ehs.ucsb.edu/files/docs/bs/Meechan_and_Wilson_2006.pdf


## Difficulties:
I have broken up the project into 2 difficulties, basic and advanced, based on your technical skills. Advanced have safety features to only allow the light to turn on when the box is closed
Basic: Only requires 2 bulbs, holders, cardboard, net, and aluminum, no programming / electrical experience required.
Advanced: Arduino, switch sensor, ultrasonic sensor etc. basic programming and electrical experience required. 
Switch sensor is used to detect open or closure of the box
Ultrasonic sensor to detect objects in the box
Arduino as microcontroller




## Usage:
Basic:
Put the items in the box, turn on light bulb manually by opening the switch.
Wait 15 minutes, and closed the light first, then take out your item

Advanced:
Put the items in the box, close the lit firmly until you see the indicator LED turns on
Wait until the indicator LED turns off (after 15 minutes), and take it out
If you need your items during the 15 minutes, turn off the LED from the outside first, then open the box, OR you can open the lid slightly for the indicator LED to turn off, then open the box

## Disclaimer 
Health Precaution:
According to articles above, UVC lights are not normally found in nature, and it is extremely dangerous to human. Avoid direct exposure to the bulb and never look directly into the bulb.
Also, in this project, you will be working with 110 V Alternating current, which could be lethal. Be very carefully when working on the project, and never do work on live wires. Aluminum foil in the project is also conductive, be careful and don’t get shocked.


## License
MIT License

Copyright (c) 2020 Disinfecting Box

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

For full build instruction, see https://docs.google.com/document/d/1My3Jf1Ugp5K4MVcWLSCnGbFniPcyivTnpr6QURKskS0/edit?usp=sharing
