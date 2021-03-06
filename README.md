# Chico servo #

The project was designed based on the MCU PIC16LF1824. It's intent is to control the ChicoServo board( [link to PCBs repo](https://bitbucket.org/jpnbino/hw_palha_servo/src/master/) ) so that two palhaservo boards can communicate with each other. One board is going to perform master role while the other will perform the slave role. The master is going to read a rotary potentiometer attached to the board and then translate its position into a servomotor position attached to the slave board.

![System overview](https://i.imgur.com/gyzdevEl.png)

### Important Note###
As there are many different seril bluetooth modules in the market such as HC-05, HC-06, Hm-10 and so on ... I didn't implemented code for connecting them automatically. So, in order to have the firmware properly working, you have to configure the master bluetooth module to automatically connect to a slave module, this can be achieved through a serial terminal on a PC and a USB-to-UART converter or and arduino. 

The role of the board is defined in hardware, whether master or slave.

### Firmware Funcionality###
* Drives a low battery warn LED;
* Manages a Li-ion battery ( 3.7V );
* PWM control;
* Serial UART Communication (9600baud)
* Rotary potentiometer read;

### How do I get set up? ###

* Install [MPLAB X IDE](http://www.microchip.com/mplab/mplab-x-ide) v4.15 or greater
* Have a programmer like [PicKit3](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=PG164130)
* Download [compiler XC8](http://www.microchip.com/mplab/compilers)


### Who do I talk to? ###

* Any questions? Just give me a call [jpnogg@gmail.com]()

### Version ###

* No version released yet
