import subprocess
import os


def run_command(command, cwd=None):
    result = subprocess.run(command, shell=True, cwd=cwd, check=True)
    return result


def build():
    run_command("make -C mpy-cross", cwd="micropython")
    run_command("make BOARD=NUCLEO_H743ZI2 submodules", cwd="micropython/ports/stm32")
    run_command(
        "make BOARD=NUCLEO_H743ZI2 USER_C_MODULES=../../../modules",
        cwd="micropython/ports/stm32",
    )


def init():
    run_command("git submodule init")
    run_command("git submodule update")
    with open("./micropython/ports/stm32/Makefile", "r") as fr:
        content = fr.read()
        content = content.replace("-Werror", "")
        content = content.replace("hal_uart.c", "hal_uart.c\\\n    hal_uart_ex.c")
        with open("./micropython/ports/stm32/Makefile", "w") as fw:
            fw.write(content)

    str_to_replace = """#if defined(UART4)
void UART4_IRQHandler(void) {
    IRQ_ENTER(UART4_IRQn);
    uart_irq_handler(4);
    IRQ_EXIT(UART4_IRQn);
}
#endif
"""
    with open("./micropython/ports/stm32/stm32_it.c", "r") as fr:
        content = fr.read()
        content = content.replace(str_to_replace, "")
        with open("./micropython/ports/stm32/stm32_it.c", "w") as fw:
            fw.write(content)


def flash():
    run_command(
        "st-flash --connect-under-reset --format ihex write micropython/ports/stm32/build-NUCLEO_H743ZI2/firmware.hex"
    )


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="Micropython build and flash automation script"
    )
    parser.add_argument(
        "command", choices=["build", "init", "flash"], help="Command to run"
    )
    args = parser.parse_args()

    if args.command == "build":
        build()
    elif args.command == "init":
        init()
    elif args.command == "flash":
        flash()


if __name__ == "__main__":
    main()
