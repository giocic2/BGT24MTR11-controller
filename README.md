# BGT24MTR11-controller
Controlling BGT24MTR11 with RaspberryPi and Python script.
## Configure your Raspberry Pi from terminal
### 1. Enable SPI interface
1. From Raspberry Pi terminal:
```
sudo raspi-config
```
2. Select "Interface options" and enable SPI interface.
3. Load kernel module from terminal>
```
sudo modprobe spi-2835
```
4. Install _spidev_ Python module:
```
sudo apt isntall python/dev python3/dev
```
```
cd ~
```
```
git clone https://github.com/doceme/py-spidev.git
```
```
cd py-spidev
```
```
make
```
```
sudo make install
```

### 2. Clone this repository and make the controller software executable
From terminal:
```
git clone https://github.com/giocic2/BGT24MTR11/controller.github
```
```
cd BGT24MTR11-controller/
```
```
chmod +x BGT24MTR11_controller.py
```

To execute:
```
sudo ./BGT24MTR11_controller.py
```
