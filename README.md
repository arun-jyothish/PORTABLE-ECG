# PORTABLE-ECG
A Handheld ECG Machine with Mobile phone and Laptop interface. Cardiac condition prediction using ML

[jump to README 2](src/README.md)


[variable link][var link]
LOCK

[var link]: https://GOOGLE.COM 

|part name|LCSC PART NO|LINK|
|-----|-----|----|
|OLED| 	C2890600|https://lcsc.com/product-detail/span-style-background-color-ff0-OLED-span-Displays-Modules_Shenzhen-Allvision-Tech-N096-2864TMBEG0-H30_C2890600.html|
|RESISTOR|
|CAPACITOR|
|TYPEC CONN|
hello world
<br>

[![Contributors][Contributors-shield]][Contributors-url]

<br>

![f3d render 1](https://drive.google.com/uc?id=149vw4zegmcoNbQL5KWwcFqe9mdXNZAx) 

## P-ECG MACHINE

In the prediction feature, patient's ECG signal is compared with various cardio gram.
as the processing result the machine filter out many heart disease and predicts the most probable disease that should affect the person's life'


## BLOCK DIAGRAM
~~~mermaid

graph TD
 
    PWR[POWER SUPPLY]-->CHR[CHARGING CIRCUIT]
    CHR-->BAT[BATTERY 3.7 LI-ION]
    RGL[POWER REGULATOR]-.->|3.3 VOLT|OLED[OLED 128*64]
    CHR--> RGL
    RGL-.->|3.7 VOLT|UC 
    UC{MICROCONTROLLER}-->OLED
   
    UC-->UART[USB TO TTL CONVERTER]
    UART-.->EXT[COMPUTER]
    UART-.->EXT2[MOBILE]
    probe[/PROBE/]-->|DATA|INS
    RGL-.->INS
    RA((RA))-->probe
    RL((RL))-->probe
    LA((LA))-->probe
    INS[INSTRUMENTATION AMPLIFIER] --->|ANALOG DATA| UC
~~~

~~~mermaid
graph TD 

   I((IDEATION)) --> Q[PREPARE FAQ] 
    I --> D[CONSTRAINTS IN NEW IMPLEMENTATION]
    D-->M[ MEASURES TAKEN ]
    EX[IDENTIFYING EXISTING TECHNOLOGY]-->I
    FL[IDENTIFYING LIMITATIONS]-->I
    
~~~
~~~mermaid
graph TD
    H[COMPONENTS SELECTION]-->SCH[PREPARE SCHEMATICS]
    SCH-->PCB[DESIGN PCB LAYOUT]
   DSN[CHASY DESIGN]-->TST[TESTING STAGE]
    TST-.->|FAIL|SCH
    TST==>|SUCCESS|FINAL((PRODUCT))
    PCB-->DSN

~~~
[contributors-shield]: https://img.shields.io/github/contributors/Arun-jyothish/PORTABLE-ECG.svg?style=for-the-badge
[Contributors-url]:https://github.com/Arun-jyothish/PORTABLE-ECG/network/members



~~~mermaid



~~~