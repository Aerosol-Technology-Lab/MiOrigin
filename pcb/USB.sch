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
Text GLabel 9715 3620 2    50   Input ~ 0
CH340-TX
Text GLabel 9715 3720 2    50   Input ~ 0
CH340-RX
Text GLabel 9715 4120 2    50   Input ~ 0
CH340-DTR
Text GLabel 9715 3920 2    50   Input ~ 0
CH340-RTS
$Comp
L CP2102:CP2102 U2
U 1 1 60F884F8
P 8915 3820
F 0 "U2" H 8915 4785 50  0000 C CNN
F 1 "CP2102" H 8915 4694 50  0000 C CNN
F 2 "CP2102:QFN50P500X500X100-29N" H 8915 3820 50  0001 L BNN
F 3 "" H 8915 3820 50  0001 L BNN
F 4 "CP2102" H 8915 3820 50  0001 L BNN "MP"
F 5 "None" H 8915 3820 50  0001 L BNN "PRICE"
F 6 "Silicon Labs" H 8915 3820 50  0001 L BNN "MF"
F 7 "WFQFN-20 Silicon Labs" H 8915 3820 50  0001 L BNN "PACKAGE"
F 8 "Unavailable" H 8915 3820 50  0001 L BNN "AVAILABILITY"
F 9 "USB to UART Bridge" H 8915 3820 50  0001 L BNN "DESCRIPTION"
F 10 "https://www.digikey.com/en/products/detail/silicon-labs/CP2102-GM/696598" H 8915 3820 50  0001 C CNN "DigiKey"
	1    8915 3820
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0106
U 1 1 60F92083
P 7565 3670
F 0 "#PWR0106" H 7565 3520 50  0001 C CNN
F 1 "+VUSB_IN" H 7565 3820 50  0000 C CNN
F 2 "" H 7565 3670 50  0001 C CNN
F 3 "" H 7565 3670 50  0001 C CNN
	1    7565 3670
	1    0    0    -1  
$EndComp
Wire Wire Line
	7765 3120 7765 3320
Wire Wire Line
	7765 3320 7865 3320
NoConn ~ 8215 3520
$Comp
L Device:C_Small C1
U 1 1 60F96294
P 7865 3420
F 0 "C1" H 7615 3520 50  0000 L CNN
F 1 "1uF" H 7615 3420 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7865 3420 50  0001 C CNN
F 3 "~" H 7865 3420 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C105K4RACAUTO/8635831" H 7865 3420 50  0001 C CNN "DigiKey"
	1    7865 3420
	1    0    0    -1  
$EndComp
Connection ~ 7865 3320
Wire Wire Line
	7865 3320 8065 3320
$Comp
L Device:C_Small C10
U 1 1 60F96A58
P 8065 3420
F 0 "C10" H 8165 3470 50  0000 L CNN
F 1 "0.1uF" H 8161 3402 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8065 3420 50  0001 C CNN
F 3 "~" H 8065 3420 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 8065 3420 50  0001 C CNN "DigiKey"
	1    8065 3420
	1    0    0    -1  
$EndComp
Connection ~ 8065 3320
Wire Wire Line
	8065 3320 8215 3320
$Comp
L power:GND #PWR0107
U 1 1 60F98FE3
P 7965 3520
F 0 "#PWR0107" H 7965 3270 50  0001 C CNN
F 1 "GND" H 7971 3366 50  0000 C CNN
F 2 "" H 7965 3520 50  0001 C CNN
F 3 "" H 7965 3520 50  0001 C CNN
	1    7965 3520
	1    0    0    -1  
$EndComp
Wire Wire Line
	7965 3520 7865 3520
Wire Wire Line
	7965 3520 8065 3520
Connection ~ 7965 3520
$Comp
L Device:C_Small C18
U 1 1 60F9B4B0
P 9865 3220
F 0 "C18" H 9965 3270 50  0000 L CNN
F 1 "0.1uF" H 9961 3202 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9865 3220 50  0001 C CNN
F 3 "~" H 9865 3220 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 9865 3220 50  0001 C CNN "DigiKey"
	1    9865 3220
	1    0    0    -1  
$EndComp
Wire Wire Line
	9615 3120 9865 3120
$Comp
L power:GND #PWR0108
U 1 1 60F9D614
P 9865 3420
F 0 "#PWR0108" H 9865 3170 50  0001 C CNN
F 1 "GND" H 10015 3370 50  0000 C CNN
F 2 "" H 9865 3420 50  0001 C CNN
F 3 "" H 9865 3420 50  0001 C CNN
	1    9865 3420
	1    0    0    -1  
$EndComp
NoConn ~ 9615 3320
NoConn ~ 9615 3420
Text GLabel 8115 3820 0    50   Input ~ 0
D+
Wire Wire Line
	8115 3820 8215 3820
Text GLabel 8115 3920 0    50   Input ~ 0
D-
Wire Wire Line
	8115 3920 8215 3920
NoConn ~ 8215 4320
Wire Wire Line
	9715 3620 9615 3620
Wire Wire Line
	9615 3720 9715 3720
Wire Wire Line
	9715 4120 9615 4120
Wire Wire Line
	9715 3920 9615 3920
