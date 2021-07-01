EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L dk_Transistors-FETs-MOSFETs-Single:DMG2305UX-13 Q?
U 1 1 60D9F76A
P 6770 1900
AR Path="/60D9F76A" Ref="Q?"  Part="1" 
AR Path="/60D841D7/60D9F76A" Ref="Q2"  Part="1" 
F 0 "Q2" H 6870 2150 60  0000 L CNN
F 1 "DMG2305UX-13" H 6870 2050 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 6970 2100 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMG2305UX.pdf" H 6970 2200 60  0001 L CNN
F 4 "DMG2305UX-13DICT-ND" H 6970 2300 60  0001 L CNN "Digi-Key_PN"
F 5 "DMG2305UX-13" H 6970 2400 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 6970 2500 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 6970 2600 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/DMG2305UX.pdf" H 6970 2700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/DMG2305UX-13/DMG2305UX-13DICT-ND/4251589" H 6970 2800 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 20V 4.2A SOT23" H 6970 2900 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 6970 3000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6970 3100 60  0001 L CNN "Status"
F 13 "https://www.digikey.com/en/products/detail/yangzhou-yangjie-electronic-technology-co-ltd/YJL2301C-F2-0000HF/13911895" H 6770 1900 50  0001 C CNN "DigiKey(Alt)"
	1    6770 1900
	1    0    0    -1  
$EndComp
$Comp
L Diode:PMEG6030EP D?
U 1 1 60D9F770
P 6420 2350
AR Path="/60D9F770" Ref="D?"  Part="1" 
AR Path="/60D841D7/60D9F770" Ref="D3"  Part="1" 
F 0 "D3" H 6420 2450 50  0000 C CNN
F 1 "PMEG6030EP" H 6320 2250 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-128" H 6420 2175 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMEG6030EP.pdf" H 6420 2350 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/nexperia-usa-inc/PMEG6030EP-115/2296186" H 6420 2350 50  0001 C CNN "DigiKey"
F 5 "PMEG6030EP,115" H 6420 2350 50  0001 C CNN "MPN"
	1    6420 2350
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 60D9F787
P 5420 2200
AR Path="/60D9F787" Ref="R?"  Part="1" 
AR Path="/60D841D7/60D9F787" Ref="R10"  Part="1" 
F 0 "R10" H 5170 2250 50  0000 L CNN
F 1 "10k" H 5170 2150 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5420 2200 50  0001 C CNN
F 3 "~" H 5420 2200 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 5420 2200 50  0001 C CNN "DigiKey"
	1    5420 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D9F78D
P 5420 2400
AR Path="/60D9F78D" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F78D" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0112" H 5420 2150 50  0001 C CNN
F 1 "GND" H 5425 2227 50  0000 C CNN
F 2 "" H 5420 2400 50  0001 C CNN
F 3 "" H 5420 2400 50  0001 C CNN
	1    5420 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5420 2300 5420 2400
$Comp
L Device:C C?
U 1 1 60D9F796
P 6070 2650
AR Path="/60D9F796" Ref="C?"  Part="1" 
AR Path="/60D841D7/60D9F796" Ref="C4"  Part="1" 
F 0 "C4" H 6185 2696 50  0000 L CNN
F 1 "1uF" H 6185 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6108 2500 50  0001 C CNN
F 3 "" H 6070 2650 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C105K4RACAUTO/8635831" H 6070 2650 50  0001 C CNN "DigiKey"
	1    6070 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D9F79E
P 6070 3000
AR Path="/60D9F79E" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F79E" Ref="#PWR0113"  Part="1" 
F 0 "#PWR0113" H 6070 2750 50  0001 C CNN
F 1 "GND" H 6075 2827 50  0000 C CNN
F 2 "" H 6070 3000 50  0001 C CNN
F 3 "" H 6070 3000 50  0001 C CNN
	1    6070 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7695 2450 7695 2350
Wire Wire Line
	7695 2350 7420 2350
$Comp
L power:+BATT #PWR?
U 1 1 60D9F7B9
P 6770 1600
AR Path="/60D9F7B9" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7B9" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 6770 1450 50  0001 C CNN
F 1 "+BATT" H 6785 1773 50  0000 C CNN
F 2 "" H 6770 1600 50  0001 C CNN
F 3 "" H 6770 1600 50  0001 C CNN
	1    6770 1600
	1    0    0    -1  
