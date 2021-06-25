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
Text GLabel 9450 2750 2    50   Input ~ 0
CH340-TX
Text GLabel 9450 2850 2    50   Input ~ 0
CH340-RX
Text GLabel 9450 3250 2    50   Input ~ 0
CH340-DTR
Text GLabel 9450 3050 2    50   Input ~ 0
CH340-RTS
$Comp
L CP2102:CP2102 U2
U 1 1 60F884F8
P 8650 2950
F 0 "U2" H 8650 3915 50  0000 C CNN
F 1 "CP2102" H 8650 3824 50  0000 C CNN
F 2 "CP2102:QFN50P500X500X100-29N" H 8650 2950 50  0001 L BNN
F 3 "" H 8650 2950 50  0001 L BNN
F 4 "CP2102" H 8650 2950 50  0001 L BNN "MP"
F 5 "None" H 8650 2950 50  0001 L BNN "PRICE"
F 6 "Silicon Labs" H 8650 2950 50  0001 L BNN "MF"
F 7 "WFQFN-20 Silicon Labs" H 8650 2950 50  0001 L BNN "PACKAGE"
F 8 "Unavailable" H 8650 2950 50  0001 L BNN "AVAILABILITY"
F 9 "USB to UART Bridge" H 8650 2950 50  0001 L BNN "DESCRIPTION"
F 10 "https://www.digikey.com/en/products/detail/silicon-labs/CP2102-GM/696598" H 8650 2950 50  0001 C CNN "DigiKey"
	1    8650 2950
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0106
U 1 1 60F92083
P 7500 2250
F 0 "#PWR0106" H 7500 2100 50  0001 C CNN
F 1 "+VUSB_IN" H 7515 2423 50  0000 C CNN
F 2 "" H 7500 2250 50  0001 C CNN
F 3 "" H 7500 2250 50  0001 C CNN
	1    7500 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 2250 7500 2450
Wire Wire Line
	7500 2450 7600 2450
Wire Wire Line
	7500 2450 7500 2850
Wire Wire Line
	7500 2850 7950 2850
Connection ~ 7500 2450
NoConn ~ 7950 2650
$Comp
L Device:C_Small C1
U 1 1 60F96294
P 7600 2550
F 0 "C1" H 7350 2650 50  0000 L CNN
F 1 "1uF" H 7250 2550 50  0000 L CNN
F 2 "" H 7600 2550 50  0001 C CNN
F 3 "~" H 7600 2550 50  0001 C CNN
	1    7600 2550
	1    0    0    -1  
$EndComp
Connection ~ 7600 2450
Wire Wire Line
	7600 2450 7800 2450
$Comp
L Device:C_Small C10
U 1 1 60F96A58
P 7800 2550
F 0 "C10" H 7900 2600 50  0000 L CNN
F 1 "0.1uF" H 7896 2532 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7800 2550 50  0001 C CNN
F 3 "~" H 7800 2550 50  0001 C CNN
	1    7800 2550
	1    0    0    -1  
$EndComp
Connection ~ 7800 2450
Wire Wire Line
	7800 2450 7950 2450
$Comp
L power:GND #PWR0107
U 1 1 60F98FE3
P 7700 2650
F 0 "#PWR0107" H 7700 2400 50  0001 C CNN
F 1 "GND" H 7706 2496 50  0000 C CNN
F 2 "" H 7700 2650 50  0001 C CNN
F 3 "" H 7700 2650 50  0001 C CNN
	1    7700 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 2650 7600 2650
Wire Wire Line
	7700 2650 7800 2650
Connection ~ 7700 2650
$Comp
L Device:C_Small C18
U 1 1 60F9B4B0
P 9600 2350
F 0 "C18" H 9700 2400 50  0000 L CNN
F 1 "0.1uF" H 9696 2332 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9600 2350 50  0001 C CNN
F 3 "~" H 9600 2350 50  0001 C CNN
	1    9600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 2250 9600 2250
