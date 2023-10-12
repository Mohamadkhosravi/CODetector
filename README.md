# CODetector
CO Detector

# CO gass
CO gas, also known as carbon monoxide gas, is a colorless, odorless, and tasteless gas composed of one carbon atom and one oxygen atom, with the chemical formula CO. It is often referred to as carbon monoxide because it contains one less oxygen atom than carbon dioxide (CO2).

Carbon monoxide is produced through incomplete combustion of carbon-containing fuels, such as gasoline, natural gas, wood, and coal. When these fuels do not burn completely due to a lack of oxygen, carbon monoxide is one of the byproducts formed.

Carbon monoxide is highly toxic to humans and animals when inhaled because it binds strongly to hemoglobin in red blood cells, preventing them from carrying oxygen to vital tissues and organs. This can lead to carbon monoxide poisoning, which can be life-threatening. 

Symptoms of carbon monoxide poisoning include headache, dizziness, nausea, confusion, shortness of breath, and in severe cases, loss of consciousness or death.

To prevent carbon monoxide poisoning, it's essential to have proper ventilation in areas where combustion processes occur and to install carbon monoxide detectors in homes and buildings where carbon monoxide may be generated, such as those with gas appliances or heating systems

This project is used to measure and warn of CO gas

# Technical description of the project

## Brief description of the parts used in the project
For this project, we used BA45F5240 microcontroller for HOLTEK company

![1](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/7303fa27-6e76-4fca-b92d-a3873ea8319e)

### MCU Peripheral Features
* working voltage 2.2V to 5.5V

* clock  in micro is 32kH to 8MH 

* Flash Program Memory: 4K×16

* RAM Data Memory: 256×8

* True EEPROM Memory: 64×8

* 2 Timer 10bit and internal Watchdog Timer

* Watchdog Timer function

* Up to 13 bidirectional I/O lines

* Up to two external interrupt lines shared with I/O pins

* Universal Serial Interface Module – USIM for SPI, I2C or UART communication

* Up to 4 external channel 12-bit resolution A/D converter with Internal Reference Voltage VBGREF
* Multi-mode operation: FAST, SLOW, IDLE and SLEEP

