EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title "MiOrigin Controller"
Date "2021-06-11"
Rev "0.0"
Comp "BAEN - Aerosol Technologies Lab"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1570 4930 1570 4980
Text GLabel 1520 5630 0    50   Input ~ 0
ESP_0-QPWR
Wire Wire Line
	1520 5630 1570 5630
Wire Wire Line
	1570 4530 1570 4480
Wire Wire Line
	1570 4480 1470 4480
Connection ~ 2320 4730
Wire Wire Line
	2370 4730 2320 4730
Connection ~ 2220 5330
Wire Wire Line
	2370 5330 2220 5330
Text GLabel 2370 5330 2    50   Input ~ 0
CH340-RTS
Text GLabel 2370 4730 2    50   Input ~ 0
CH340-DTR
Wire Wire Line
	1570 5080 2320 5080
Wire Wire Line
	2220 4980 2220 5330
Wire Wire Line
	1570 4980 2220 4980
Wire Wire Line
	1870 4730 1920 4730
$Comp
L Device:R_Small_US R1
U 1 1 60C4F142
P 2020 4730
F 0 "R1" V 1815 4730 50  0000 C CNN
F 1 "10k" V 1906 4730 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2020 4730 50  0001 C CNN
F 3 "~" H 2020 4730 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 2020 4730 50  0001 C CNN "DigiKey"
	1    2020 4730
	0    1    1    0   
$EndComp
Wire Wire Line
	2120 4730 2320 4730
Text GLabel 2500 1150 2    50   Input ~ 0
ESP_0-QPWR
Wire Wire Line
	2500 1150 2400 1150
Wire Wire Line
	1570 5130 1570 5080
Wire Wire Line
	1570 5530 1570 5630
Wire Wire Line
	1920 5330 1870 5330
Wire Wire Line
	2120 5330 2220 5330
$Comp
L Device:R_Small_US R2
U 1 1 60C5441D
P 2020 5330
F 0 "R2" V 1815 5330 50  0000 C CNN
F 1 "10k" V 1906 5330 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2020 5330 50  0001 C CNN
F 3 "~" H 2020 5330 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 2020 5330 50  0001 C CNN "DigiKey"
	1    2020 5330
	0    1    1    0   
$EndComp
Wire Wire Line
	2320 5080 2320 4730
$Comp
L power:+3.3V #PWR0102
U 1 1 60C5A4E3
P 1800 700
F 0 "#PWR0102" H 1800 550 50  0001 C CNN
F 1 "+3.3V" H 1815 873 50  0000 C CNN
F 2 "" H 1800 700 50  0001 C CNN
F 3 "" H 1800 700 50  0001 C CNN
	1    1800 700 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0103
U 1 1 60C5CBED
P 850 800
F 0 "#PWR0103" H 850 650 50  0001 C CNN
F 1 "+3.3V" H 865 973 50  0000 C CNN
F 2 "" H 850 800 50  0001 C CNN
F 3 "" H 850 800 50  0001 C CNN
	1    850  800 
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R3
U 1 1 60C5E684
P 850 950
F 0 "R3" H 918 996 50  0000 L CNN
F 1 "10k" H 918 905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 850 950 50  0001 C CNN
F 3 "~" H 850 950 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 850 950 50  0001 C CNN "DigiKey"
	1    850  950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1050 850  1150
Wire Wire Line
	850  1150 1200 1150
Wire Wire Line
	850  800  850  850 
Text GLabel 800  1150 0    50   Input ~ 0
~RESET
Wire Wire Line
	800  1150 850  1150
Connection ~ 850  1150
Text GLabel 2500 1450 2    50   Input ~ 0
CH340-TX
Wire Wire Line
	2500 1450 2400 1450
NoConn ~ 1200 1350
NoConn ~ 1200 1450
Text GLabel 2500 2550 2    50   Input ~ 0
SDA
Wire Wire Line
	2400 2550 2500 2550
Wire Wire Line
	9330 2080 8830 2080
Wire Wire Line
	8880 1880 9330 1880
Wire Wire Line
	8880 1480 8880 1580
$Comp
L power:+3.3V #PWR0128
U 1 1 60D1B7F8
P 8880 1480
F 0 "#PWR0128" H 8880 1330 50  0001 C CNN
F 1 "+3.3V" H 8895 1653 50  0000 C CNN
F 2 "" H 8880 1480 50  0001 C CNN
F 3 "" H 8880 1480 50  0001 C CNN
	1    8880 1480
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0129
U 1 1 60D1AAEF
P 8830 2330
F 0 "#PWR0129" H 8830 2080 50  0001 C CNN
F 1 "GND" H 8835 2157 50  0000 C CNN
F 2 "" H 8830 2330 50  0001 C CNN
F 3 "" H 8830 2330 50  0001 C CNN
	1    8830 2330
	1    0    0    -1  
$EndComp
Wire Wire Line
	9230 1680 9280 1680
Text GLabel 9230 1680 0    50   Input ~ 0
SD_CS
Wire Wire Line
	9230 1980 9330 1980
Wire Wire Line
	9230 1780 9330 1780
Text Notes 9690 1020 0    118  ~ 0
microSD Card
Wire Notes Line
	3700 450  3700 7800
