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

BA45F5240 Datasheet [https://www.holtek.com.tw/webapi/11842/BA45F5240_5240-2v140.pdf] 

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


ME2-CO Datasheet  [https://www.winsen-sensor.com/d/files/me2-co-0-1000ppm-manual%EF%BC%88ver1_3%EF%BC%89.pdf]
### Display 
 For show information we used seven segment 3 Digit Complex for part number MMC1808 B B10
 
![2](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/610d305e-6a13-4920-a16e-bc3b92a0b769)

MMC1808 B B10 Datasheet [MMD1808B-B10-DataSheet.pdf](https://github.com/Mohamadkhosravi/CODetector/files/12854924/MMD1808B-B10-DataSheet.pdf)

### Temperature Sensor
for measure Temperature ,we used NTC 10k 5% for part number MF52 A 103 J 3950

![MF52_3095-550x550](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/ddeee2ff-c82c-4cc2-ac04-5c27fff9d2ae)

### Alarm 
for alarm we use 2 wire buzzer with resonator circuit



![3](https://github.com/Mohamadkhosravi/CODetector/assets/94738811/51b13706-63c2-4031-aca4-4b330883896e)

##Examining the general scenario and performance of different departments
The firmware of this project is written in C and assembly language using Holtec's own proprietary IDE HT-IDE3000  on the BA45F5240 microcontroller
The main code scenario is in file Main.c  and other modules are written in libraries with related names in header and C files.
main scenario this is : if CO sensor detect co values is more than MINIMUM CO ALLOWED, sensor alarming 
The limits that exist for comparing the value of CO are defined according to American Standard – UL2034






