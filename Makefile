#############################################################################
#
# Makefile for rf24hub and rf24gw 
#
# License: GPL (General Public License)
# Author:  Norbert Wilms 
# Date:    08.12.2019
# 
# Description:
# ------------
# use make all  
#
PREFIX=/usr/local
EXECDIR=${PREFIX}/bin
INCLUDEDIR=${PREFIX}/include
ARCH := $(shell uname -m)

ifeq "$(ARCH)" "armv6l"
        CCFLAGS=-Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -std=c++0x -pthread
        RF24FLAGS=-lrf24-bcm
endif

ifeq "$(ARCH)" "armv7l"
	CCFLAGS=-Ofast -mfpu=vfp -mfloat-abi=hard -march=armv7-a -mtune=arm1176jzf-s -std=c++0x -pthread
	RF24FLAGS=-lrf24-bcm
endif

ifeq "$(ARCH)" "x86_64"
	CCFLAGS=-Ofast -std=c++0x
endif

# make all
all: buffertest

# Make the rf24hub deamon
buffertest: buffer.o buffertest.cpp 
	g++ ${CCFLAGS} -Wall $^ -o $@

#rf24test: log.o zahlenformat.o rf24test.cpp
#	g++ ${CCFLAGS} ${RF24FLAGS} -Wall $^ -o $@

# clear build files
clean:
	rm *.o buffertest