$Comp
L Device:C C6
U 1 1 60D36709
P 8150 1060
F 0 "C6" H 8265 1106 50  0000 L CNN
F 1 "0.1uF" H 8265 1015 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8188 910 50  0001 C CNN
F 3 "" H 8150 1060 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 8150 1060 50  0001 C CNN "DigiKey"
	1    8150 1060
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0130
U 1 1 60D37261
P 8150 810
F 0 "#PWR0130" H 8150 660 50  0001 C CNN
F 1 "+3.3V" H 8165 983 50  0000 C CNN
F 2 "" H 8150 810 50  0001 C CNN
F 3 "" H 8150 810 50  0001 C CNN
	1    8150 810 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 810  8150 910 
$Comp
L power:GND #PWR0131
U 1 1 60D3B365
P 8150 1360
F 0 "#PWR0131" H 8150 1110 50  0001 C CNN
F 1 "GND" H 8155 1187 50  0000 C CNN
F 2 "" H 8150 1360 50  0001 C CNN
F 3 "" H 8150 1360 50  0001 C CNN
	1    8150 1360
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1360 8150 1210
Text GLabel 2500 2750 2    50   Input ~ 0
VSPI_MOSI
Text GLabel 2500 2450 2    50   Input ~ 0
VSPI_MISO
Wire Wire Line
	2500 2450 2400 2450
Wire Wire Line
	2500 2750 2400 2750
Text GLabel 2500 2250 2    50   Input ~ 0
SD_CS
Text GLabel 2500 1250 2    50   Input ~ 0
CH340-RX
Wire Wire Line
	2500 1250 2400 1250
NoConn ~ 2400 1350
Wire Wire Line
	2500 2350 2400 2350
Wire Wire Line
	2500 2650 2400 2650
$Comp
L Device:R_Small_US R5
U 1 1 60D8F347
P 9130 2280
F 0 "R5" V 9210 2270 50  0000 C CNN
F 1 "10k" V 9280 2280 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9130 2280 50  0001 C CNN
F 3 "~" H 9130 2280 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 9130 2280 50  0001 C CNN "DigiKey"
	1    9130 2280
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small_US R4
U 1 1 60D8FF03
P 9130 1580
F 0 "R4" V 8925 1580 50  0000 C CNN
F 1 "10k" V 9016 1580 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9130 1580 50  0001 C CNN
F 3 "~" H 9130 1580 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 9130 1580 50  0001 C CNN "DigiKey"
	1    9130 1580
	0    1    1    0   
$EndComp
Wire Wire Line
	9230 2280 9330 2280
Wire Wire Line
	9330 1580 9230 1580
Wire Wire Line
	9030 1580 8880 1580
Connection ~ 8880 1580
Wire Wire Line
	8880 1580 8880 1880
Wire Wire Line
	8830 2080 8830 2330
Wire Wire Line
	9030 2280 8880 2280
Wire Wire Line
	8880 2280 8880 1880
Connection ~ 8880 1880
$Comp
L Device:R_Small_US R6
U 1 1 60DA967C
P 9280 1380
F 0 "R6" H 9230 1280 50  0000 R CNN
F 1 "10k" H 9230 1380 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9280 1380 50  0001 C CNN
F 3 "~" H 9280 1380 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 9280 1380 50  0001 C CNN "DigiKey"
	1    9280 1380
	-1   0    0    1   
$EndComp
Wire Wire Line
	9280 1480 9280 1680
Connection ~ 9280 1680
Wire Wire Line
	9280 1680 9330 1680
$Comp
L power:+3.3V #PWR0104
U 1 1 60DADE13
P 9280 1230
F 0 "#PWR0104" H 9280 1080 50  0001 C CNN
F 1 "+3.3V" H 9295 1403 50  0000 C CNN
F 2 "" H 9280 1230 50  0001 C CNN
F 3 "" H 9280 1230 50  0001 C CNN
	1    9280 1230
	1    0    0    -1  
$EndComp
Wire Wire Line
	9280 1230 9280 1280
$Comp
L Connector:Micro_SD_Card J3
U 1 1 60D047A9
P 10230 1880
F 0 "J3" H 10180 2597 50  0000 C CNN
F 1 "Micro_SD_Card" H 10180 2506 50  0000 C CNN
F 2 "DM3CS-SF:HRS_DM3CS-SF" H 11380 2180 50  0001 C CNN
F 3 "http://katalog.we-online.de/em/datasheet/693072010801.pdf" H 10230 1880 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/hirose-electric-co-ltd/DM3CS-SF/2602739?s=N4IgjCBcoLQBxVAYygMwIYBsDOBTANCAPZQDaIATAGwgC6AvvYRWSACICyAzAMIDKMPgDE69IA" H 10230 1880 50  0001 C CNN "DigiKey"
	1    10230 1880
	1    0    0    -1  
$EndComp
NoConn ~ 1200 2850
NoConn ~ 1200 2750
NoConn ~ 1200 2650
NoConn ~ 1200 2550
NoConn ~ 1200 2450
NoConn ~ 1200 2350
$Comp
L RF_Module:ESP32-WROOM-32U U1
U 1 1 60C34232
P 1800 2350
F 0 "U1" H 1950 3800 50  0000 C CNN
F 1 "ESP32-WROOM-32E" H 2300 3700 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 1800 850 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32d_esp32-wroom-32u_datasheet_en.pdf" H 1500 2400 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/espressif-systems/ESP32-WROOM-32E-16MB/11613144" H 1800 2350 50  0001 C CNN "DigiKey"
F 5 "ESP32-WROOM-32E (4MB HIGH TEMP)" H 1800 2350 50  0001 C CNN "MPN"
F 6 "https://www.digikey.com/en/products/detail/espressif-systems/ESP32-WROOM-32E-4MB-HIGH-TEMP/12696413" H 1800 2350 50  0001 C CNN "DigiKey(Alt)"
	1    1800 2350
	1    0    0    -1  
