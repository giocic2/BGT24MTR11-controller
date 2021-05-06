# BGT24MTR11-controller
Controlling BGT24MTR11 with RaspberryPi and Python script.
## Configure your Raspberry Pi from terminal
### 1. Enable SPI interface
1. From Raspberry Pi terminal:
```
sudo raspi-config
```
2. Select "Interface options" and enable SPI interface.
3. Load kernel module:
```
sudo modprobe spi-2835
```
4. Install _spidev_ Python module:
```
sudo apt install python/dev python3/dev
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

### 2. Clone this repository
From terminal:
```
git clone https://github.com/giocic2/BGT24MTR11-controller.git
```
### 3. Execute the script
```
./BGT24MTR11_controller/Raspberry/BGT24MTR11_controller.py
```
### 4. (Optional) Update repository discarding local changes
```
git reset --hard
git pull
```