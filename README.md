# Low-Side Switch Shield with BTF3050TE for Arduino

<img src="https://github.com/Infineon/Assets/blob/master/Pictures/BTF3050TE_Low-Side_Switch_Shield_top-view_plain.jpg" width=350>

Example code for Infineon's [Low-Side Switch Shield with BTF3050TE](https://www.infineon.com/cms/en/product/evaluation-boards/shield_btf3050te/) for Arduino IDE. Refer also to the [User manual](https://www.infineon.com/dgdl/Infineon-Low_Side_Switch_Shield_with_BTF3050TE_for_Arduino_Users_Manual-UM-v01_00-EN.pdf?fileId=5546d46256fb43b301572836a14c4c36).

## Summary

### Overview

The Low-Side Switch Shield from Infineon consists out of three [BTF3050TE](https://www.infineon.com/cms/en/product/power/smart-low-side-high-side-switches/low-side-switches/hitfet-plus-12v/btf3050te/?redirId=131743) low-side switches of the HITFET™+ family providing three independent power channels that can be controlled via the input pins. The shield is compatible with microcontroller boards using the Arduino form factor for example the corresponding ARM® powered XMC™ microcontroller kits from Infineon and supports fast and easy prototyping of applications with BTF3050TE. The BTF3050TE is a 50 mΩ high integrated single channel low-side switch and able to drive resistive, inductive and capacitive loads with a nominal load current of 3 A. The power transistor itself is a built in N-channel power MOSFET. The whole device is monolithically integrated. This means that the power MOSFET, the driver and protection blocks are integrated in one package. Furthermore the smart low-side switch provides diagnosis and protection features (e.g. overtemperature, overcurrent). BTF3050TE is qualified and optimized for 12 V automotive and industrial applications.

## Key Features and Applications

* An Arduino Uno R3, XMC1100 Boot Kit, or similar board connected to the shield can control the three low-side switches via general IO pins.
* Able to switch all kind of loads like resistive, inductive and capacitive, limited by clamping energy
* Three low-side switches BTF3050TE
  * Input voltage : 3 to 5.5V
  * Supply voltage: 3 to 5.5V
  * Nominal battery voltage: 8 to 18V
  * Extended battery voltage: 3 to 28V
  * Nominal load current: 3 A
  * Minimum current limitation: 30 A
* Over temperature shutdown with auto-restart
* Active clamp over voltage protection of the output (min. 40 V)
* Enhanced short circuit protection
* Capable of PWM up to14 kHz (at 10% duty cycle)
* Driver circuit with logic level inputs
* Diagnosis function
* Protection e.g. against overtemperature, overcurrent and overvoltage
* Communication with the environment via four LEDs, one DIP-switch and up to 6 push buttons
* Easy handling of push buttons: The pin connected to switch SI is always activated; when any button is pushed. This characteristic provides the option to handle easily push button inputs via interrupt

### Applications

* Resistive Loads
  * Heating elements, such as PTC auxiliary heater or lambda sensor
* Inductive Loads
  * Solenoids, valves, flaps, safety locks
  * typically driven with PWM between 4-5 kHz
* Charge capacitors
* Drive loads that behave in a similar way such as bulbs (able to handle the high inrush current)

### Integration of Project

Please download this repository from GitHub by clicking on `Download ZIP` at `Clone or download` dropdown button of this repository or directly [here](https://github.com/Infineon/low-side-switch-shield-btf3050te/archive/refs/heads/master.zip).

Just unzip the file to a location of your choice for further processing the examples.
You can also just clone the repository to a location of your choice and work with the repository directly.

## Usage

Please see the example sketches in the `/examples` directory.
We will guide you through the provided examples using a BTF3050TE Low-Side Switch Shield in combination with an Arduino UNO.
Before you can use the examples, ensure that you have installed the Arduino IDE as described [here](https://www.arduino.cc/en/Guide).

For an example with DAVE and the Infineon XMC1100 Boot Kit, go to the [boards homepage](https://www.infineon.com/cms/en/product/evaluation-boards/shield_btf3050te/) and [download this example](https://www.infineon.com/dgdl/Infineon-Low_Side_Switch_Shield_Dave_Example_Software-SW-v01_00-EN.zip?fileId=5546d46256fb43b30157480aec6f1ab7&da=t).

## Additional Information

* BTF3050TE chip
  * [Product page](https://www.infineon.com/cms/en/product/power/smart-low-side-high-side-switches/low-side-switches/hitfet-plus-12v/btf3050te/?redirId=131743)
  * [Datasheet of the BTF3050TE](https://www.infineon.com/dgdl/Infineon-BTF3050TE-DS-v01_10-EN.pdf?fileId=5546d4625a888733015a892c37d7023f)
* Low-Side Switch Shield with BTF3050TE for Arduino
  * [Product page](https://www.infineon.com/cms/en/product/evaluation-boards/shield_btf3050te/)
  * [Quick start guide](https://www.infineon.com/dgdl/Infineon-HITFET_Low-Side_Shield_with_BTF3050TE_for_Arduino_A6_QSG_Webversion-GS-v01_00-EN.pdf?fileId=5546d46256fb43b30157283fa5d44c3e)
  * [User Manual](https://www.infineon.com/dgdl/Infineon-Low_Side_Switch_Shield_with_BTF3050TE_for_Arduino_Users_Manual-UM-v01_00-EN.pdf?fileId=5546d46256fb43b301572836a14c4c36)
  * [Product Brief](https://www.infineon.com/dgdl/Infineon-LowSide_Switch_Shield_BTF3050TE_for_Arduino-PB-v01_00-EN.pdf?fileId=5546d462580663ef01583e32636d17df)