$EndComp
Text Notes 6440 1160 0    118  ~ 0
Power Regulator
$Comp
L SparkFun-IC-Power:MAX1704X U?
U 1 1 60D9F7EA
P 1720 5890
AR Path="/60D9F7EA" Ref="U?"  Part="1" 
AR Path="/60D841D7/60D9F7EA" Ref="U6"  Part="1" 
F 0 "U6" H 1720 6450 45  0000 C CNN
F 1 "MAX1704X" H 1720 6366 45  0000 C CNN
F 2 "MAX17048G_T10:SON50P200X200X80-9N" H 1720 6290 20  0001 C CNN
F 3 "" H 1720 5890 60  0001 C CNN
F 4 "IC-10399" H 1720 6271 60  0000 C CNN "Field4"
F 5 "https://www.digikey.com/en/products/detail/maxim-integrated/MAX17048G-T10/3758921" H 1720 5890 50  0001 C CNN "DigiKey"
F 6 "MAX17048G+T10" H 1720 5890 50  0001 C CNN "MPN"
	1    1720 5890
	1    0    0    -1  
$EndComp
Text GLabel 2670 5690 2    50   Input ~ 0
SDA
Text GLabel 2670 5790 2    50   Input ~ 0
SCL
$Comp
L power:GND #PWR?
U 1 1 60D9F7F5
P 1070 6190
AR Path="/60D9F7F5" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7F5" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 1070 5940 50  0001 C CNN
F 1 "GND" H 1075 6017 50  0000 C CNN
F 2 "" H 1070 6190 50  0001 C CNN
F 3 "" H 1070 6190 50  0001 C CNN
	1    1070 6190
	1    0    0    -1  
$EndComp
Wire Wire Line
	1070 6190 1070 6090
Wire Wire Line
	1070 5990 1220 5990
Wire Wire Line
	1220 6090 1070 6090
Connection ~ 1070 6090
Wire Wire Line
	1070 6090 1070 5990
Wire Wire Line
	1070 5990 1070 5690
Wire Wire Line
	1070 5690 1220 5690
Connection ~ 1070 5990
Wire Wire Line
	1120 5590 1120 5790
Wire Wire Line
	1120 5890 1220 5890
Wire Wire Line
	1220 5790 1120 5790
Connection ~ 1120 5790
Wire Wire Line
	1120 5790 1120 5890
$Comp
L power:GND #PWR?
U 1 1 60D9F809
P 2320 6190
AR Path="/60D9F809" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F809" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 2320 5940 50  0001 C CNN
F 1 "GND" H 2325 6017 50  0000 C CNN
F 2 "" H 2320 6190 50  0001 C CNN
F 3 "" H 2320 6190 50  0001 C CNN
	1    2320 6190
	1    0    0    -1  
$EndComp
Wire Wire Line
	2320 6190 2320 5890
Wire Wire Line
	2320 5890 2220 5890
$Comp
L power:+BATT #PWR?
U 1 1 60D9F817
P 2730 6360
AR Path="/60D9F817" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F817" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 2730 6210 50  0001 C CNN
F 1 "+BATT" H 2745 6533 50  0000 C CNN
F 2 "" H 2730 6360 50  0001 C CNN
F 3 "" H 2730 6360 50  0001 C CNN
	1    2730 6360
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D9F81F
P 2730 6740
AR Path="/60D9F81F" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F81F" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 2730 6490 50  0001 C CNN
F 1 "GND" H 2735 6567 50  0000 C CNN
F 2 "" H 2730 6740 50  0001 C CNN
F 3 "" H 2730 6740 50  0001 C CNN
	1    2730 6740
	1    0    0    -1  
