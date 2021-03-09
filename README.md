# Running the LED Matrix software

In order to run the software, the following hardware setup are required.

* Raspberry PI 4 ( Raspberry PI zero, only tested on Raspberry PI 4)
* Adafruit RGB Hat Bonnet
* 64x32 RGB LED matrix from Adafruit
* bcm2835 library, you can download it from https://www.airspayce.com/mikem/bcm2835/ and install in the raspberry pi using the instruction on the link.
* Connect all the hardwares needed as instructed in the Adafruit datasheet : https://cdn-learn.adafruit.com/downloads/pdf/adafruit-rgb-matrix-bonnet-for-raspberry-pi.pdf
* Compile the code and run using the commands
  ``` 
       gcc -Wall -pedantic -o matrix  ledmatrix.c  -l bcm2835 -l m
       ./matrix
```
