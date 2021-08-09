# Usage

Please open the example sketch `Low_Side_Switch_Shield_BTF3050TE.ino` in this folder.

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/BTF3050TE_Low-Side_Switch_Shield_top-view_component-description.jpg" width=350><img src="https://github.com/Infineon/Assets/blob/master/Pictures/BTF3050TE_Low-Side_Switch_Shield_top-view_pinout.jpg" width=350>

## Hardware

* Choose up to three appropriate loads, for example a valve
* Connect the Low Side Switch Shield to the Arduino Uno R3
* Connect the GND of shield’s screw terminal with the ground of your power supply.
* Connect the three outputs of the screw terminal with your loads and the loads to your power supply. Your power supply should not exceed 18V for nominal operation.
* To supply the Arduino, connect the board with the proper USB cable
* Open the example sketch with the Arduino IDE
* Hit the upload button in the Arduino IDE
* Turn on the power

## Software functionality

| Switch | Functionality    |
|--------|------------------|
| DIP_1  | Turns the left BTF3050TE on or off (OUT1) |
| DIP_2  | Turns the middle BTF3050TE on or off (OUT2) |
| DIP_3  | Turns the right BTF3050TE on or off (OUT3) |
| S_I    | No functionality |
| S_0    | Toggles LED0. LED0 indicates wether the duty cycle of the PWM will increase or decrease while pressing the corresponding button. If the Led emits light the duty cycle will increase, elsewise it will decrease. |
| S_1    | Increase/decrease duty cycle of left BTF3050TE (OUT1) |
| S_2    | Increase/decrease duty cycle of middle BTF3050TE (OUT2) |
| S_3    | Increase/decrease duty cycle of right BTF3050TE (OUT3) |
| S_4    | Reset fault feedback. The fault feedback is indicated by LED1, LED2 and LED3. For further information about the fault feedback, please refer to the datasheet of BTF3050TE. |
