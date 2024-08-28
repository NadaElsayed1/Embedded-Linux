#!/bin/sh

HOST="192.168.1.2"  # Replace with your host machine IP
GPIO_PIN=18  # Replace with the GPIO pin number connected to the LED

# Export GPIO pin and set direction to output
echo "$GPIO_PIN" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio$GPIO_PIN/direction

# Ping the host
ping -c 1 $HOST > /dev/null 2>&1

if [ $? -eq 0 ]; then
    # Ping successful, turn off LED
    echo "0" > /sys/class/gpio/gpio$GPIO_PIN/value
else
    # Ping failed, turn on LED
    echo "1" > /sys/class/gpio/gpio$GPIO_PIN/value
fi

# Unexport the GPIO pin
echo "$GPIO_PIN" > /sys/class/gpio/unexport