$EndComp
Text Notes 2150 4800 2    118  ~ 0
Fuel Gauge
$Comp
L power:+BATT #PWR?
U 1 1 60D9F82F
P 1120 5590
AR Path="/60D9F82F" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F82F" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 1120 5440 50  0001 C CNN
F 1 "+BATT" H 1135 5763 50  0000 C CNN
F 2 "" H 1120 5590 50  0001 C CNN
F 3 "" H 1120 5590 50  0001 C CNN
	1    1120 5590
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60DC1187
P 5675 5195
AR Path="/60DC1187" Ref="C?"  Part="1" 
AR Path="/60D841D7/60DC1187" Ref="C2"  Part="1" 
F 0 "C2" H 5790 5241 50  0000 L CNN
F 1 "4.7uF" H 5790 5150 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5713 5045 50  0001 C CNN
F 3 "" H 5675 5195 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0805C475K4RACTU/3317621" H 5675 5195 50  0001 C CNN "DigiKey"
	1    5675 5195
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60DC118F
P 5675 5445
AR Path="/60DC118F" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC118F" Ref="#PWR0124"  Part="1" 
F 0 "#PWR0124" H 5675 5195 50  0001 C CNN
F 1 "GND" H 5680 5272 50  0000 C CNN
F 2 "" H 5675 5445 50  0001 C CNN
F 3 "" H 5675 5445 50  0001 C CNN
	1    5675 5445
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60DC1195
P 6600 5650
AR Path="/60DC1195" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC1195" Ref="#PWR0125"  Part="1" 
F 0 "#PWR0125" H 6600 5400 50  0001 C CNN
F 1 "GND" H 6605 5477 50  0000 C CNN
F 2 "" H 6600 5650 50  0001 C CNN
F 3 "" H 6600 5650 50  0001 C CNN
	1    6600 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5675 5345 5675 5445
Wire Wire Line
	5675 4995 5675 5045
$Comp
L Device:R_US R?
U 1 1 60DC119E
P 6075 5545
AR Path="/60DC119E" Ref="R?"  Part="1" 
AR Path="/60D841D7/60DC119E" Ref="R9"  Part="1" 
F 0 "R9" H 6143 5591 50  0000 L CNN
F 1 "2k" H 6143 5500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6115 5535 50  0001 C CNN
F 3 "~" H 6075 5545 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-072KL/726726" H 6075 5545 50  0001 C CNN "DigiKey"
	1    6075 5545
	1    0    0    -1  
$EndComp
Wire Wire Line
	6075 5345 6075 5395
$Comp
L power:GND #PWR?
U 1 1 60DC11A6
P 6075 5795
AR Path="/60DC11A6" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC11A6" Ref="#PWR0126"  Part="1" 
F 0 "#PWR0126" H 6075 5545 50  0001 C CNN
F 1 "GND" H 6080 5622 50  0000 C CNN
F 2 "" H 6075 5795 50  0001 C CNN
F 3 "" H 6075 5795 50  0001 C CNN
	1    6075 5795
	1    0    0    -1  
$EndComp
Wire Wire Line
	6075 5795 6075 5695
$Comp
L power:+BATT #PWR?
U 1 1 60DC11AD
P 7325 4895
AR Path="/60DC11AD" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC11AD" Ref="#PWR0132"  Part="1" 
F 0 "#PWR0132" H 7325 4745 50  0001 C CNN
F 1 "+BATT" H 7340 5068 50  0000 C CNN
F 2 "" H 7325 4895 50  0001 C CNN
F 3 "" H 7325 4895 50  0001 C CNN
	1    7325 4895
	1    0    0    -1  
$EndComp
Wire Wire Line
	7325 4895 7325 5145
$Comp
L Device:C C?
U 1 1 60DC11B5
P 7325 5395
AR Path="/60DC11B5" Ref="C?"  Part="1" 
AR Path="/60D841D7/60DC11B5" Ref="C3"  Part="1" 
F 0 "C3" H 7440 5441 50  0000 L CNN
F 1 "4.7uF" H 7440 5350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7363 5245 50  0001 C CNN
F 3 "" H 7325 5395 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0805C475K4RACTU/3317621" H 7325 5395 50  0001 C CNN "DigiKey"
	1    7325 5395
	1    0    0    -1  
$EndComp
Wire Wire Line
	7325 5245 7325 5145