$EndComp
Text GLabel 1470 4480 0    50   Input ~ 0
~RESET
$Sheet
S 12850 4250 1200 700 
U 60D5DC34
F0 "USB" 50
F1 "USB.sch" 50
$EndSheet
$Sheet
S 12850 5250 1150 600 
U 60D841D7
F0 "Power Regulators" 50
F1 "Power Regulators.sch" 50
$EndSheet
Text GLabel 2500 2650 2    50   Input ~ 0
SCL
Text GLabel 2500 1850 2    50   Input ~ 0
HSPI_MOSI
Text GLabel 2500 2850 2    50   Input ~ 0
HSPI_MISO
Text GLabel 3350 1700 1    50   Input ~ 0
HSPI_MOSI
$Comp
L power:GND #PWR0135
U 1 1 60D515CF
P 3350 2100
F 0 "#PWR0135" H 3350 1850 50  0001 C CNN
F 1 "GND" H 3355 1927 50  0000 C CNN
F 2 "" H 3350 2100 50  0001 C CNN
F 3 "" H 3350 2100 50  0001 C CNN
	1    3350 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R12
U 1 1 60D524D5
P 3350 1900
F 0 "R12" H 3418 1946 50  0000 L CNN
F 1 "NC" H 3418 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3390 1890 50  0001 C CNN
F 3 "~" H 3350 1900 50  0001 C CNN
F 4 "This was 10k, I don't think this is needed anymore" H 3350 1900 50  0001 C CNN "Notes"
F 5 "~" H 3350 1900 50  0001 C CNN "DigiKey"
	1    3350 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1750 3350 1700
Wire Wire Line
	3350 2050 3350 2100
Text Notes 3650 2650 2    50   ~ 0
Pull down \nto allow ESP32\nto boot\nsuccessfully
Wire Wire Line
	2500 1850 2400 1850
Text GLabel 2500 1950 2    50   Input ~ 0
HSPI_SCLK
Wire Wire Line
	2500 1950 2400 1950
Text GLabel 2500 1550 2    50   Input ~ 0
LCD_CS
Wire Wire Line
	2500 2250 2400 2250
Wire Wire Line
	2500 1550 2400 1550
NoConn ~ 2400 1650
Wire Wire Line
	2500 2850 2400 2850
NoConn ~ 2400 1750
Wire Notes Line
	3700 5800 500  5800
Text GLabel 8540 1790 1    50   Input ~ 0
SD_CS
Text GLabel 8240 2180 0    50   Input ~ 0
HSPI_MISO
Wire Wire Line
	8240 2180 8265 2180
Wire Wire Line
	8815 2180 9330 2180
Wire Wire Line
	8540 1790 8540 1830
$Comp
L MiOrigin:PTS636-SMG25J-SMTR-LFS S2
U 1 1 60E5B9C3
P 1245 6855
F 0 "S2" V 1125 6795 50  0000 R CNN
F 1 "PTS636-SMG25J-SMTR-LFS" V 1045 6805 50  0000 R CNN
F 2 "PTS636SK50SMTRLFS:PTS636SK50SMTRLFS" H 1245 6855 50  0001 C CNN
F 3 "https://www.ckswitches.com/media/2779/pts636.pdf" H 1245 6855 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/c-k/PTS636-SMG25J-SMTR-LFS/10071740" H 1245 6855 50  0001 C CNN "DigiKey"
	1    1245 6855
	0    -1   -1   0   
$EndComp
$Comp
L MiOrigin:PTS636-SMG25J-SMTR-LFS S3
U 1 1 60E5D370
P 2505 6845
F 0 "S3" V 2655 6785 50  0000 R CNN
F 1 "PTS636-SMG25J-SMTR-LFS" V 2575 6785 50  0000 R CNN
F 2 "PTS636SK50SMTRLFS:PTS636SK50SMTRLFS" H 2505 6845 50  0001 C CNN
F 3 "https://www.ckswitches.com/media/2779/pts636.pdf" H 2505 6845 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/c-k/PTS636-SMG25J-SMTR-LFS/10071740" H 2505 6845 50  0001 C CNN "DigiKey"
	1    2505 6845
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0146
U 1 1 60E5E5AB
P 1245 7185
F 0 "#PWR0146" H 1245 6935 50  0001 C CNN
F 1 "GND" H 1250 7012 50  0000 C CNN
F 2 "" H 1245 7185 50  0001 C CNN
F 3 "" H 1245 7185 50  0001 C CNN
	1    1245 7185
	1    0    0    -1  
$EndComp
Wire Wire Line
	1245 7080 1245 7185
$Comp
L power:GND #PWR0147
U 1 1 60E611C2
P 2505 7175
F 0 "#PWR0147" H 2505 6925 50  0001 C CNN
F 1 "GND" H 2510 7002 50  0000 C CNN
F 2 "" H 2505 7175 50  0001 C CNN
F 3 "" H 2505 7175 50  0001 C CNN
	1    2505 7175
	1    0    0    -1  
