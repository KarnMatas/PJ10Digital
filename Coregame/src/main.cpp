#include <mbed.h>
// ############################# Fighter Rumble!! #######################################
Serial pc(USBTX,USBRX);
Serial NUBT(D8,D2);
//Serial mp3(กรอก);

DigitalOut light(LED1);
//AnalogIn joy();
// Create Function mp3.//
void playMusicSD(int Music,int WWW);
void NextSong();
void StopSong(int WA);


int main() 
{
  uint8_t game_state=0;
  char inputBT[32];
  char Select_Char[10];
  pc.baud(38400);
  bt.baud(38400);
  pc.printf("Fighter Rumble!!\n\n");


  while(1) {

  if (NUBT.readable())
    {
      inputBT = NUBT.gets(inputBT,32);
      pc.printf("%s\n",inputBT);
    }
    
  switch (game_state)
  {
  case 0:
    /*-opening sound +mp3
      -goto game_state = 1 */
    pc.printf("Game Start! state 0\n");
    game_state = 1 ;
    break;
  case 1:
    /*-Choose Character +joy
      -sound it +mp3
      -light of the character +led
      -communicate 2 nucleo  to tell player already selected
      -if you choose Kangaroo goto game_state=3
      -if you choose Kangaroo goto game_state=4
      - and set the character */
    pc.printf("state 1 : Select\n");
    game_state = 2 ;
    break;
   case 2:
    /*-Ready fight! +mp3
      -goto game_state = 3 */
    pc.printf("state 2 : Ready\n");
    game_state = 3 ;
    break;
    case 3:
    /*-player can control character + joy
      -interface with HPandSP(LED)
      -timer
      -analyse amount of HP SP and Time +Led
      -sounds when a player is hit   +mp3
      -goto game_state = 4 */
    pc.printf("state 3 : Fight!\n");
    //game_state = 4 ;
    break;
    case 4:
    /*-sounds Time out
      -say the winner name
      -return to game_state 0 and wait for next player*/
    pc.printf("state 4 : Winner\n");
    game_state = 0 ;
    break;

  default:
    break;
  }
  }


  // Function mp3//
  void playMusicSD(int Music,int WWW)
{
     mp3.putc(0x7e);
     mp3.putc(0xff);
     mp3.putc(0x06);
     mp3.putc(0x03);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(Music);
     mp3.putc(0xef);
     wait(WWW);
     pc.printf(" List:%d\n",Music);
     
}
void NextSong(){
     mp3.putc(0x7e);
     mp3.putc(0xff);
     mp3.putc(0x06);
     mp3.putc(0x01);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0xef);

     pc.printf("NextSong\n");
}
void StopSong(int WA)
{
    mp3.putc(0x7e);
     mp3.putc(0xff);
     mp3.putc(0x06);
     mp3.putc(0x16);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0xef);
     wait(WA);
     pc.printf("StopSong\n");
     
}
 
}