Connection ~ 7325 5145
$Comp
L power:GND #PWR?
U 1 1 60DC11BD
P 7325 5645
AR Path="/60DC11BD" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC11BD" Ref="#PWR0133"  Part="1" 
F 0 "#PWR0133" H 7325 5395 50  0001 C CNN
F 1 "GND" H 7330 5472 50  0000 C CNN
F 2 "" H 7325 5645 50  0001 C CNN
F 3 "" H 7325 5645 50  0001 C CNN
	1    7325 5645
	1    0    0    -1  
$EndComp
Wire Wire Line
	7325 5645 7325 5545
Wire Wire Line
	7325 5145 7650 5145
$Comp
L power:GND #PWR?
U 1 1 60DC11CC
P 7780 5690
AR Path="/60DC11CC" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60DC11CC" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 7780 5440 50  0001 C CNN
F 1 "GND" H 7785 5517 50  0000 C CNN
F 2 "" H 7780 5690 50  0001 C CNN
F 3 "" H 7780 5690 50  0001 C CNN
	1    7780 5690
	1    0    0    -1  
$EndComp
Wire Wire Line
	7875 5245 7780 5245
Wire Wire Line
	7780 5245 7780 5560
Text Notes 5875 4395 0    118  ~ 0
Lithium Charger w/ BMS
$Comp
L MiOrigin:+VUSB_IN #PWR0137
U 1 1 60DF442D
P 6600 4765
F 0 "#PWR0137" H 6600 4615 50  0001 C CNN
F 1 "+VUSB_IN" H 6615 4938 50  0000 C CNN
F 2 "" H 6600 4765 50  0001 C CNN
F 3 "" H 6600 4765 50  0001 C CNN
	1    6600 4765
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:+VUSB_IN #PWR0138
U 1 1 60DF4A37
P 5675 4995
F 0 "#PWR0138" H 5675 4845 50  0001 C CNN
F 1 "+VUSB_IN" H 5690 5168 50  0000 C CNN
F 2 "" H 5675 4995 50  0001 C CNN
F 3 "" H 5675 4995 50  0001 C CNN
	1    5675 4995
	1    0    0    -1  
$EndComp
Wire Wire Line
	6070 3000 6070 2800
Wire Wire Line
	6470 2000 6070 2000
Wire Wire Line
	6070 2000 5420 2000
Connection ~ 6070 2000
Connection ~ 5420 2000
Wire Wire Line
	5420 2000 5420 2100
Wire Wire Line
	6770 1700 6770 1600
Wire Wire Line
	6770 2100 6770 2350
$Comp
L SparkFun-Connectors:CONN_02JST-PTH-2 J?
U 1 1 60DC11C5
P 7975 5245
AR Path="/60DC11C5" Ref="J?"  Part="1" 
AR Path="/60D841D7/60DC11C5" Ref="J4"  Part="1" 
F 0 "J4" H 7747 5390 45  0000 R CNN
F 1 "CONN_02JST-PTH-2" H 7747 5306 45  0000 R CNN
F 2 "Connectors:JST-2-PTH" H 7975 5545 20  0001 C CNN
F 3 "" H 7975 5245 50  0001 C CNN
F 4 "CONN-09863" H 7747 5211 60  0000 R CNN "Field4"
	1    7975 5245
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6070 2000 6070 2350
Wire Wire Line
	6270 2350 6070 2350
Connection ~ 6070 2350
Wire Wire Line
	6070 2350 6070 2500
Wire Wire Line
	6570 2350 6770 2350
Connection ~ 6770 2350
$Comp
L MiOrigin:+VUSB_IN #PWR0136
U 1 1 60DF405D
P 5420 1600
F 0 "#PWR0136" H 5420 1450 50  0001 C CNN
F 1 "+VUSB_IN" H 5435 1773 50  0000 C CNN
F 2 "" H 5420 1600 50  0001 C CNN
F 3 "" H 5420 1600 50  0001 C CNN
	1    5420 1600
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:OS102011MA1QN1 S1
U 1 1 60DB7CB0
P 5490 7190
F 0 "S1" H 5578 7244 50  0000 L CNN
F 1 "OS102011MA1QN1" H 5578 7153 50  0000 L CNN
F 2 "MiOrigin:OS102011MA1QN1" H 5490 7190 50  0001 C CNN
F 3 "https://www.ckswitches.com/media/1428/os.pdf" H 5490 7190 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/c-k/OS102011MA1QN1/1981430" H 5490 7190 50  0001 C CNN "DigiKey"
	1    5490 7190
	1    0    0    -1  