$EndComp
Wire Wire Line
	2505 7175 2505 7070
Text GLabel 2445 6540 0    50   Input ~ 0
~RESET
Wire Wire Line
	2445 6540 2505 6540
Wire Wire Line
	2505 6540 2505 6620
Text GLabel 1185 6545 0    50   Input ~ 0
ESP_0-QPWR
Wire Wire Line
	1185 6545 1245 6545
Wire Wire Line
	1245 6545 1245 6630
Text Notes 790  6200 0    79   ~ 0
GPIO/Boot Button
Text Notes 2540 6220 0    79   ~ 0
Reset Button
$Comp
L Device:C C11
U 1 1 60F11211
P 5530 7180
F 0 "C11" H 5310 7260 50  0000 L CNN
F 1 "0.1uF" H 5210 7170 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5568 7030 50  0001 C CNN
F 3 "" H 5530 7180 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 5530 7180 50  0001 C CNN "DigiKey"
	1    5530 7180
	1    0    0    -1  
$EndComp
Wire Wire Line
	5530 7330 5530 7530
Wire Wire Line
	5530 7530 5820 7530
Wire Wire Line
	5820 7530 5820 7480
Wire Wire Line
	5530 6810 5820 6810
Wire Wire Line
	5820 6810 5820 6860
Wire Wire Line
	5530 6810 5530 7030
$Comp
L power:+3.3V #PWR0148
U 1 1 60F1913D
P 5820 6770
F 0 "#PWR0148" H 5820 6620 50  0001 C CNN
F 1 "+3.3V" H 5835 6943 50  0000 C CNN
F 2 "" H 5820 6770 50  0001 C CNN
F 3 "" H 5820 6770 50  0001 C CNN
	1    5820 6770
	1    0    0    -1  
$EndComp
Wire Wire Line
	5820 6770 5820 6810
Connection ~ 5820 6810
$Comp
L power:GND #PWR0149
U 1 1 60F1B31F
P 5820 7550
F 0 "#PWR0149" H 5820 7300 50  0001 C CNN
F 1 "GND" H 5825 7377 50  0000 C CNN
F 2 "" H 5820 7550 50  0001 C CNN
F 3 "" H 5820 7550 50  0001 C CNN
	1    5820 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5820 7550 5820 7530
Connection ~ 5820 7530
$Comp
L 2021-06-22_18-51-54:SN74LVC125ADBR_(Units) U7
U 1 1 60F25FE0
P 8540 2180
F 0 "U7" H 8670 1790 50  0000 C CNN
F 1 "SN74LVC125ADBR_(Units)" H 8640 1690 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 8540 2180 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/scas290q/scas290q.pdf" H 8540 2180 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/texas-instruments/SN74LVC125ADBR/377410" H 8540 2180 50  0001 C CNN "DigiKey"
	1    8540 2180
	-1   0    0    -1  
$EndComp
$Comp
L 2021-06-22_18-51-54:SN74LVC125ADBR_(Units) U7
U 5 1 60F271D5
P 5820 7170
F 0 "U7" H 5908 7216 50  0000 L CNN
F 1 "SN74LVC125ADBR_(Units)" H 5908 7125 50  0000 L CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 5820 7170 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/scas290q/scas290q.pdf" H 5820 7170 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/texas-instruments/SN74LVC125ADBR/377410" H 5820 7170 50  0001 C CNN "DigiKey"
	5    5820 7170
	1    0    0    -1  
$EndComp
$Comp
L Connector:DB9_Male_MountingHoles J?
U 1 1 60D49BDD
P 7400 2480
AR Path="/60D5DC34/60D49BDD" Ref="J?"  Part="1" 
AR Path="/60D49BDD" Ref="J5"  Part="1" 
F 0 "J5" H 6920 2020 50  0000 L CNN
F 1 "DB9_Male_MountingHoles" H 6400 1880 50  0000 L CNN
F 2 "MiOrigin:DB9_MALE" H 7400 2480 50  0001 C CNN
F 3 "https://www.amphenol-icc.com/media/wysiwyg/files/drawing/10130914.pdf" H 7400 2480 50  0001 C CNN
F 4 "LD09P33E4GX00LF" H 7400 2480 50  0001 C CNN "MPN"
F 5 "https://www.digikey.com/en/products/detail/amphenol-icc-fci/LD09P33E4GX00LF/4997289" H 7400 2480 50  0001 C CNN "DigiKey"
	1    7400 2480
	1    0    0    -1  
