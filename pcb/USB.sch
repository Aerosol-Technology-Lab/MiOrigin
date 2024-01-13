EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title "MiOrigin Controller"
Date "2021-06-11"
Rev "1.1"
Comp "Aerosol Technologies Lab - BAEN @ TAMU"
Comment1 "Author: Charlemagne Wong | CECN 21'"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 3320 2505
Wire Wire Line
	3320 2405 3320 2505
Wire Wire Line
	3120 2405 3320 2405
Wire Wire Line
	3320 2505 3320 2555
Wire Wire Line
	3120 2505 3320 2505
$Comp
L power:GND #PWR?
U 1 1 60D75987
P 3320 2555
AR Path="/60D75987" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60D75987" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 3320 2305 50  0001 C CNN
F 1 "GND" H 3325 2382 50  0000 C CNN
F 2 "" H 3320 2555 50  0001 C CNN
F 3 "" H 3320 2555 50  0001 C CNN
	1    3320 2555
	1    0    0    -1  
$EndComp
Wire Wire Line
	2820 2505 2670 2505
Wire Wire Line
	2670 2405 2820 2405
$Comp
L Device:R_US R?
U 1 1 60D7598F
P 2970 2505
AR Path="/60D7598F" Ref="R?"  Part="1" 
AR Path="/60D5DC34/60D7598F" Ref="R8"  Part="1" 
F 0 "R8" V 3070 2355 50  0000 C CNN
F 1 "5.1k" V 3070 2555 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3010 2495 50  0001 C CNN
F 3 "~" H 2970 2505 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/bourns-inc/CR0603-FX-5101ELF/3784064" H 2970 2505 50  0001 C CNN "DigiKey"
	1    2970 2505
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 60D75995
P 2970 2405
AR Path="/60D75995" Ref="R?"  Part="1" 
AR Path="/60D5DC34/60D75995" Ref="R7"  Part="1" 
F 0 "R7" V 2870 2255 50  0000 C CNN
F 1 "5.1k" V 2870 2455 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3010 2395 50  0001 C CNN
F 3 "~" H 2970 2405 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/bourns-inc/CR0603-FX-5101ELF/3784064" H 2970 2405 50  0001 C CNN "DigiKey"
	1    2970 2405
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0143
U 1 1 60D70D19
P 2070 4955
F 0 "#PWR0143" H 2070 4705 50  0001 C CNN
F 1 "GND" H 2075 4782 50  0000 C CNN
F 2 "" H 2070 4955 50  0001 C CNN
F 3 "" H 2070 4955 50  0001 C CNN
	1    2070 4955
	1    0    0    -1  
$EndComp
Wire Wire Line
	2070 4805 2070 4955
NoConn ~ 2670 4505
NoConn ~ 2670 4405
NoConn ~ 2670 4205
NoConn ~ 2670 4105
NoConn ~ 2670 3905
NoConn ~ 2670 3805
NoConn ~ 2670 3605
NoConn ~ 2670 3505
NoConn ~ 1770 4805
Text GLabel 2670 3005 2    50   Input ~ 0
D+
Text GLabel 2670 2805 2    50   Input ~ 0
D-
Text GLabel 2670 2705 2    50   Input ~ 0
D-
Text GLabel 2670 2905 2    50   Input ~ 0
D+
NoConn ~ 2670 3205
NoConn ~ 2670 3305
$Comp
L MiOrigin:+VUSB_IN #PWR0144
U 1 1 60D3C419
P 2720 2105
F 0 "#PWR0144" H 2720 1955 50  0001 C CNN
F 1 "+VUSB_IN" H 2735 2278 50  0000 C CNN
F 2 "" H 2720 2105 50  0001 C CNN
F 3 "" H 2720 2105 50  0001 C CNN
	1    2720 2105
	1    0    0    -1  
$EndComp
Wire Wire Line
	2720 2205 2670 2205