$EndComp
Wire Wire Line
	5235 7190 5320 7190
Text GLabel 4885 7190 0    50   Input ~ 0
EN_SWITCH
Wire Wire Line
	4885 7190 4935 7190
Connection ~ 7695 2350
Connection ~ 9295 2350
Wire Wire Line
	9295 2100 9295 2350
$Comp
L power:+3.3V #PWR?
U 1 1 60D9F7DF
P 9295 2100
AR Path="/60D9F7DF" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7DF" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 9295 1950 50  0001 C CNN
F 1 "+3.3V" H 9310 2273 50  0000 C CNN
F 2 "" H 9295 2100 50  0001 C CNN
F 3 "" H 9295 2100 50  0001 C CNN
	1    9295 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9295 2800 9295 2700
Wire Wire Line
	8895 2700 8895 2800
$Comp
L power:GND #PWR?
U 1 1 60D9F7D7
P 9295 2800
AR Path="/60D9F7D7" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7D7" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 9295 2550 50  0001 C CNN
F 1 "GND" H 9300 2627 50  0000 C CNN
F 2 "" H 9295 2800 50  0001 C CNN
F 3 "" H 9295 2800 50  0001 C CNN
	1    9295 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60D9F7D1
P 8895 2800
AR Path="/60D9F7D1" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7D1" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 8895 2550 50  0001 C CNN
F 1 "GND" H 8900 2627 50  0000 C CNN
F 2 "" H 8895 2800 50  0001 C CNN
F 3 "" H 8895 2800 50  0001 C CNN
	1    8895 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8895 2350 9295 2350
Connection ~ 8895 2350
Wire Wire Line
	8745 2350 8895 2350
Wire Wire Line
	9295 2400 9295 2350
Wire Wire Line
	8895 2350 8895 2400
$Comp
L Device:C C?
U 1 1 60D9F7C6
P 9295 2550
AR Path="/60D9F7C6" Ref="C?"  Part="1" 
AR Path="/60D841D7/60D9F7C6" Ref="C7"  Part="1" 
F 0 "C7" H 9410 2596 50  0000 L CNN
F 1 "10uF" H 9410 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 9333 2400 50  0001 C CNN
F 3 "" H 9295 2550 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C1206C106K4RAC7215/12701027" H 9295 2550 50  0001 C CNN "DigiKey"
	1    9295 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 60D9F7C0
P 8895 2550
AR Path="/60D9F7C0" Ref="C?"  Part="1" 
AR Path="/60D841D7/60D9F7C0" Ref="C5"  Part="1" 
F 0 "C5" H 9010 2596 50  0000 L CNN
F 1 "1uF" H 9010 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8933 2400 50  0001 C CNN
F 3 "" H 8895 2550 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C105K4RACAUTO/8635831" H 8895 2550 50  0001 C CNN "DigiKey"
	1    8895 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8445 2800 8445 2750
$Comp
L power:GND #PWR?
U 1 1 60D9F7B2
P 8445 2800
AR Path="/60D9F7B2" Ref="#PWR?"  Part="1" 
AR Path="/60D841D7/60D9F7B2" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 8445 2550 50  0001 C CNN
F 1 "GND" H 8450 2627 50  0000 C CNN
F 2 "" H 8445 2800 50  0001 C CNN
F 3 "" H 8445 2800 50  0001 C CNN
	1    8445 2800
	1    0    0    -1  
$EndComp
Connection ~ 8095 2350
Wire Wire Line
	7695 2350 8095 2350
Wire Wire Line
	7745 2450 7695 2450
Wire Wire Line
	8045 2450 8145 2450
$Comp
L Device:R_US R?
U 1 1 60D9F7A5
P 7895 2450
AR Path="/60D9F7A5" Ref="R?"  Part="1" 
AR Path="/60D841D7/60D9F7A5" Ref="R11"  Part="1" 
F 0 "R11" V 7995 2400 50  0000 C CNN
F 1 "10k" V 8095 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7935 2440 50  0001 C CNN
F 3 "~" H 7895 2450 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 7895 2450 50  0001 C CNN "DigiKey"
	1    7895 2450
	0    1    1    0   
