#!/usr/bin/python
# Code based on the sample https://www.takaitra.com/spi-device-raspberry-pi/

import spidev
import time

spi0 = spidev.SpiDev()
# Use of /dev/spidev0.0, SPI0 with CE0=HIGH
spi0.open(0,0)
spi0.max_speed_hz = 122000
# CPOL=0, CPHA=1
spi0.mode = 0b01

MSB = 0x00
# bit7: Active-low LNA Gain Reduction (OFF)
# bit6: Not Used
# bit5: Not Used
# bit4: TX power disable (OFF)
#       TX is controlled by active-low "TXOFF" pin of the IC.
# bit3: Analog multiplexer control bit "AMUX2" (0)
# bit2: Test bit, must be LOW (0)
# bit1: Test bit, must be lOW (0)
# bit0: Analog multiplexer control bit "AMUX1" (0)

LSB = 0x08
# bit7: Analog multiplexer control bit "AMUX0" (0)
# bit6: Active-low 64k divider (ON)
# bit5: Active-low 16 divider (ON)
# bit4: Active-low LO buffer output power in high mode (ON)
# bit3: Active-low TX buffer output power in high mode (ON)
# bit2: TW power reduction bit2
# bit1: TW power reduction bit1
# bit0: TW power reduction bit0
# TW output power reduction factors: 0, 0.4, 0.8, 1.4, 2.5, 4, 6, 9

spi0.xfer([MSB,LSB])
spi0.close()
