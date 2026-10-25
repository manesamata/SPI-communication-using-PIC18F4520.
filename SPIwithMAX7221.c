#include<p18f4520.h>

void spi_init(void);
void spi_trans(unsigned char);
void display(unsigned char,unsigned char);

void main()
{
spi_init();
display(0X01,0X6D);
while(1);
}
void spi_init(void)
{
TRISC=0X10;
SSPCON1=0X20;
SSPSTAT=0X80;
display(0X0B,0X00);
display(0X09,0X00);
display(0X0A,0XFF);
display(0X0C,0X01);
display(0X0F,0X00);
}
void display(unsigned char address,unsigned char data)
{
PORTCbits.RC2=0;
spi_trans(address);
spi_trans(data);
PORTCbits.RC2=1;
}
void spi_trans(unsigned char x)
{
PIR1bits.SSPIF=0;
SSPBUF=x;
while(PIR1bits.SSPIF=0);
PIR1bits.SSPIF=0;
}

