
obj-m += exec_driver.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	- sudo rmmod exec_driver.ko
	sudo insmod exec_driver.ko
	sudo chmod 666 /dev/query
