#include <mbed.h>
 

Serial pc(USBTX,USBRX);
Serial mp3(D8,D2);
void playMusicSD(int Music,int WWW);
void NextSong();
void StopSong(int WA);
void Upvolume();
uint8_t input;
int main() {
 

    while(1) {

    if(pc.readable()){
        input = pc.getc();
    }
    pc.printf("%c",input);

    switch(input){
        case '1':
        playMusicSD(4,30);
        break;
    
        case '2':
        Upvolume();
        break;
    }
    
    //StopSong(1);
    //playMusicSD(2,2);
    //StopSong(1);
  
    
    }
    }

 
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
 
void Upvolume(){
     mp3.putc(0x7e);
     mp3.putc(0xff);
     mp3.putc(0x06);
     mp3.putc(0x04);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0x00);
     mp3.putc(0xef);

     pc.printf("Up\n");
}