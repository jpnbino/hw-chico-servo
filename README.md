# PALHASERVO #

The project was designed based on the MCU PIC16LF1824. Its intent is to control the ChicoServo board( [link to PCBs repo](https://bitbucket.org/jpnbino/hw_palha_servo/src/master/) ) so that two palhaservo boards can communicate with each other. One board is going to perform master role while the other will perform the slave role. The master is going to read a rotary potentiometer attached to the board and then translate its position into a servomotor position attached to the slave board.

![System overview](https://lh3.googleusercontent.com/-jT2j34XCdvs/W6qo9w_tO_I/AAAAAAAAHq8/VbPxKEYenjMH2JVU4tIfljCSoPwHgT1_QCL0BGAs/w530-d-h331-n-rw/c67a32fa-b86f-4673-8a85-4f221cb39394.png)

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