BA45F5240 [Datasheet](https://www.holtek.com.tw/webapi/11842/BA45F5240_5240-2v140.pdf) 

this MCU designed especially for smoke detector applications but we used for CO gas detection
### CO Sensor 
For this project, we used ME2-CO Electrochemical Carbon Monoxide Sensor with UL certificate for Winsen company

![ME2-CO](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/c61d3add-fc4e-4da1-88d0-90ea02925615)

Technical parameters :
* Measurement Range	0~1000 ppm
* Max detecting concentration	2000 ppm
* Sensitivity	0.023±0.008 µA/ppm
* Resolution ratio	0.5 ppm
* Response time（T90）	≤50 S
* Load resistance	200 Ω（recommended）
* Repeatability	<3%output value
* Stability（／year）	<10%
* Output Linearity	Linear
* Zero drift（-20℃～40℃）	≤10 ppm
* Storage temperature	-20℃～50℃
* Storage Humidity	15%～90%RH
* Pressure range	normal atmosphere ±10%
* Anticipated using life	5 years


ME2-CO  Datasheet (https://www.winsen-sensor.com/d/files/me2-co-0-1000ppm-manual%EF%BC%88ver1_3%EF%BC%89.pdf)
### Display 
 For show information we used seven segment 3 Digit Complex for part number MMC1808 B B10
 
![2](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/610d305e-6a13-4920-a16e-bc3b92a0b769)

MMC1808 B B10 Datasheet [MMD1808B-B10-DataSheet.pdf](https://github.com/Mohamadkhosravi/CODetector/files/12854924/MMD1808B-B10-DataSheet.pdf)

### Temperature Sensor
for measure Temperature ,we used NTC 10k 5% for part number MF52 A 103 J 3950

![MF52_3095-550x550](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/ddeee2ff-c82c-4cc2-ac04-5c27fff9d2ae)

### Alarm 

![3](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/51b13706-63c2-4031-aca4-4b330883896e)

## Examining the general scenario and performance of different departments
The firmware of this project is written in C and assembly language using Holtec's own proprietary [IDE HT-IDE3000](https://www.holtek.com/page/ice)  on the BA45F5240 microcontroller
The main code scenario is in file [Main.c](https://github.com/Mohamadkhosravi/CODetector/blob/main/Main/Main.c) and other modules are written in libraries with related names in header and C files.
main scenario this is : 

### Normal state

In normal mode, the green LED blinks every 8 seconds 
```	
BLINK_LED_GREEN

```	
when the watchdog wakes up and goes back to sleep mode.
```
// Enter low-power mode if no button is pressed	
 _halt();
```	
When pressing the key, the micro wakes up and :

* by pressing the key once, we can see the amount of CO gas in ppm
* By pressing the key twice, we can see the battery charge percentage
* By pressing the key for a long time, the alarm will sound 4 times
After a few seconds after pressing the micro key, it goes to normal mode, i.e. sleep mode

### Low battery state
when battery voltage geting leser than "LOW_BATTERY" yellow LED blinks every 8 seconds


### Alarm state
If the CO sensor detects CO values greater than "MINIMUM_CO_ALLOWED", increment the alarm time counter.
And when we pass one of the limits according to the standard, the alarm sounds and the red LED remains on.
for alarm we use 2 wire buzzer with resonator circuit
```	
if(COValue > MINIMUM_CO_ALLOWED)
		{
		 // Trigger an alarm and increment the alarm counter	
		    LED_RED_ON
			buzzerAlarm(0);
			alarmCounter++;
	    	LED_RED_OFF
			
		}
		else
		{
		 // Decrease the alarm counter and turn off the buzzer	
		  if(alarmCounter>0) alarmCounter--;	
		  BUZZER_OFF
		 
		}
```	
```	
if((LIMIT_1_CO)||(LIMIT_2_CO)||(LIMIT_3_CO)||(LIMIT_4_CO)){
		
		 // Trigger alarms and indicate danger	
			while(1) 
			{
				 _clrwdt();
				 LED_RED_ON
				 buzzerAlarm(0);
			     
			}
		}
```
# #

The limits that exist for comparing the value of CO are defined according to [American Standard – UL2034](https://www.carbonmonoxidekills.com/carbon-monoxide-detectors/ul2034-american/)
According to the definition of this standard, we have:
# #
Main alarm requirements :
 * at 30ppm CO, the alarm must not activate for at least 8 hours
 * at 70ppm CO, the alarm must not activate before 60 minutes but must
 * activate before 240 minutes
 * at 150ppm CO, the alarm must not activate before 10 minutes but must
 * activate before 50 minutes
 * at 400ppm CO, the alarm must not activate before 4 minutes but must activate before 15 minutes
  

# # 
this limits defined in main code for 4 limit defined
# # 
```
 #define MINIMUM_CO_ALLOWED 30
 #define LIMIT_1_CO   ((alarmCounter>=_4_MINUTES)&&(COValue>400))
 #define LIMIT_2_CO   ((alarmCounter>=_10_MINUTES)&&(COValue>125)) 
 #define LIMIT_3_CO   ((alarmCounter>=_50_MINUTES)&&(COValue>75)) 
 #define LIMIT_4_CO   ((alarmCounter>=_8_HOURS)&&(COValue>30))
```
## Description of libraries
To set up and measure the amount of CO gas based on the data sheet of the CO gas sensor [ME2-CO](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/c61d3add-fc4e-4da1-88d0-90ea02925615)  , we must use the following circuit

![4](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/d037fe12-3cf4-412c-acc0-197c10b30f03)

To set up the sensor, we have used the internal micro opamp which is located in the [OPAMP.C](https://github.com/Mohamadkhosravi/CODetector/blob/main/OPAMP/OPAMP.c) and [OPAMP.h](https://github.com/Mohamadkhosravi/CODetector/blob/main/OPAMP/OPAMP.h) files
In the opamp file, we first set the output offset to zero, then set the registers related to the internal opamp keys
![5](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/f6979095-c815-479c-8207-c5fdd2a394b5)
Smoke Detector AFE Block Diagram
for change this keys used from this registers in  [OPAMP.C](https://github.com/Mohamadkhosravi/CODetector/blob/main/OPAMP/OPAMP.c)
```
_sds0=0;
_sds1=0;
_sds2=1;////////
_sds3=0;////////
_sds4=1;
//01: AC coupling mode
_sds5=0;
_sds6=0;

_sda0ofm=0;
_sda1ofm=0;

```
This op-amp topology is called non-inverting topology
The RF resistance is set in this internal project and its value is 100 kiloohms
```
//R1 resistance control
_sdpgac0=0b00000001;  //*100k
```
RI is external and value is 15 kR
The gain of op_amp 1 is obtained from the following formula and its value is 7.6 and it is defined in the [CO.h](https://github.com/Mohamadkhosravi/CODetector/blob/main/CO/CO.h) file.
NON-INVERTING Gain = Rf/Ri + 1 
```
#define gainAmplifier1 7.666666666666667  //gainAmplifier1=1+(100k/15k)
```
we don't use amplifier 2
# # 
for calculate co we need convert current to voltage for this do we use RSHANT 15k ohm,this parameter for calculation CO value defined in [CO.h](https://github.com/Mohamadkhosravi/CODetector/blob/main/CO/CO.h)
```
#define RSHANT 15 //15k
```









