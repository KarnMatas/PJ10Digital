#include <mbed.h>
Serial pc(USBTX,USBRX,38400);
Serial bt(PA_11,PA_12,38400);
DigitalIn buttonA(D2);
DigitalIn buttonB(D3);
DigitalIn buttonC(D4);
DigitalIn buttonD(D5);
AnalogIn X(A0);
AnalogIn Y(A1);
uint8_t ch ;
char  DirX,DirY;
int main() {
  while(1) {
      //////////////////// MASTER Joystick //////////////////////////////////
            pc.printf("%d %d %d %d  X =  %.1f   : Y =   %.1f \n",buttonA.read(),buttonD.read(),buttonC.read(),buttonB.read(),X.read(),Y.read());
			bt.printf("%d %d %d %d  X =  %.1f   : Y =   %.1f \n",buttonA.read(),buttonD.read(),buttonC.read(),buttonB.read(),X.read(),Y.read());	
            wait(0.1);
  }
  ///////////////////////////////////////////////////////////////////////////
}