$Comp
L Connector:USB_C_Receptacle J?
U 1 1 60D7597C
P 2070 3205
AR Path="/60D7597C" Ref="J?"  Part="1" 
AR Path="/60D5DC34/60D7597C" Ref="J2"  Part="1" 
F 0 "J2" H 2177 4472 50  0000 C CNN
F 1 "USB_C_Receptacle" H 2177 4381 50  0000 C CNN
F 2 "Connector_USB:USB_C_Receptacle_GCT_USB4085" H 2220 3205 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/GCT%20PDFs/Ionex_USB_Conn_Br.pdf" H 2220 3205 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/gct/USB4085-GF-A/9859662" H 2070 3205 50  0001 C CNN "Digikey"
F 5 "USB4085-GF-A" H 2070 3205 50  0001 C CNN "MPN"
F 6 "https://www.digikey.com/en/products/detail/gct/USB4085-GF-A/9859662" H 2070 3205 50  0001 C CNN "DigiKey"
	1    2070 3205
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
	2720 2105 2720 2155
$Comp
L Connector:TestPoint TP6
U 1 1 60EB0C6B
P 2720 2155
F 0 "TP6" V 2674 2343 50  0000 L CNN
F 1 "+VUSB_IN_TP" V 2765 2343 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 2920 2155 50  0001 C CNN
F 3 "~" H 2920 2155 50  0001 C CNN
	1    2720 2155
	0    1    1    0   
$EndComp
Connection ~ 2720 2155
Wire Wire Line
	2720 2155 2720 2205
Text GLabel 9920 2925 2    50   Input ~ 0
CH340-TX
Text GLabel 9920 3025 2    50   Input ~ 0
CH340-RX
Text GLabel 9920 3425 2    50   Input ~ 0
CH340-DTR
Text GLabel 9920 3225 2    50   Input ~ 0
CH340-RTS
$Comp
L CP2102:CP2102 U2
U 1 1 60F884F8
P 9120 3125
F 0 "U2" H 9120 4090 50  0000 C CNN
F 1 "CP2102" H 9120 3999 50  0000 C CNN
F 2 "CP2102:QFN50P500X500X100-29N" H 9120 3125 50  0001 L BNN
F 3 "" H 9120 3125 50  0001 L BNN
F 4 "CP2102" H 9120 3125 50  0001 L BNN "MP"
F 5 "None" H 9120 3125 50  0001 L BNN "PRICE"
F 6 "Silicon Labs" H 9120 3125 50  0001 L BNN "MF"
F 7 "WFQFN-20 Silicon Labs" H 9120 3125 50  0001 L BNN "PACKAGE"
F 8 "Unavailable" H 9120 3125 50  0001 L BNN "AVAILABILITY"
F 9 "USB to UART Bridge" H 9120 3125 50  0001 L BNN "DESCRIPTION"
F 10 "https://www.digikey.com/en/products/detail/silicon-labs/CP2102-GM/696598" H 9120 3125 50  0001 C CNN "DigiKey"
	1    9120 3125
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0106
U 1 1 60F92083
P 7770 2975
F 0 "#PWR0106" H 7770 2825 50  0001 C CNN
F 1 "+VUSB_IN" H 7770 3125 50  0000 C CNN
F 2 "" H 7770 2975 50  0001 C CNN
F 3 "" H 7770 2975 50  0001 C CNN
	1    7770 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	7970 2425 7970 2625
Wire Wire Line
	7970 2625 8070 2625
NoConn ~ 8420 2825
$Comp
L Device:C_Small C1
U 1 1 60F96294
P 8070 2725
F 0 "C1" H 7820 2825 50  0000 L CNN
F 1 "1uF" H 7820 2725 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8070 2725 50  0001 C CNN
F 3 "~" H 8070 2725 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C105K4RACAUTO/8635831" H 8070 2725 50  0001 C CNN "DigiKey"
	1    8070 2725
	1    0    0    -1  
$EndComp
Connection ~ 8070 2625
Wire Wire Line
	8070 2625 8270 2625
