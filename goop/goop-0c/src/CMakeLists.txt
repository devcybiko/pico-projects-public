add_executable(${NAME}
        main.c
        GObj.c
        Gpio.c
        GpioInput.c
        GpioOutput.c
        LedBlink.c
        LedPwm.c
        XButton.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(${NAME} pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 1)
pico_enable_stdio_uart(${NAME} 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

target_compile_options(${NAME} PRIVATE
    -Wno-incompatible-pointer-types
)