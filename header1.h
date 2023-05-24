#define DELAY 2000
#define ON 0x01
#define OFF 0x00
//Input Pushbuttons
#define PB1      (1U<<10)      //pin 16 offset 
#define PB2      (1U<<11)      //pin 17 offset
#define PB3      (1U<<12)      //pin 18 offset
#define OPEN_PB  (1U<<13)      //pin 19 offset
#define CLOSE_PB (1U<<2)       //pin 10 offset        
#define MOVE_PB  (1U<<1)       //pin 9 offset
// Output LEDs
#define F1       (1U<<18)       //pin 2 offset
#define F2       (1U<<19)       //pin 3 offset    
#define F3       (1U<<20)       //pin 4 offset
#define OPEN_L   (1U<<21)       //pin 5 offset 
#define CLOSE_L  (1U<<22)       //pin 6 offset
#define MOVE_L   (1U<<23)       //pin 7 offset

void setupGPIO();
int setLED(int color, int state);
void delay(int milliseconds);
int checkBot(int button); 