$EndComp
$Comp
L Interface_UART:MAX3232 U?
U 1 1 60D49BE3
P 5550 1980
AR Path="/60D5DC34/60D49BE3" Ref="U?"  Part="1" 
AR Path="/60D49BE3" Ref="U8"  Part="1" 
F 0 "U8" H 5000 3130 50  0000 C CNN
F 1 "MAX3232" H 5110 3040 50  0000 C CNN
F 2 "MAX3232:SOIC127P1030X265-16N" H 5600 930 50  0001 L CNN
F 3 "https://www.ti.com/lit/ds/symlink/max3232e.pdf?HQS=dis-dk-null-digikeymode-dsf-pf-null-wwe&ts=1624419706022&ref_url=https%253A%252F%252Fwww.ti.com%252Fgeneral%252Fdocs%252Fsuppproductinfo.tsp%253FdistId%253D10%2526gotoUrl%253Dhttps%253A%252F%252Fwww.ti.com%252Flit%252Fgpn%252Fmax3232e" H 5550 2080 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/texas-instruments/MAX3232EIDWR/1120595?utm_source=snapeda&utm_medium=aggregator&utm_campaign=buynow" H 5550 1980 50  0001 C CNN "DigiKey"
F 5 "MAX3232EIDWR" H 5550 1980 50  0001 C CNN "MPN"
	1    5550 1980
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 60D4B880
P 690 2230
F 0 "C12" H 805 2276 50  0000 L CNN
F 1 "0.1uF" H 805 2185 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 728 2080 50  0001 C CNN
F 3 "" H 690 2230 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 690 2230 50  0001 C CNN "DigiKey"
	1    690  2230
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 60D4CFB6
P 1800 3920
F 0 "#PWR0101" H 1800 3670 50  0001 C CNN
F 1 "GND" H 1805 3747 50  0000 C CNN
F 2 "" H 1800 3920 50  0001 C CNN
F 3 "" H 1800 3920 50  0001 C CNN
	1    1800 3920
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3750 1800 3900
$Comp
L power:GND #PWR0150
U 1 1 60D4EC96
P 690 2480
F 0 "#PWR0150" H 690 2230 50  0001 C CNN
F 1 "GND" H 695 2307 50  0000 C CNN
F 2 "" H 690 2480 50  0001 C CNN
F 3 "" H 690 2480 50  0001 C CNN
	1    690  2480
	1    0    0    -1  
$EndComp
Wire Wire Line
	690  2480 690  2380
$Comp
L power:+3.3V #PWR0151
U 1 1 60D56F71
P 5550 720
F 0 "#PWR0151" H 5550 570 50  0001 C CNN
F 1 "+3.3V" H 5565 893 50  0000 C CNN
F 2 "" H 5550 720 50  0001 C CNN
F 3 "" H 5550 720 50  0001 C CNN
	1    5550 720 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 720  5550 780 
$Comp
L power:+3.3V #PWR0152
U 1 1 60D59D82
P 690 1970
F 0 "#PWR0152" H 690 1820 50  0001 C CNN
F 1 "+3.3V" H 705 2143 50  0000 C CNN
F 2 "" H 690 1970 50  0001 C CNN
F 3 "" H 690 1970 50  0001 C CNN
	1    690  1970
	1    0    0    -1  
$EndComp
Wire Wire Line
	690  2080 690  1970
$Comp
L power:GND #PWR0153
U 1 1 60D5C756
P 5550 3240
F 0 "#PWR0153" H 5550 2990 50  0001 C CNN
F 1 "GND" H 5555 3067 50  0000 C CNN
F 2 "" H 5550 3240 50  0001 C CNN
F 3 "" H 5550 3240 50  0001 C CNN
	1    5550 3240
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 3240 5550 3180
$Comp
L Device:C C13
U 1 1 60D61FD7
P 4260 1010
F 0 "C13" H 4375 1056 50  0000 L CNN
F 1 "0.1uF" H 4375 965 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4298 860 50  0001 C CNN
F 3 "" H 4260 1010 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 4260 1010 50  0001 C CNN "DigiKey"
	1    4260 1010
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0154
U 1 1 60D61FDD
P 4260 1260
F 0 "#PWR0154" H 4260 1010 50  0001 C CNN
F 1 "GND" H 4265 1087 50  0000 C CNN
F 2 "" H 4260 1260 50  0001 C CNN
F 3 "" H 4260 1260 50  0001 C CNN
	1    4260 1260
	1    0    0    -1  
$EndComp
Wire Wire Line
	4260 1260 4260 1160
$Comp
L power:+3.3V #PWR0155
U 1 1 60D61FE4
P 4260 750
F 0 "#PWR0155" H 4260 600 50  0001 C CNN
F 1 "+3.3V" H 4275 923 50  0000 C CNN
F 2 "" H 4260 750 50  0001 C CNN
F 3 "" H 4260 750 50  0001 C CNN
	1    4260 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4260 860  4260 750 
$Comp
L Device:C_Small C14
U 1 1 60D65DD8
P 4600 1230
F 0 "C14" H 4692 1276 50  0000 L CNN
F 1 "0.1uF" H 4692 1185 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4600 1230 50  0001 C CNN
F 3 "" H 4600 1230 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 4600 1230 50  0001 C CNN "DigiKey"
	1    4600 1230
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1080 4600 1080
Wire Wire Line
	4600 1080 4600 1130
Wire Wire Line
	4600 1330 4600 1380
Wire Wire Line
	4600 1380 4750 1380
$Comp
L Device:C_Small C15
U 1 1 60D6CD2D
P 6450 1230
F 0 "C15" H 6542 1276 50  0000 L CNN
F 1 "0.1uF" H 6542 1185 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6450 1230 50  0001 C CNN
F 3 "" H 6450 1230 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 6450 1230 50  0001 C CNN "DigiKey"
	1    6450 1230
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1130 6450 1080
Wire Wire Line
	6450 1080 6350 1080
Wire Wire Line
	6350 1380 6450 1380
Wire Wire Line
	6450 1380 6450 1330