$EndComp
$Comp
L SparkFun-PowerSymbols:VIN #SUPPLY?
U 1 1 60D9F77B
P 8095 1945
AR Path="/60D9F77B" Ref="#SUPPLY?"  Part="1" 
AR Path="/60D841D7/60D9F77B" Ref="#SUPPLY0101"  Part="1" 
F 0 "#SUPPLY0101" H 8145 1945 45  0001 L BNN
F 1 "VIN" H 8095 2095 45  0000 C CNN
F 2 "XXX-00000" H 8345 2095 60  0001 L CNN
F 3 "" H 8095 1945 60  0001 C CNN
	1    8095 1945
	1    0    0    -1  
$EndComp
Wire Wire Line
	8095 1945 8095 2175
Wire Wire Line
	8145 2350 8095 2350
$Comp
L Regulator_Linear:AP2112K-3.3 U?
U 1 1 60D9F75B
P 8445 2450
AR Path="/60D9F75B" Ref="U?"  Part="1" 
AR Path="/60D841D7/60D9F75B" Ref="U5"  Part="1" 
F 0 "U5" H 8445 2792 50  0000 C CNN
F 1 "AP2112K-3.3" H 8445 2701 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 8445 2775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2112.pdf" H 8445 2550 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/diodes-incorporated/AP7365-33WG-7/4249847" H 8445 2450 50  0001 C CNN "DigiKey(Alt)"
	1    8445 2450
	1    0    0    -1  
$EndComp
$Comp
L dk_Transistors-FETs-MOSFETs-Single:DMG2305UX-13 Q?
U 1 1 60DDD22B
P 7220 2350
AR Path="/60DDD22B" Ref="Q?"  Part="1" 
AR Path="/60D841D7/60DDD22B" Ref="Q5"  Part="1" 
F 0 "Q5" V 7445 2200 60  0000 L CNN
F 1 "DMG2305UX-13" V 7345 2175 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 7420 2550 60  0001 L CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMG2305UX.pdf" H 7420 2650 60  0001 L CNN
F 4 "DMG2305UX-13DICT-ND" H 7420 2750 60  0001 L CNN "Digi-Key_PN"
F 5 "DMG2305UX-13" H 7420 2850 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 7420 2950 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 7420 3050 60  0001 L CNN "Family"
F 8 "https://www.diodes.com/assets/Datasheets/DMG2305UX.pdf" H 7420 3150 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/diodes-incorporated/DMG2305UX-13/DMG2305UX-13DICT-ND/4251589" H 7420 3250 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET P-CH 20V 4.2A SOT23" H 7420 3350 60  0001 L CNN "Description"
F 11 "Diodes Incorporated" H 7420 3450 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7420 3550 60  0001 L CNN "Status"
F 13 "https://www.digikey.com/en/products/detail/yangzhou-yangjie-electronic-technology-co-ltd/YJL2301C-F2-0000HF/13911895" V 7220 2350 50  0001 C CNN "DigiKey(Alt)"
	1    7220 2350
	0    1    -1   0   
$EndComp
Wire Wire Line
	7020 2350 6895 2350
Text GLabel 7145 2700 2    50   Input ~ 0
EN_SWITCH
Wire Wire Line
	7145 2700 7120 2700
Wire Wire Line
	7120 2700 7120 2650
$Comp
L Device:R_US R14
U 1 1 60DC08DD
P 5085 7190
F 0 "R14" V 4880 7190 50  0000 C CNN
F 1 "100k" V 4971 7190 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5125 7180 50  0001 C CNN
F 3 "~" H 5085 7190 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-10100KL/2345148" H 5085 7190 50  0001 C CNN "DigiKey"
	1    5085 7190
	0    1    1    0   
$EndComp
Wire Wire Line
	5280 7110 5320 7110
