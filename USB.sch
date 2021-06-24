EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 4650 2350
Wire Wire Line
	4650 2250 4650 2350
Wire Wire Line
	4450 2250 4650 2250
Wire Wire Line
	4650 2350 4650 2400
Wire Wire Line
	4450 2350 4650 2350
$Comp
L power:GND #PWR?
U 1 1 60D75987
P 4650 2400
AR Path="/60D75987" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D75987" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 4650 2150 50  0001 C CNN
F 1 "GND" H 4655 2227 50  0000 C CNN
F 2 "" H 4650 2400 50  0001 C CNN
F 3 "" H 4650 2400 50  0001 C CNN
	1    4650 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 2350 4000 2350
Wire Wire Line
	4000 2250 4150 2250
$Comp
L Device:R_US R?
U 1 1 60D7598F
P 4300 2350
AR Path="/60D7598F" Ref="R?"  Part="1" 
AR Path="/60D5DC34/60D7598F" Ref="R8"  Part="1" 
F 0 "R8" V 4400 2200 50  0000 C CNN
F 1 "5.1k" V 4400 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4340 2340 50  0001 C CNN
F 3 "~" H 4300 2350 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/bourns-inc/CR0603-FX-5101ELF/3784064" H 4300 2350 50  0001 C CNN "DigiKey"
	1    4300 2350
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 60D75995
P 4300 2250
AR Path="/60D75995" Ref="R?"  Part="1" 
AR Path="/60D5DC34/60D75995" Ref="R7"  Part="1" 
F 0 "R7" V 4200 2100 50  0000 C CNN
F 1 "5.1k" V 4200 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4340 2240 50  0001 C CNN
F 3 "~" H 4300 2250 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/bourns-inc/CR0603-FX-5101ELF/3784064" H 4300 2250 50  0001 C CNN "DigiKey"
	1    4300 2250
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 60D7DE98
P 9750 2400
AR Path="/60D7DE98" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D7DE98" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 9750 2250 50  0001 C CNN
F 1 "+3.3V" H 9765 2573 50  0000 C CNN
F 2 "" H 9750 2400 50  0001 C CNN
F 3 "" H 9750 2400 50  0001 C CNN
	1    9750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 1950 8400 2050
Connection ~ 8400 1950
Wire Wire Line
	8300 1950 8400 1950
Wire Wire Line
	8300 2050 8300 1950
Wire Wire Line
	8400 1900 8400 1950
$Comp
L power:+3.3V #PWR?
U 1 1 60D7DEA9
P 8400 1900
AR Path="/60D7DEA9" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D7DEA9" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 8400 1750 50  0001 C CNN
F 1 "+3.3V" H 8415 2073 50  0000 C CNN
F 2 "" H 8400 1900 50  0001 C CNN
F 3 "" H 8400 1900 50  0001 C CNN
	1    8400 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2950 8900 2950
Wire Wire Line
	8900 3050 8800 3050
Text GLabel 8900 3050 2    50   Input ~ 0
CH340-RTS
Text GLabel 8900 2950 2    50   Input ~ 0
CH340-DTR
NoConn ~ 8800 2650
NoConn ~ 8800 2750
NoConn ~ 8800 2550
NoConn ~ 8800 2850
Wire Wire Line
	8400 3350 8400 3250
$Comp
L power:GND #PWR?
U 1 1 60D7DEB8
P 8400 3350
AR Path="/60D7DEB8" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D7DEB8" Ref="#PWR0109"  Part="1" 
F 0 "#PWR0109" H 8400 3100 50  0001 C CNN
F 1 "GND" H 8405 3177 50  0000 C CNN
F 2 "" H 8400 3350 50  0001 C CNN
F 3 "" H 8400 3350 50  0001 C CNN
	1    8400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2350 8800 2350
Text GLabel 8900 2350 2    50   Input ~ 0
CH340-RX
Wire Wire Line
	8900 2250 8800 2250
Text GLabel 8900 2250 2    50   Input ~ 0
CH340-TX
NoConn ~ 8000 2350
$Comp
L Interface_USB:CH340C U?
U 1 1 60D7DEC6
P 8400 2650
AR Path="/60D7DEC6" Ref="U?"  Part="1" 
AR Path="/60D5DC34/60D7DEC6" Ref="U2"  Part="1" 
F 0 "U2" H 8750 2150 50  0000 C CNN
F 1 "CH340C" H 8800 2050 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 8450 2100 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Jiangsu-Qin-Heng-CH340C_C84681.pdf" H 8050 3450 50  0001 C CNN
	1    8400 2650
	1    0    0    -1  
