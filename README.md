 

REAL TIME CLOCK WITH ALARM FOR EMBEDDED SYSTEMS
 
      


ABSTRACT
The objective of this project is to design and implement a real-time clock (RTC) system with alarm functionality for an embedded system. The project utilized a microcontroller that is Arduino, an RTC module that is DS3231, and peripheral components to manage accurate timekeeping and time-based event triggering.thesystem should be able to manage the accurate time keeping time based events, schedule time and give a light and sound when the set time reaches to alert the individual that has set it, with user input for adjusting settings and debouncing switches.   
INTRODUCTION
In today's increasingly connected and automated world, embedded systems play a crucial role in a variety of applications, ranging from household appliances to industrial machines, healthcare devices, and smart consumer electronics. One fundamental requirement in many embedded systems is the ability to track and manage time accurately. This is particularly important in systems that rely on scheduled events, time-based alerts, or automation, where precise timekeeping is essential for reliability and functionality.
This project focuses on the design and implementation of a Real-Time Clock (RTC) with Alarm system, a critical component that ensures accurate timekeeping and event scheduling in embedded systems. The goal of this project is to create an embedded system that can maintain real-time clock functionality even during power outages, trigger alarms at specific times, and provide users with a simple interface for setting and managing time and alarm values.
The Real-Time Clock (RTC) module, typically backed by a battery to preserve time across power cycles, is used in this project to provide accurate and persistent timekeeping. The alarm functionality allows the system to trigger a pre-set event (such as activating a buzzer, LED, or other outputs) when the current time matches the set alarm time. Additionally, this project incorporates switch debouncing, GPIOs for user interaction, EEPROM for storing time and alarm settings, and a display (OLED) for time visualization.
This system can be applied in various real-world scenarios such as:
•	Home automation: Triggering lights, fans, or appliances at specific times.
•	Medical devices: Setting reminders for medication or therapy.
•	IoT devices: Providing periodic updates or status notifications.
•	Industrial control systems: Automating processes based on time schedules.
By creating this RTC with alarm system, this project aims to solve the problem of reliable time tracking and scheduled event management in embedded systems. The outcome of this project will demonstrate how embedded systems can use time to automate tasks, send reminders, and manage operations in a timely and efficient manner, all while minimizing human intervention.
COMPONENTS AND MATERIALS
Below is a list of components that we used in order to ensure the success of our project
1. Microcontroller
•	Component: Arduino.

•	Function: The microcontroller serves as the central processing unit (CPU) that controls the overall operation of the system. It interfaces with the RTC module, display, buttons, and buzzer.

•	Specifications:
o	Processor: Atmega328P 
o	I/O Pins: Sufficient for interfacing with the display, buttons, and other components
o	Power supply: 5V 

•	Quantity: 1
________________________________________
2. Real-Time Clock (RTC) Module
•	Component: DS3231 

•	Function: The RTC module provides accurate time and date information, even when the main system is powered off, as it includes its own battery backup. The RTC communicates with the microcontroller via I2C or SPI communication.


•	Specifications:
o	Real-Time Clock (RTC) accuracy: ±2 minutes/month
o	Power supply: 3.3V to 5V
o	Communication interface: I2C
•	Quantity: 1
________________________________________
3. Display
•	Component: OLED Display 

•	Function: Displays the current time, alarm time, and system status. 

•	Specifications:
o	OLED Display : 128x64 pixel resolution 
o	Power supply:  3.3V 
o	Interface: I2C 
•	Quantity: 1
________________________________________
4. Buzzer 
•	Component: Passive Buzzer 

•	Function: Emits sound when the alarm time is reached. The buzzer is activated by a digital output from the microcontroller.


•	Specifications:
o	Voltage: 5V
o	Signal type: Digital (on/off)
•	Quantity: 1
________________________________________
5. Buttons (for setting time and alarm)
•	Component: Pushbuttons 

•	Function: These buttons allow the user to set the current time and the alarm time. They may also be used for snooze or resetting the alarm.


•	Specifications:
o	Momentary push buttons 
o	Voltage: 5V
o	Quantity: 2–3 buttons (one for hour, one for minute, and optional reset/snooze button)
________________________________________
6. Power Supply
•	Component: 5V Power supply

•	Function: Provides power to the microcontroller and other components. USB power is common for prototyping, while a battery pack is useful for portable projects.


•	Specifications:
o	Input: 5V DC 
o	Battery : 5V DC battery pack 
•	Quantity: 1
________________________________________
7. Connecting Wires
•	Component: Jumper Wires (Male-to-Male, Female-to-Male)
•	Function: Used for connecting the microcontroller to other components like the RTC, display, and buzzer.

•	Specifications:
o	20–30 pieces of jumper wires (various lengths)
o	Insulated wires
•	Quantity: 1 pack
________________________________________
8. Breadboard (Optional for Prototyping)
•	Component: Breadboard 

•	Function: Used to prototype and test the circuit without the need for soldering. It provides a convenient way to connect the components and test the system before finalizing the design.


•	Specifications:
o	Size: Full-sized or half-sized breadboard
o	Pin holes: Sufficient for placing components (RTC, microcontroller, display, etc.)
•	Quantity: 1 
________________________________________
9. Resistors (for Buttons)
•	Component: 10kΩ Resistors 
•	Function: Used to prevent floating inputs when using push buttons. A pull-down resistor is often required to ensure a defined logic level when the button is not pressed.
•	Specifications:
o	Value: 10kΩ
o	Quantity: 2–3 