$Comp
L power:GND #PWR0108
U 1 1 60F9D614
P 9600 2550
F 0 "#PWR0108" H 9600 2300 50  0001 C CNN
F 1 "GND" H 9750 2500 50  0000 C CNN
F 2 "" H 9600 2550 50  0001 C CNN
F 3 "" H 9600 2550 50  0001 C CNN
	1    9600 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 2550 9600 2450
NoConn ~ 9350 2450
NoConn ~ 9350 2550
Text GLabel 7850 2950 0    50   Input ~ 0
D+
Wire Wire Line
	7850 2950 7950 2950
Text GLabel 7850 3050 0    50   Input ~ 0
D-
Wire Wire Line
	7850 3050 7950 3050
NoConn ~ 7950 3450
Wire Wire Line
	9450 2750 9350 2750
Wire Wire Line
	9350 2850 9450 2850
Wire Wire Line
	9450 3250 9350 3250
Wire Wire Line
	9450 3050 9350 3050
NoConn ~ 9350 2950
NoConn ~ 9350 3150
NoConn ~ 9350 3350
NoConn ~ 9350 3450
$Comp
L dk_TVS-Diodes:SP0503BAHTG D1
U 1 1 60FA7251
P 5500 3550
F 0 "D1" H 5450 3897 60  0000 C CNN
F 1 "SP0503BAHTG" H 5450 3791 60  0000 C CNN
F 2 "digikey-footprints:SOT-143-4" H 5700 3750 60  0001 L CNN
F 3 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5700 3850 60  0001 L CNN
F 4 "F2715CT-ND" H 5700 3950 60  0001 L CNN "Digi-Key_PN"
F 5 "SP0503BAHTG" H 5700 4050 60  0001 L CNN "MPN"
F 6 "Circuit Protection" H 5700 4150 60  0001 L CNN "Category"
F 7 "TVS - Diodes" H 5700 4250 60  0001 L CNN "Family"
F 8 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5700 4350 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/littelfuse-inc/SP0503BAHTG/F2715CT-ND/1154322" H 5700 4450 60  0001 L CNN "DK_Detail_Page"
F 10 "TVS DIODE 5.5V 8.5V SOT143-4" H 5700 4550 60  0001 L CNN "Description"
F 11 "Littelfuse Inc." H 5700 4650 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5700 4750 60  0001 L CNN "Status"
F 13 "https://www.digikey.com/en/products/detail/littelfuse-inc/SP0503BAHTG/1154308" H 5500 3550 50  0001 C CNN "DigiKey"
	1    5500 3550
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0109
U 1 1 60FAF33E
P 5850 3350
F 0 "#PWR0109" H 5850 3200 50  0001 C CNN
F 1 "+VUSB_IN" H 5865 3523 50  0000 C CNN
F 2 "" H 5850 3350 50  0001 C CNN
F 3 "" H 5850 3350 50  0001 C CNN
	1    5850 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3350 5850 3450
Wire Wire Line
	5850 3450 5700 3450
Text GLabel 5150 3650 0    50   Input ~ 0
D+
Wire Wire Line
	5150 3650 5200 3650
Text GLabel 5750 3650 2    50   Input ~ 0
D-
Wire Wire Line
	5700 3650 5750 3650
$Comp
L power:GND #PWR?
U 1 1 60FB327A
P 4850 3500
AR Path="/60FB327A" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60FB327A" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 4850 3250 50  0001 C CNN
F 1 "GND" H 4855 3327 50  0000 C CNN
F 2 "" H 4850 3500 50  0001 C CNN
F 3 "" H 4850 3500 50  0001 C CNN
	1    4850 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3450 4850 3450
Wire Wire Line
	4850 3450 4850 3500
$Comp
L power:GND #PWR?
U 1 1 60FC9AA1
P 9500 3750
F 0 "#PWR?" H 9500 3500 50  0001 C CNN
F 1 "GND" H 9650 3700 50  0000 C CNN
F 2 "" H 9500 3750 50  0001 C CNN
F 3 "" H 9500 3750 50  0001 C CNN
	1    9500 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 3750 9500 3650
Wire Wire Line
	9500 3650 9350 3650
$EndSCHEMATC
