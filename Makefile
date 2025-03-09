all: 
	cd micropython && make -C mpy-cross
	cd micropython/ports/stm32 && make BOARD=NUCLEO_H743ZI2 submodules
	cd micropython/ports/stm32 && make V=1 BOARD=NUCLEO_H743ZI2 USER_C_MODULES=../../../modules

init:
	git submodule init
	git submodule update


flash:
	st-flash --connect-under-reset --format ihex write micropython/ports/stm32/build-NUCLEO_H743ZI2/firmware.hex