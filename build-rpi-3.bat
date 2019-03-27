@ECHO OFF

arm-none-eabi-g++ -O0 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a53 -nostartfiles -g -Wl,-T,rpi.x test.cpp armc-09-cstartup.cpp armc-09-start.S cpp_core.cpp -o kernel.elf
arm-none-eabi-objcopy kernel.elf -O binary kernel7.img