SYSTEM DESIGN AND REQUIREMENTS 
In this section of the report, we will describe the system design and outline the requirements for the Real-Time Clock (RTC) with Alarm project. This will cover both the hardware and software architecture, as well as the specific functional requirements needed to successfully implement the system.
1.	System Design Overview
The Real-Time Clock (RTC) with Alarm system is designed to provide an accurate timekeeping solution with the added functionality of setting and triggering an alarm at a specific time. The system will continuously display the current time and will sound an alarm when the set alarm time is reached.
2.	System Architecture
The system is composed of several key modules that interact with each other. The overall architecture is based on a microcontroller (i.e., Arduino Uno) which communicates with other peripherals, including the RTC module, LCD display, buttons, and buzzer.
Here is a breakdown of the system architecture:
2.1 Microcontroller (Arduino Uno)
•	Function: The microcontroller is the central processing unit of the system. It controls the flow of data, interfaces with the RTC module, reads button inputs, updates the display, and triggers the alarm.

•	Input/Output:
o	Inputs: Button presses (for setting time and alarm).
o	Outputs: Display (LCD or OLED), buzzer (alarm sound).
2.2 Real-Time Clock (RTC) Module (DS3231)
Function: The RTC module is responsible for keeping track of the time. It uses an onboard battery to maintain time even when the system is powered off.
Communication: The microcontroller communicates with the RTC module via the I2C protocol.
Power: Powered by 3.3V or 5V from the microcontroller, with a backup coin cell battery for timekeeping when the system is powered off.
2.3 LCD Display (16x2 LCD or OLED)
•	Function: Displays the current time (hours, minutes, and seconds) and the set alarm time. Additionally, it will display status messages such as "Alarm Triggered" when the alarm goes off.
•	Interface: The display communicates with the microcontroller via I2C (for 16x2 LCD) or SPI/I2C (for OLED).
•	Power: Powered by 5V from the microcontroller.
2.4 Buttons
•	Function: Push buttons allow the user to set the time (hour, minute, second) and the alarm time (alarm hour, alarm minute). Additional buttons can be used to reset the alarm or enable a snooze function.
•	Types: Typically, two buttons are needed for setting hours and minutes for both time and alarm. An additional button can be used for resetting or snoozing the alarm.
•	Connection: The buttons connect to the digital input pins of the microcontroller, and pull-down resistors are used to prevent floating inputs.
2.5 Buzzer
•	Function: The buzzer emits a sound when the set alarm time is reached. It is activated by a digital output from the microcontroller when the current time matches the alarm time.
•	Type: A passive buzzer 
•	Power: Powered by the 5V pin from the microcontroller.
3.	System Requirements
We made sure that the system meets both the functional and the nonfunctional requirements to make sure that it works efficiently and reliably
3.1 Functional Requirements
These requirements describe the specific functions the system must perform.
Accurate Timekeeping:
o	The system must accurately keep track of time (hours, minutes, and seconds) and continuously display it on the screen.
o	The RTC module must update the time every second and maintain timekeeping even during power loss, using the onboard backup battery.


Alarm Setting:
•	The user must be able to set the current time and alarm time using the push buttons.
•	The system should allow the user to set hours and minutes for both the current time and alarm time.
•	The user should be able to view the current time and the alarm time on the display.
Alarm Triggering:
•	When the current time matches the alarm time, the system must trigger the alarm by activating the buzzer.
•	The buzzer should sound until the user acknowledges the alarm by pressing a button to stop it (reset button).
Button Functionality:
•	The system must allow the user to set and reset the alarm time using push buttons.
•	The user should be able to set hours and minutes for both the current time and the alarm time independently.
•	
Display Functionality:
•	The display must show the current time in a format (e.g., HH:MM).
•	When the alarm is triggered, the display should show a message such as “Alarm Triggered.”

Battery Backup:
•	The RTC module must include a backup battery (e.g., CR2032) to keep track of time when the system is powered off.
3.2 Non-Functional Requirements
These requirements define the overall qualities and constraints of the system.
Power Consumption:
•	The system must operate with low power consumption, especially when running on a battery, to ensure prolonged operation.
•	The RTC module should have low standby power consumption and should draw very little current when idle.
User Interface:
•	The user interface should be simple and intuitive, with clearly labeled buttons for setting time and alarm.
•	The display should be easy to read, and the alarm sound should be loud enough to be heard in a typical environment.
System Stability:
•	The system should be stable and reliable. It must correctly display the time and respond to user inputs without delay or malfunction.
•	The system should have minimal latency when switching between functions (e.g., setting time, displaying the alarm).
Portability:
•	The system should be portable, with a compact design suitable for a variety of applications (e.g., portable alarm clock).
•	If powered by a battery pack, it should be easy to carry and operate without a constant power source.
Cost and Availability:
•	The components used in the system should be cost-effective and readily available.
The system design should be simple enough for easy reproduction and prototyping.
4. Functional Block Diagram
A functional block diagram of the RTC with Alarm system is illustrated below to provide a visual understanding of how the different components interact:

 
4.	System Flowchart
The system flowchart will help clarify how the system works logically.
1.	Start: The system begins by initializing the microcontroller and the RTC module.
2.	Set Time: The user sets the current time via buttons.
3.	Set Alarm: The user sets the alarm time.
4.	Run Loop: The system continually checks the current time and compares it to the alarm time.
If the times match, the alarm triggers.
5.	Alarm Triggered: The buzzer sounds, and the user can reset or acknowledge it.
6.	Reset or Snooze: The user presses a button to stop the alarm or activate the snooze.
7.	Display Update: The system updates the time and any other relevant messages on the display.
SOFTWARE DEVELOPMENT (THE CODE)
TESTING AND RESULTS
CHALLENGES AND LIMITATIONS
CONCLUSION
REFERENCES
    
