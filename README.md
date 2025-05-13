# Door-Alarm-System-PBL
If your door is left open accidentally, the sensor will activate the alarm system. 

Project Description: 

This project is a smart door alarm system. It uses an ultrasonic sensor to detect whether a door is open, and the buzzer will notify the user. If the door stays open for a certain amount of time, a buzzer will go off. The alarm turns off when you close the door. 


Problem it solves: 

Sometimes people forget to close the door properly. This can be unsafe, especially for the front door, as it could lead to intruders or pets escaping. For example, kids might not shut the door all the way, or you might think the door is closed when your hands are full of groceries or bags. These small moments can lead to big safety problems. Our system helps keep the house secure by warning you with a sound if the door is left open for too long. It acts as a simple reminder to double-check the door, adding an extra layer of security to your home. 


Inputs: 

Ultrasonic sensor: Measures the distance between the door and the sensor to check if the door is open or closed. 

Button Switch Module: Lets the user turn off the buzzer by pressing it. 

Outputs:  

Active Buzzer: Makes a sound to warn you if the door is left open too long. 

 

What each function does: 

isDoorOpen(int distance) 

This checks if the door is open. Measures the distance between the ultrasonic sensor and the door. If the distance is more than 3 cm, it will say that the door is open.  

controlBuzzer(bool shouldBuzz) 

This function turns the buzzer on or off. If shouldBuzz is true, that means the buzzer will turn on. If it’s false, the buzzer turns off.  

 

How the sensors and outputs work: 

Ultrasonic sensor 

This input sensor sends out a sound wave at a high frequency. The transducer part of the sensor receives and sends ultrasonic sound. The sensor finds the distance between itself and its target using time lapses between the ultrasonic pulses.  

Active Buzzer 

This output buzzer works by making it HIGH or LOW whether you want it on or off. This active buzzer has an internal pullup resistor, so the code would also need to include INPUT_PULLUP for it to work.  

Security:  

This project was designed to improve home security by alerting the user if a door is left open for too long. It can help prevent break-ins, accidents, or letting pets out by mistake. The system is meant to be a simple way to keep your home safer using basic sensors and alerts. 

Disclaimer: 
 This device is a basic security aid and should not be relied on as the only protection for your home. It does not replace proper locks, alarms, or human supervision.  