$EndComp
Text Notes 7800 1550 0    118  ~ 0
USB to Serial
Text GLabel 7750 2550 0    50   Input ~ 0
D+
Text GLabel 7750 2650 0    50   Input ~ 0
D-
$Comp
L power:GND #PWR0143
U 1 1 60D70D19
P 3400 4800
F 0 "#PWR0143" H 3400 4550 50  0001 C CNN
F 1 "GND" H 3405 4627 50  0000 C CNN
F 2 "" H 3400 4800 50  0001 C CNN
F 3 "" H 3400 4800 50  0001 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4650 3400 4800
NoConn ~ 4000 4350
NoConn ~ 4000 4250
NoConn ~ 4000 4050
NoConn ~ 4000 3950
NoConn ~ 4000 3750
NoConn ~ 4000 3650
NoConn ~ 4000 3450
NoConn ~ 4000 3350
NoConn ~ 3100 4650
Text GLabel 4000 2850 2    50   Input ~ 0
D+
Text GLabel 4000 2650 2    50   Input ~ 0
D-
Text GLabel 4000 2550 2    50   Input ~ 0
D-
Text GLabel 4000 2750 2    50   Input ~ 0
D+
NoConn ~ 4000 3050
NoConn ~ 4000 3150
Wire Wire Line
	7750 2550 8000 2550
Wire Wire Line
	8000 2650 7750 2650
Wire Wire Line
	9750 2400 9750 2450
Wire Wire Line
	9750 2800 9750 2750
$Comp
L Device:C C?
U 1 1 60D7DE9E
P 9750 2600
AR Path="/60D7DE9E" Ref="C?"  Part="1" 
AR Path="/60D5DC34/60D7DE9E" Ref="C1"  Part="1" 
F 0 "C1" V 9498 2600 50  0000 C CNN
F 1 "0.1uF" V 9589 2600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9788 2450 50  0001 C CNN
F 3 "" H 9750 2600 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 9750 2600 50  0001 C CNN "DigiKey"
	1    9750 2600
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D7DE92
P 9750 2800
AR Path="/60D7DE92" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D7DE92" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 9750 2550 50  0001 C CNN
F 1 "GND" H 9755 2627 50  0000 C CNN
F 2 "" H 9750 2800 50  0001 C CNN
F 3 "" H 9750 2800 50  0001 C CNN
	1    9750 2800
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0144
U 1 1 60D3C419
P 4050 1950
F 0 "#PWR0144" H 4050 1800 50  0001 C CNN
F 1 "+VUSB_IN" H 4065 2123 50  0000 C CNN
F 2 "" H 4050 1950 50  0001 C CNN
F 3 "" H 4050 1950 50  0001 C CNN
	1    4050 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2050 4000 2050
$Comp
L Connector:USB_C_Receptacle J?
U 1 1 60D7597C
P 3400 3050
AR Path="/60D7597C" Ref="J?"  Part="1" 
AR Path="/60D5DC34/60D7597C" Ref="J2"  Part="1" 
F 0 "J2" H 3507 4317 50  0000 C CNN
F 1 "USB_C_Receptacle" H 3507 4226 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_GCT_USB4085" H 3550 3050 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/GCT%20PDFs/Ionex_USB_Conn_Br.pdf" H 3550 3050 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/gct/USB4085-GF-A/9859662" H 3400 3050 50  0001 C CNN "Digikey"
F 5 "USB4085-GF-A" H 3400 3050 50  0001 C CNN "MPN"
F 6 "https://www.digikey.com/en/products/detail/gct/USB4085-GF-A/9859662" H 3400 3050 50  0001 C CNN "DigiKey"
	1    3400 3050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 60D48E0E
P 1200 6600
F 0 "H1" H 1300 6646 50  0000 L CNN
F 1 "MountingHole" H 1300 6555 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 1200 6600 50  0001 C CNN
F 3 "~" H 1200 6600 50  0001 C CNN
	1    1200 6600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 60D4A0A4
P 1200 6800
F 0 "H2" H 1300 6846 50  0000 L CNN
F 1 "MountingHole" H 1300 6755 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 1200 6800 50  0001 C CNN
F 3 "~" H 1200 6800 50  0001 C CNN
	1    1200 6800
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 60D4A3C7
P 1200 7000
F 0 "H3" H 1300 7046 50  0000 L CNN
F 1 "MountingHole" H 1300 6955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 1200 7000 50  0001 C CNN
F 3 "~" H 1200 7000 50  0001 C CNN
	1    1200 7000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 60D4A7EB
P 1200 7200
F 0 "H4" H 1300 7246 50  0000 L CNN
F 1 "MountingHole" H 1300 7155 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_DIN965_Pad_TopBottom" H 1200 7200 50  0001 C CNN
F 3 "~" H 1200 7200 50  0001 C CNN
	1    1200 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1950 4050 2000
$Comp
L Connector:TestPoint TP6
U 1 1 60EB0C6B
P 4050 2000
F 0 "TP6" V 4004 2188 50  0000 L CNN
F 1 "+VUSB_IN_TP" V 4095 2188 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 4250 2000 50  0001 C CNN
F 3 "~" H 4250 2000 50  0001 C CNN
	1    4050 2000
	0    1    1    0   
$EndComp
Connection ~ 4050 2000
Wire Wire Line
	4050 2000 4050 2050
$EndSCHEMATC