$Comp
L Device:C_Small C16
U 1 1 60D7A3D1
P 6550 1580
F 0 "C16" V 6750 1580 50  0000 C CNN
F 1 "0.1uF" V 6650 1580 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6550 1580 50  0001 C CNN
F 3 "" H 6550 1580 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 6550 1580 50  0001 C CNN "DigiKey"
	1    6550 1580
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 1580 6350 1580
Wire Wire Line
	6450 1880 6350 1880
Wire Wire Line
	6800 1880 6650 1880
Wire Wire Line
	6650 1580 6800 1580
Wire Wire Line
	6800 1580 6800 1880
Connection ~ 6800 1880
$Comp
L Device:C_Small C17
U 1 1 60D7D0C1
P 6550 1880
F 0 "C17" V 6750 1880 50  0000 C CNN
F 1 "0.1uF" V 6650 1880 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6550 1880 50  0001 C CNN
F 3 "" H 6550 1880 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 6550 1880 50  0001 C CNN "DigiKey"
	1    6550 1880
	0    -1   -1   0   
$EndComp
NoConn ~ 7400 3080
Wire Wire Line
	6350 2080 6650 2080
Wire Wire Line
	6350 2480 7100 2480
Wire Wire Line
	6650 2080 6650 2680
Wire Wire Line
	6650 2680 7100 2680
Wire Wire Line
	4750 2080 4550 2080
Wire Wire Line
	4650 3430 4550 3430
Text GLabel 2500 2950 2    50   Input ~ 0
RS232-TX
Text GLabel 2500 3050 2    50   Input ~ 0
RS232-RX
Wire Wire Line
	2500 3050 2400 3050
Wire Wire Line
	2400 2950 2500 2950
Text GLabel 4350 1730 0    50   Input ~ 0
RS232-TX
Wire Wire Line
	4300 3030 4400 3030
Wire Wire Line
	4400 3030 4400 3230
Wire Wire Line
	4750 2480 4650 2480
Wire Wire Line
	4650 2480 4650 3430
Text GLabel 4300 3030 0    50   Input ~ 0
RS232-RX
Wire Wire Line
	4350 1730 4400 1730
Wire Wire Line
	4400 1730 4400 1880
Text GLabel 4350 2430 0    50   Input ~ 0
CH340-TX
Wire Wire Line
	4300 3780 4400 3780
Wire Wire Line
	4400 3780 4400 3630
Text GLabel 4300 3780 0    50   Input ~ 0
CH340-RX
Wire Wire Line
	4350 2430 4400 2430
Wire Wire Line
	4400 2430 4400 2280
NoConn ~ 4750 2280
NoConn ~ 4750 2680
NoConn ~ 6350 2680
NoConn ~ 6350 2280
NoConn ~ -18350 4100
$Comp
L 2021-06-22_18-51-54:SN74LVC125ADBR_(Units) U7
U 2 1 60EC5F59
P 4740 5370
F 0 "U7" H 4740 5223 50  0000 C CNN
F 1 "SN74LVC125ADBR_(Units)" H 4740 5132 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 4740 5370 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/scas290q/scas290q.pdf" H 4740 5370 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/texas-instruments/SN74LVC125ADBR/377410" H 4740 5370 50  0001 C CNN "DigiKey"
	2    4740 5370
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4740 5020 4740 4770
Text GLabel 4590 4770 0    50   Input ~ 0
LCD_CS
Wire Wire Line
	4590 4770 4740 4770
Text GLabel 4340 5370 0    50   Input ~ 0
VSPI_MISO
Wire Wire Line
	4465 5370 4340 5370
Text GLabel 5640 5270 0    50   Input ~ 0
VSPI_MOSI
Text GLabel 5640 5170 0    50   Input ~ 0
VSPI_SCLK
Text GLabel 2500 2350 2    50   Input ~ 0
VSPI_SCLK
Text GLabel 9230 1980 0    50   Input ~ 0
HSPI_SCLK
$Comp
L power:GND #PWR0142
U 1 1 60F0AE54
P 6950 2130
F 0 "#PWR0142" H 6950 1880 50  0001 C CNN
F 1 "GND" H 6955 1957 50  0000 C CNN
F 2 "" H 6950 2130 50  0001 C CNN
F 3 "" H 6950 2130 50  0001 C CNN
	1    6950 2130
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2130 6950 2080
Wire Wire Line
	6950 2080 7100 2080
Wire Wire Line
	6800 1930 6800 1880
$Comp
L power:GND #PWR0156
U 1 1 60D80004
P 6800 1930
F 0 "#PWR0156" H 6800 1680 50  0001 C CNN
F 1 "GND" H 6805 1757 50  0000 C CNN
F 2 "" H 6800 1930 50  0001 C CNN
F 3 "" H 6800 1930 50  0001 C CNN
	1    6800 1930
	1    0    0    -1  
$EndComp
$Comp
L MiOrigin:3.5-TFT-LCD-SPI U4
U 1 1 60F836E9
P 6340 5370
F 0 "U4" H 6540 4870 50  0000 C CNN
F 1 "3.5-TFT-LCD-SPI" H 6790 4770 50  0000 C CNN
F 2 "MiOrigin:3.5-TFT-LCD-SPI" H 5840 5420 50  0001 C CNN
F 3 "~" H 5840 5420 50  0001 C CNN
	1    6340 5370
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0158
U 1 1 60F8755F
P 6340 5970
F 0 "#PWR0158" H 6340 5720 50  0001 C CNN
F 1 "GND" H 6345 5797 50  0000 C CNN
F 2 "" H 6340 5970 50  0001 C CNN
F 3 "" H 6340 5970 50  0001 C CNN
	1    6340 5970
	1    0    0    -1  
