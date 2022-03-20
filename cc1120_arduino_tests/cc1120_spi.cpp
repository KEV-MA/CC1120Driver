#include "cc1120_spi.h"
#include "cc1120_regs.h"
#include "cc1120_arduino_tests.h"

/**
 * @brief - Reads from consecutive registers from the CC1120.
 * 
 * @param addr - The address of the first register to read.
 * @param data - The array to store the read data, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to read.
 * @return true - If the read was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_read_spi(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if (addr >= CC1120_REGS_EXT_ADDR) {
        Serial.println("Not a valid register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }

    if (status) {
        uint8_t header = (len > 1) ? R_BIT | BURST_BIT | addr : R_BIT | addr;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        uint8_t i;
        for(i = 0; i < len; i++) {
            data[i] = SPI.transfer(0x00);
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Reads from consecutive extended address space registers on the CC1120
 * 
 * @param addr - The address of the first register to read.
 * @param data - The array to store the read data, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to read.
 * @return true - If the read was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_read_ext_addr_spi(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if (addr > CC1120_REGS_EXT_PA_CFG3 && addr < CC1120_REGS_EXT_WOR_TIME1 ||
        addr > CC1120_REGS_EXT_XOSC_TEST0 && addr < CC1120_REGS_EXT_RXFIRST ||
        addr > CC1120_REGS_EXT_FIFO_NUM_RXBYTES) {
        Serial.println("Not a valid register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }
    

    if (status) {
        uint8_t header = (len > 1) ? R_BIT | BURST_BIT | CC1120_REGS_EXT_ADDR :
                                     R_BIT | CC1120_REGS_EXT_ADDR;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        SPI.transfer(addr);
        uint8_t i;
        for(i = 0; i < len; i++) {
            data[i] = SPI.transfer(0xFF);
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Writes to consecutive registers on the CC1120.
 * 
 * @param addr - The address of the first register to write to.
 * @param data - The array of data to write to the registers, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to write.
 * @return true - If the write was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_write_spi(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if(addr >= CC1120_REGS_EXT_ADDR) {
        Serial.println("Not a valid register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }

    if (status) {
        uint8_t header = (len > 1) ? BURST_BIT | addr : addr;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        uint8_t i;
        for(i = 0; i < len; i++) {
            if (!send_byte_receive_status(data[i])) {
                status = false;
            }
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Writes to consecutive extended address space registers on the CC1120.
 * 
 * @param addr - The address of the first register to write to.
 * @param data - The array of data to write to the registers, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to write.
 * @return true - If the write was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_write_ext_addr_spi(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if (addr > CC1120_REGS_EXT_PA_CFG3 && addr < CC1120_REGS_EXT_WOR_TIME1 ||
        addr > CC1120_REGS_EXT_XOSC_TEST0 && addr < CC1120_REGS_EXT_RXFIRST ||
        addr > CC1120_REGS_EXT_FIFO_NUM_RXBYTES) {
        Serial.println("Not a valid register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }
    
    if (status) {
        uint8_t header = (len > 1) ? BURST_BIT | CC1120_REGS_EXT_ADDR : CC1120_REGS_EXT_ADDR;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        if (SPI.transfer(addr) != 0x00) {
            Serial.println("CC1120 write ext addr failed");
            status = false;
        }
    }
    
    if (status) {
        uint8_t i;
        for(i = 0; i < len; i++) {
            if (!send_byte_receive_status(data[i])) {
                status = false;
            }
        }
    }
    
    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief Calls a strobe command on the CC1120.
 * 
 * @param addr - The address of the strobe command.
 * @return true - If the strobe command was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_strobe_spi(uint8_t addr) {
    bool status = true;

    if (addr < CC1120_STROBE_SRES || addr > CC1120_STROBE_SNOP) {
        Serial.println("Not a strobe register!");
        status = false;
    }

    if (status) {
        digitalWrite(CS, LOW);    
        if (!send_byte_receive_status(addr)) {
            status = false;
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Reads consecutive registers from the FIFO memory.
 * 
 * @param data - The array to store the read data, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to read.
 * @return true - If the read was successful.
 * @return false - If the status byte is invalid.
 */