$Comp
L power:GND #PWR0145
U 1 1 60DF890A
P 5280 7310
F 0 "#PWR0145" H 5280 7060 50  0001 C CNN
F 1 "GND" H 5285 7137 50  0000 C CNN
F 2 "" H 5280 7310 50  0001 C CNN
F 3 "" H 5280 7310 50  0001 C CNN
	1    5280 7310
	1    0    0    -1  
$EndComp
Wire Wire Line
	5280 7310 5280 7270
Wire Wire Line
	5280 7270 5320 7270
$Comp
L Device:C C?
U 1 1 60D9F811
P 2730 6550
AR Path="/60D9F811" Ref="C?"  Part="1" 
AR Path="/60D841D7/60D9F811" Ref="C8"  Part="1" 
F 0 "C8" H 2550 6500 50  0000 C CNN
F 1 "0.1uF" H 2490 6600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2768 6400 50  0001 C CNN
F 3 "" H 2730 6550 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 2730 6550 50  0001 C CNN "DigiKey"
	1    2730 6550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2730 6700 2730 6740
Wire Wire Line
	2730 6360 2730 6400
Wire Notes Line
	6970 6540 3430 6540
Wire Notes Line
	3430 470  3430 7790
Wire Notes Line
	470  4330 3430 4330
Wire Notes Line
	3430 3510 11220 3510
Wire Wire Line
	2220 5690 2670 5690
Wire Wire Line
	2220 5790 2670 5790
Text GLabel 2670 5990 2    50   Input ~ 0
BAT_ALERT
Wire Wire Line
	2220 5990 2670 5990
$Comp
L Connector:TestPoint TP3
U 1 1 60D83759
P 7650 5145
F 0 "TP3" H 7700 5395 50  0000 L CNN
F 1 "+BATT TP" H 7700 5295 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 7850 5145 50  0001 C CNN
F 3 "~" H 7850 5145 50  0001 C CNN
	1    7650 5145
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP4
U 1 1 60D878C2
P 7780 5560
F 0 "TP4" V 7734 5748 50  0000 L CNN
F 1 "GND (+BATT) TP" V 7825 5748 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 7980 5560 50  0001 C CNN
F 3 "~" H 7980 5560 50  0001 C CNN
	1    7780 5560
	0    1    1    0   
$EndComp
Connection ~ 7780 5560
Wire Wire Line
	7780 5560 7780 5690
$Comp
L Connector:TestPoint TP5
U 1 1 60D8A1D4
P 8095 2175
F 0 "TP5" V 8325 2365 50  0000 C CNN
F 1 "VIN TP" V 8215 2355 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 8295 2175 50  0001 C CNN
F 3 "~" H 8295 2175 50  0001 C CNN
	1    8095 2175
	0    -1   -1   0   
$EndComp
Connection ~ 8095 2175
Wire Wire Line
	8095 2175 8095 2350
Connection ~ 7650 5145
Wire Wire Line
	7650 5145 7875 5145
Wire Wire Line
	5420 1600 5420 2000
NoConn ~ 7000 5345
Wire Wire Line
	6600 5545 6600 5650
Wire Wire Line
	6600 4945 6600 4765
Wire Wire Line
	7325 5145 7000 5145
$Comp
L Battery_Management:MCP73832-2-OT U3
U 1 1 60D60955
P 6600 5245
F 0 "U3" H 6450 5640 50  0000 C CNN
F 1 "MCP73832-2-OT" H 6225 5555 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6650 4995 50  0001 L CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001984g.pdf" H 6450 5195 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/microchip-technology/MCP73832T-2DCI-OT/1223150" H 6600 5245 50  0001 C CNN "DigiKey"
	1    6600 5245
	1    0    0    -1  
$EndComp
Wire Wire Line
	6075 5345 6200 5345
Text GLabel 6870 2775 0    50   Input ~ 0
V_PREMOS
Connection ~ 6895 2350
Wire Wire Line
	6895 2350 6770 2350
Text GLabel 5100 6850 0    50   Input ~ 0
V_PREMOS
Wire Wire Line
	5280 6850 5100 6850
Wire Wire Line
	5280 6850 5280 7110
Wire Wire Line
	6870 2775 6895 2775
Wire Wire Line
	6895 2350 6895 2775
$EndSCHEMATC