$EndComp
Wire Wire Line
	6340 5970 6340 5870
$Comp
L power:+3.3V #PWR0139
U 1 1 60F9B230
P 6340 4720
F 0 "#PWR0139" H 6340 4570 50  0001 C CNN
F 1 "+3.3V" H 6355 4893 50  0000 C CNN
F 2 "" H 6340 4720 50  0001 C CNN
F 3 "" H 6340 4720 50  0001 C CNN
	1    6340 4720
	1    0    0    -1  
$EndComp
Wire Wire Line
	6340 4720 6340 4820
Wire Wire Line
	5640 5170 5840 5170
Wire Wire Line
	5640 5270 5840 5270
Wire Wire Line
	5015 5370 5840 5370
Text GLabel 5640 5470 0    50   Input ~ 0
LCD_CS
Wire Wire Line
	5640 5470 5840 5470
$Comp
L power:+3.3V #PWR0141
U 1 1 60FD44E6
P 7040 4820
F 0 "#PWR0141" H 7040 4670 50  0001 C CNN
F 1 "+3.3V" H 7055 4993 50  0000 C CNN
F 2 "" H 7040 4820 50  0001 C CNN
F 3 "" H 7040 4820 50  0001 C CNN
	1    7040 4820
	1    0    0    -1  
$EndComp
Wire Wire Line
	7040 5170 7040 4820
$Comp
L Device:R_Small_US R17
U 1 1 60FD9BB8
P 6890 5320
F 0 "R17" V 6990 5270 50  0000 C CNN
F 1 "10k" V 7090 5270 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6890 5320 50  0001 C CNN
F 3 "~" H 6890 5320 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700" H 6890 5320 50  0001 C CNN "DigiKey"
	1    6890 5320
	0    1    1    0   
$EndComp
Wire Wire Line
	6990 5320 7040 5320
Wire Wire Line
	7040 5320 7040 5170
Connection ~ 7040 5170
$Comp
L Device:C C9
U 1 1 60FDF520
P 7340 5170
F 0 "C9" H 7455 5216 50  0000 L CNN
F 1 "0.1uF" H 7455 5125 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7378 5020 50  0001 C CNN
F 3 "" H 7340 5170 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/kemet/C0603C104J4RACTU/411096" H 7340 5170 50  0001 C CNN "DigiKey"
	1    7340 5170
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0157
U 1 1 60FDFBA4
P 7340 4970
F 0 "#PWR0157" H 7340 4820 50  0001 C CNN
F 1 "+3.3V" H 7355 5143 50  0000 C CNN
F 2 "" H 7340 4970 50  0001 C CNN
F 3 "" H 7340 4970 50  0001 C CNN
	1    7340 4970
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0159
U 1 1 60FE02A0
P 7340 5370
F 0 "#PWR0159" H 7340 5120 50  0001 C CNN
F 1 "GND" H 7345 5197 50  0000 C CNN
F 2 "" H 7340 5370 50  0001 C CNN
F 3 "" H 7340 5370 50  0001 C CNN
	1    7340 5370
	1    0    0    -1  
$EndComp
Wire Wire Line
	7340 5370 7340 5320
Wire Wire Line
	7340 5020 7340 4970
Wire Notes Line
	6970 6540 3700 6540
Text Notes 3960 7290 0    118  ~ 0
Tri-State \nBuffer Power
Text Notes 1390 4360 0    79   ~ 0
Auto Flash on USB
Wire Notes Line
	3700 3900 11220 3900
Wire Notes Line
	7690 3900 7690 470 
Text Notes 5380 3720 0    118  ~ 0
TTL to RS232 Converter
$Comp
L Device:R_Small_US R16
U 1 1 610EEDF3
P 6890 5170
F 0 "R16" V 6730 5130 50  0000 C CNN
F 1 "0" V 6810 5150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6890 5170 50  0001 C CNN
F 3 "~" H 6890 5170 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/yageo/RC0603JR-070RL/726675" H 6890 5170 50  0001 C CNN "DigiKey"
	1    6890 5170
	0    1    1    0   
$EndComp
Wire Wire Line
	6990 5170 7040 5170
Text GLabel 5650 5570 0    50   Input ~ 0
LCD_DC
Wire Wire Line
	5650 5570 5840 5570
Text GLabel 2510 2050 2    50   Input ~ 0
LCD_DC
Wire Wire Line
	2510 2050 2400 2050
$Comp
L 2021-06-22_18-51-54:SN74LVC125ADBR_(Units) U7
U 3 1 6110E7F3
P 8975 5250
F 0 "U7" H 8975 5103 50  0000 C CNN
F 1 "SN74LVC125ADBR_(Units)" H 8975 5012 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 8975 5250 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/scas290q/scas290q.pdf" H 8975 5250 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/texas-instruments/SN74LVC125ADBR/377410" H 8975 5250 50  0001 C CNN "DigiKey"
	3    8975 5250
	-1   0    0    -1  
$EndComp
$Comp
L MiOrigin:3.5-TFT-LCD-SPI U4
U 2 1 6110FE25
P 10100 5150
F 0 "U4" H 10328 5196 50  0000 L CNN
F 1 "3.5-TFT-LCD-SPI" H 10328 5105 50  0000 L CNN
F 2 "MiOrigin:3.5-TFT-LCD-SPI" H 9600 5200 50  0001 C CNN
F 3 "~" H 9600 5200 50  0001 C CNN
	2    10100 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 4950 9850 4950