NoConn ~ 9615 3820
NoConn ~ 9615 4020
NoConn ~ 9615 4220
NoConn ~ 9615 4320
$Comp
L dk_TVS-Diodes:SP0503BAHTG D1
U 1 1 60FA7251
P 5655 3560
F 0 "D1" H 5605 3907 60  0000 C CNN
F 1 "SP0503BAHTG" H 5605 3801 60  0000 C CNN
F 2 "digikey-footprints:SOT-143-4" H 5855 3760 60  0001 L CNN
F 3 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5855 3860 60  0001 L CNN
F 4 "F2715CT-ND" H 5855 3960 60  0001 L CNN "Digi-Key_PN"
F 5 "SP0503BAHTG" H 5855 4060 60  0001 L CNN "MPN"
F 6 "Circuit Protection" H 5855 4160 60  0001 L CNN "Category"
F 7 "TVS - Diodes" H 5855 4260 60  0001 L CNN "Family"
F 8 "https://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 5855 4360 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/littelfuse-inc/SP0503BAHTG/F2715CT-ND/1154322" H 5855 4460 60  0001 L CNN "DK_Detail_Page"
F 10 "TVS DIODE 5.5V 8.5V SOT143-4" H 5855 4560 60  0001 L CNN "Description"
F 11 "Littelfuse Inc." H 5855 4660 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5855 4760 60  0001 L CNN "Status"
F 13 "https://www.digikey.com/en/products/detail/littelfuse-inc/SP0503BAHTG/1154308" H 5655 3560 50  0001 C CNN "DigiKey"
	1    5655 3560
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0109
U 1 1 60FAF33E
P 6005 3360
F 0 "#PWR0109" H 6005 3210 50  0001 C CNN
F 1 "+VUSB_IN" H 6020 3533 50  0000 C CNN
F 2 "" H 6005 3360 50  0001 C CNN
F 3 "" H 6005 3360 50  0001 C CNN
	1    6005 3360
	1    0    0    -1  
$EndComp
Wire Wire Line
	6005 3360 6005 3460
Wire Wire Line
	6005 3460 5855 3460
Text GLabel 5305 3660 0    50   Input ~ 0
D+
Wire Wire Line
	5305 3660 5355 3660
Text GLabel 5905 3660 2    50   Input ~ 0
D-
Wire Wire Line
	5855 3660 5905 3660
$Comp
L power:GND #PWR?
U 1 1 60FB327A
P 5005 3510
AR Path="/60FB327A" Ref="#PWR?"  Part="1" 
AR Path="/60D5DC34/60FB327A" Ref="#PWR0110"  Part="1" 
F 0 "#PWR0110" H 5005 3260 50  0001 C CNN
F 1 "GND" H 5010 3337 50  0000 C CNN
F 2 "" H 5005 3510 50  0001 C CNN
F 3 "" H 5005 3510 50  0001 C CNN
	1    5005 3510
	1    0    0    -1  
$EndComp
Wire Wire Line
	5355 3460 5005 3460
Wire Wire Line
	5005 3460 5005 3510
$Comp
L power:GND #PWR0111
U 1 1 60FC9AA1
P 9765 4620
F 0 "#PWR0111" H 9765 4370 50  0001 C CNN
F 1 "GND" H 9915 4570 50  0000 C CNN
F 2 "" H 9765 4620 50  0001 C CNN
F 3 "" H 9765 4620 50  0001 C CNN
	1    9765 4620
	1    0    0    -1  
$EndComp
Wire Wire Line
	9765 4620 9765 4520
Wire Wire Line
	9765 4520 9615 4520
$Comp
L power:+3.3V #PWR0127
U 1 1 60FE1EDC
P 7765 3120
F 0 "#PWR0127" H 7765 2970 50  0001 C CNN
F 1 "+3.3V" H 7780 3293 50  0000 C CNN
F 2 "" H 7765 3120 50  0001 C CNN
F 3 "" H 7765 3120 50  0001 C CNN
	1    7765 3120
	1    0    0    -1  
$EndComp
Wire Wire Line
	7565 3670 7565 3720
Wire Wire Line
	7565 3720 8215 3720
$Comp
L Device:C_Small C19
U 1 1 60FE5D2A
P 10265 3220
F 0 "C19" H 10357 3266 50  0000 L CNN
F 1 "4.7uF" H 10357 3175 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10265 3220 50  0001 C CNN
F 3 "~" H 10265 3220 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0805C475K4RACTU/3317621" H 10265 3220 50  0001 C CNN "DigiKey"
	1    10265 3220
	1    0    0    -1  
$EndComp
Wire Wire Line
	9865 3420 9865 3370
Wire Wire Line
	9865 3370 10265 3370
Wire Wire Line
	10265 3370 10265 3320
Connection ~ 9865 3370
Wire Wire Line
	9865 3370 9865 3320
$Comp
L power:+3.3V #PWR0160
U 1 1 60FE7835
P 9865 2970
F 0 "#PWR0160" H 9865 2820 50  0001 C CNN
F 1 "+3.3V" H 9880 3143 50  0000 C CNN
F 2 "" H 9865 2970 50  0001 C CNN
F 3 "" H 9865 2970 50  0001 C CNN
	1    9865 2970
	1    0    0    -1  
$EndComp
Wire Wire Line
	9865 2970 9865 3120
Connection ~ 9865 3120
Wire Wire Line
	9865 3120 10265 3120
$EndSCHEMATC