$Comp
L Device:C_Small C10
U 1 1 60F96A58
P 8270 2725
F 0 "C10" H 8370 2775 50  0000 L CNN
F 1 "0.1uF" H 8366 2707 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8270 2725 50  0001 C CNN
F 3 "~" H 8270 2725 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 8270 2725 50  0001 C CNN "DigiKey"
	1    8270 2725
	1    0    0    -1  
$EndComp
Connection ~ 8270 2625
Wire Wire Line
	8270 2625 8420 2625
$Comp
L power:GND #PWR0107
U 1 1 60F98FE3
P 8170 2825
F 0 "#PWR0107" H 8170 2575 50  0001 C CNN
F 1 "GND" H 8176 2671 50  0000 C CNN
F 2 "" H 8170 2825 50  0001 C CNN
F 3 "" H 8170 2825 50  0001 C CNN
	1    8170 2825
	1    0    0    -1  
$EndComp
Wire Wire Line
	8170 2825 8070 2825
Wire Wire Line
	8170 2825 8270 2825
Connection ~ 8170 2825
$Comp
L Device:C_Small C18
U 1 1 60F9B4B0
P 10070 2525
F 0 "C18" H 10170 2575 50  0000 L CNN
F 1 "0.1uF" H 10166 2507 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10070 2525 50  0001 C CNN
F 3 "~" H 10070 2525 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 10070 2525 50  0001 C CNN "DigiKey"
	1    10070 2525
	1    0    0    -1  
$EndComp
Wire Wire Line
	9820 2425 10070 2425
$Comp
L power:GND #PWR0108
U 1 1 60F9D614
P 10070 2725
F 0 "#PWR0108" H 10070 2475 50  0001 C CNN
F 1 "GND" H 10220 2675 50  0000 C CNN
F 2 "" H 10070 2725 50  0001 C CNN
F 3 "" H 10070 2725 50  0001 C CNN
	1    10070 2725
	1    0    0    -1  
$EndComp
NoConn ~ 9820 2625
NoConn ~ 9820 2725
Text GLabel 8320 3125 0    50   Input ~ 0
D+
Wire Wire Line
	8320 3125 8420 3125
Text GLabel 8320 3225 0    50   Input ~ 0
D-
Wire Wire Line
	8320 3225 8420 3225
NoConn ~ 8420 3625
Wire Wire Line
	9920 2925 9820 2925
Wire Wire Line
	9820 3025 9920 3025
Wire Wire Line
	9920 3425 9820 3425
Wire Wire Line
	9920 3225 9820 3225
NoConn ~ 9820 3125
NoConn ~ 9820 3325
NoConn ~ 9820 3525
NoConn ~ 9820 3625
$Comp
L dk_TVS-Diodes:SP0503BAHTG D1
U 1 1 60FA7251
P 5655 2920
F 0 "D1" H 5605 3267 60  0000 C CNN
F 1 "SP0503BAHTG" H 5605 3161 60  0000 C CNN
F 2 "digikey-footprints:SOT-143-4" H 5855 3120 60  0001 L CNN
F 3 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5855 3220 60  0001 L CNN
F 4 "F2715CT-ND" H 5855 3320 60  0001 L CNN "Digi-Key_PN"
F 5 "SP0503BAHTG" H 5855 3420 60  0001 L CNN "MPN"
F 6 "Circuit Protection" H 5855 3520 60  0001 L CNN "Category"
F 7 "TVS - Diodes" H 5855 3620 60  0001 L CNN "Family"
F 8 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5855 3720 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/littelfuse-inc/SP0503BAHTG/F2715CT-ND/1154322" H 5855 3820 60  0001 L CNN "DK_Detail_Page"
F 10 "TVS DIODE 5.5V 8.5V SOT143-4" H 5855 3920 60  0001 L CNN "Description"
F 11 "Littelfuse Inc." H 5855 4020 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5855 4120 60  0001 L CNN "Status"
F 13 "https://www.digikey.com/en/products/detail/littelfuse-inc/SP0503BAHTG/1154308" H 5655 2920 50  0001 C CNN "DigiKey"
	1    5655 2920
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0109
U 1 1 60FAF33E
P 6005 2720
F 0 "#PWR0109" H 6005 2570 50  0001 C CNN
F 1 "+VUSB_IN" H 6020 2893 50  0000 C CNN
F 2 "" H 6005 2720 50  0001 C CNN
F 3 "" H 6005 2720 50  0001 C CNN
	1    6005 2720
	1    0    0    -1  