Text GLabel 2500 2150 2    50   Input ~ 0
TCH_CS
Text GLabel 9750 5050 0    50   Input ~ 0
TCH_CS
Wire Wire Line
	9750 5050 9850 5050
Text GLabel 8925 4800 0    50   Input ~ 0
TCH_CS
Wire Wire Line
	8925 4800 8975 4800
Wire Wire Line
	8975 4800 8975 4900
Wire Wire Line
	9250 5250 9850 5250
Text GLabel 9750 4950 0    50   Input ~ 0
HSPI_SCLK
Text GLabel 8625 5250 0    50   Input ~ 0
HSPI_MISO
Text GLabel 9750 5150 0    50   Input ~ 0
HSPI_MOSI
Wire Wire Line
	9750 5150 9850 5150
$Comp
L Transistor_BJT:PMBT3904YS Q1
U 1 1 61142565
P 1670 4730
F 0 "Q1" H 1861 4776 50  0000 L CNN
F 1 "PMBT3904YS" H 1861 4685 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 1870 4830 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMBT3904YS.pdf" H 1670 4730 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/nexperia-usa-inc/PMBT3904YS-115/2119855" H 1670 4730 50  0001 C CNN "DigiKey"
	1    1670 4730
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:PMBT3904YS Q1
U 2 1 6114611E
P 1670 5330
F 0 "Q1" H 1861 5284 50  0000 L CNN
F 1 "PMBT3904YS" H 1861 5375 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-363_SC-70-6" H 1870 5430 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMBT3904YS.pdf" H 1670 5330 50  0001 C CNN
F 4 "https://www.digikey.com/en/products/detail/nexperia-usa-inc/PMBT3904YS-115/2119855" H 1670 5330 50  0001 C CNN "DigiKey"
	2    1670 5330
	-1   0    0    1   
$EndComp
Wire Wire Line
	2500 2150 2400 2150
NoConn ~ 2400 3350
NoConn ~ 2400 3450
Text Notes 4100 4250 0    118  ~ 0
3.5" TFT LCD SPI Dispaly w/ Touch
Text Notes 9200 5900 0    79   ~ 0
Touch Pins
Text Notes 5150 6300 0    79   ~ 0
Display Pins
NoConn ~ 11030 2480
Text GLabel 9750 5350 0    50   Input ~ 0
TCH_INT
Wire Wire Line
	9750 5350 9850 5350
Text GLabel 2500 3150 2    50   Input ~ 0
TCH_INT
Wire Wire Line
	2400 3150 2500 3150
Text GLabel 9230 1780 0    50   Input ~ 0
HSPI_MOSI
Text GLabel 2500 3250 2    50   Input ~ 0
BAT_ALERT
Wire Wire Line
	2500 3250 2400 3250
Wire Wire Line
	1800 700  1800 750 
$Comp
L Connector:TestPoint TP1
U 1 1 60D803B6
P 1800 750
F 0 "TP1" V 1754 938 50  0000 L CNN
F 1 "MCU +3.3V Test Point" V 1845 938 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 2000 750 50  0001 C CNN
F 3 "~" H 2000 750 50  0001 C CNN
	1    1800 750 
	0    1    1    0   
$EndComp
Connection ~ 1800 750 
Wire Wire Line
	1800 750  1800 950 
$Comp
L Connector:TestPoint TP2
U 1 1 60D81AC1
P 1800 3900
F 0 "TP2" V 1754 4088 50  0000 L CNN
F 1 "MCU GND Test Point" V 1845 4088 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 2000 3900 50  0001 C CNN
F 3 "~" H 2000 3900 50  0001 C CNN
	1    1800 3900
	0    1    1    0   
$EndComp
Connection ~ 1800 3900
Wire Wire Line
	1800 3900 1800 3920
NoConn ~ 7100 2180
NoConn ~ 7100 2380
NoConn ~ 7100 2280
NoConn ~ 7100 2580
NoConn ~ 7100 2880
NoConn ~ 7100 2780
Wire Wire Line
	8625 5250 8700 5250
$Comp
L SparkFun-Jumpers:JUMPER-SMT_3_1-NC JP1
U 1 1 60E9058A
P 4400 2080
F 0 "JP1" H 4503 2038 45  0000 L CNN
F 1 "JUMPER-SMT_3" H 4503 2122 45  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 4400 2330 20  0001 C CNN
F 3 "" V 4400 2025 60  0001 C CNN
F 4 "XXX-00000" H 4503 2164 60  0001 L CNN "PROD_ID"
	1    4400 2080
	-1   0    0    1   
$EndComp
$Comp
L SparkFun-Jumpers:JUMPER-SMT_3_1-NC JP2
U 1 1 60E96F66
P 4400 3430
F 0 "JP2" H 4503 3388 45  0000 L CNN
F 1 "JUMPER-SMT_3" H 4503 3472 45  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 4400 3680 20  0001 C CNN
F 3 "" V 4400 3375 60  0001 C CNN
F 4 "XXX-00000" H 4504 3514 60  0001 L CNN "PROD_ID"
	1    4400 3430
	-1   0    0    1   
$EndComp
$EndSCHEMATC