bool cc1120_read_fifo(uint8_t data[], uint8_t len) {
    bool status = true;

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }

    if (status) {
        uint8_t header = (len > 1) ? R_BIT | BURST_BIT | CC1120_REGS_FIFO_ACCESS_STD :
                                    R_BIT | CC1120_REGS_FIFO_ACCESS_STD;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        uint8_t i = 0;
        for(i = 0; i < len; i++) {
            data[i] = SPI.transfer(0xFF);
        }
    }
    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Writes consecutive registers to the FIFO memory.
 * 
 * @param data - The array of data to write to the registers, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to write.
 * @return true - If the write was successful.
 * @return false - If the status byte is invalid.
 */
bool cc1120_write_fifo(uint8_t data[], uint8_t len) {
    bool status = true;

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }

    if (status) {
        uint8_t header = (len > 1) ? BURST_BIT | CC1120_REGS_FIFO_ACCESS_STD :
                                    CC1120_REGS_FIFO_ACCESS_STD;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            digitalWrite(CS, HIGH);
            status = false;
        }
    }

    if (status) {
        uint8_t i = 0;
        for(i = 0; i < len; i++) {
            SPI.transfer(data[i]);
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Reads consecutive registers directly from the FIFO on the CC1120.
 * 
 * @param addr - The address of the first register to read. Range 0x00 - 0xFF.
 * @param data - The array to store the read data, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to read.
 * @return true - If the read was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_read_fifo_direct(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if (addr < CC1120_FIFO_TX_START || addr > CC1120_FIFO_RX_END) {
        Serial.println("Not a valid FIFO register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }

    if (status) {
        uint8_t header = (len > 1) ? R_BIT | BURST_BIT | CC1120_REGS_FIFO_ACCESS_DIR :
                                    R_BIT | CC1120_REGS_FIFO_ACCESS_DIR;

        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            digitalWrite(CS, HIGH);
            status = false;
        }
    }

    if (status) {
        SPI.transfer(addr);
        uint8_t i = 0;
        for(i = 0; i < len; i++) {
            data[i] = SPI.transfer(0xff);
        }
    }

    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Writes consecutive registers directly to the FIFO on the CC1120.
 * 
 * @param addr - The address of the first register to write to. Range 0x00 - 0xFF.
 * @param data - The array of data to write to the registers, or a pointer to a single uint8_t if len=1.
 * @param len - The number of registers to write.
 * @return true - If the write was successful.
 * @return false - If the register is not valid, or the status byte is invalid.
 */
bool cc1120_write_fifo_direct(uint8_t addr, uint8_t data[], uint8_t len) {
    bool status = true;

    if (addr < CC1120_FIFO_TX_START || addr > CC1120_FIFO_RX_END) {
        Serial.println("Not a valid FIFO register!");
        status = false;
    }

    if (len < 1) {
        Serial.println("Not a valid length!");
        status = false;
    }
    
    if (status) {
        uint8_t header = (len > 1) ? BURST_BIT | CC1120_REGS_FIFO_ACCESS_DIR :
                                    CC1120_REGS_FIFO_ACCESS_DIR;


        digitalWrite(CS, LOW);
        if (!send_byte_receive_status(header)) {
            status = false;
        }
    }

    if (status) {
        SPI.transfer(addr);
        uint8_t i = 0;
        for(i = 0; i < len; i++) {
            SPI.transfer(data[i]);
        }
    }
    digitalWrite(CS, HIGH);
    return status;
}

/**
 * @brief - Reads the status register on the CC1120 and consecutively sends a byte over SPI.
 * 
 * @param data - The data to send to the status register.
 * @return true - If the status byte is valid.
 * @return false - If the status byte is invalid.
 */
bool send_byte_receive_status(uint8_t data) {
    bool status = false;
    union cc_st ccstatus;

    uint8_t i;
    for (i = 1; i <= 5; i++) {
        ccstatus.data = SPI.transfer(data);
        if (ccstatus.ccst.chip_ready == 1) {
            Serial.print("CC1120 chip not ready. Retrying... (");
            Serial.print(i);
            Serial.println("/5)");
        } else {
            status = true;
            break;
        }
    }

    return status;
}
