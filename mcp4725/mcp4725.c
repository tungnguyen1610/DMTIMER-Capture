#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define MCP4725_ADDR 0x60
#define I2C_SLAVE 0x0703
void write_DAC (int fd,uint16_t value)
{
    uint8_t data[3];
    buff[0]=0x60; //register address 0x60
    buff[1]=(value >> 8) &0x0F;
    buff[2]=(value & 0x0F);
    if (write(file, buf, 3) != 3) {
    /* ERROR HANDLING: i2c transaction failed */
    perror("Failed to write to the i2c bus");
        exit(1);
     }

    /* Using I2C Read, equivalent of i2c_smbus_read_byte(file) */
    if (read(file, buf, 1) != 1) {
    /* ERROR HANDLING: i2c transaction failed */
    } else {
    /* buf[0] contains the read byte */
    }
}
int main()
{
     const char *i2c_device = "/dev/i2c-1";
    int fd;
    if ((fd = open(i2c_device, O_RDWR)) < 0) {
        perror("Failed to open the i2c bus");
        exit(1);
    }
    if (ioctl(fd, I2C_SLAVE, MCP4725_ADDR) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        exit(1);
    }
    for (int i=0;i<10;i++)
    {
        write_DAC(fd,4095);
    }
    close(fd);
    return 0;
}