#include <mbed.h>
Serial pc(USBTX,USBRX);
//Serial bt(D1,D0);
DigitalIn button1A(D2);
DigitalOut led(LED1);
int main() {
  //uint8_t ch=0;
  //pc.baud(38400);
  pc.baud(38400);
  //pc.printf("%s\n",a);

  while(1) {
    
       /* if(bt.readable())
        {
            ch=bt.getc();
            pc.printf("I hear you B1 : %c\n",ch);
            //bt.printf("%c",ch);
        }*/
        
            //ch=pc.getc();
            pc.printf("%d",button1A.read());
            led = button1A.read();
            wait(0.1);
  }
}
