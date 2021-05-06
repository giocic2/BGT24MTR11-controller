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

### 2. Clone this repository and make the controller software executable
From terminal:
```
git clone https://github.com/giocic2/BGT24MTR11-controller.git
```
```
cd BGT24MTR11-controller/Raspberry
```
```
chmod +x BGT24MTR11_controller.py
```
### 3. Execute the script
```
sudo ./BGT24MTR11_controller.py
```
### 4. Sync with future updates of this repository
If first time, make the update script executable:
```
chmod +x update_BGT24MTR11repository.sh
```
Execute the shell script. It discards all local changes, pulls the code from GitHub, and make the Python script executable.
```
./update_BGT24MTR11repository.sh
```