$EndComp
Wire Wire Line
	6005 2720 6005 2820
Wire Wire Line
	6005 2820 5855 2820
Text GLabel 5305 3020 0    50   Input ~ 0
D+
Wire Wire Line
	5305 3020 5355 3020
Text GLabel 5905 3020 2    50   Input ~ 0
D-
Wire Wire Line
	5855 3020 5905 3020
$Comp
L power:GND #PWR?
U 1 1 60FB327A
P 5005 2870
AR Path="/60FB327A" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60FB327A" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 5005 2620 50  0001 C CNN
F 1 "GND" H 5010 2697 50  0000 C CNN
F 2 "" H 5005 2870 50  0001 C CNN
F 3 "" H 5005 2870 50  0001 C CNN
	1    5005 2870
	1    0    0    -1  
$EndComp
Wire Wire Line
	5355 2820 5005 2820
Wire Wire Line
	5005 2820 5005 2870
$Comp
L power:GND #PWR0111
U 1 1 60FC9AA1
P 9970 3925
F 0 "#PWR0111" H 9970 3675 50  0001 C CNN
F 1 "GND" H 10120 3875 50  0000 C CNN
F 2 "" H 9970 3925 50  0001 C CNN
F 3 "" H 9970 3925 50  0001 C CNN
	1    9970 3925
	1    0    0    -1  
$EndComp
Wire Wire Line
	9970 3925 9970 3825
Wire Wire Line
	9970 3825 9820 3825
$Comp
L power:+3.3V #PWR0127
U 1 1 60FE1EDC
P 7970 2425
F 0 "#PWR0127" H 7970 2275 50  0001 C CNN
F 1 "+3.3V" H 7985 2598 50  0000 C CNN
F 2 "" H 7970 2425 50  0001 C CNN
F 3 "" H 7970 2425 50  0001 C CNN
	1    7970 2425
	1    0    0    -1  
$EndComp
Wire Wire Line
	7770 2975 7770 3025
Wire Wire Line
	7770 3025 8420 3025
$Comp
L Device:C_Small C19
U 1 1 60FE5D2A
P 10470 2525
F 0 "C19" H 10562 2571 50  0000 L CNN
F 1 "4.7uF" H 10562 2480 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10470 2525 50  0001 C CNN
F 3 "~" H 10470 2525 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0805C475K4RACTU/3317621" H 10470 2525 50  0001 C CNN "DigiKey"
	1    10470 2525
	1    0    0    -1  
$EndComp
Wire Wire Line
	10070 2725 10070 2675
Wire Wire Line
	10070 2675 10470 2675
Wire Wire Line
	10470 2675 10470 2625
Connection ~ 10070 2675
Wire Wire Line
	10070 2675 10070 2625
$Comp
L power:+3.3V #PWR0160
U 1 1 60FE7835
P 10070 2275
F 0 "#PWR0160" H 10070 2125 50  0001 C CNN
F 1 "+3.3V" H 10085 2448 50  0000 C CNN
F 2 "" H 10070 2275 50  0001 C CNN
F 3 "" H 10070 2275 50  0001 C CNN
	1    10070 2275
	1    0    0    -1  
$EndComp
Wire Wire Line
	10070 2275 10070 2425
Connection ~ 10070 2425
Wire Wire Line
	10070 2425 10470 2425
Text Notes 4575 3515 0    79   ~ 0
USB-C ESD Protection TVS Diode
Text Notes 8800 4205 0    79   ~ 0
USB to UART
$EndSCHEMATC
