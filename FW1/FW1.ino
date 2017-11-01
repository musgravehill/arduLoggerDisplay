//TODO

//================================== pinout ================================================
/* FREE pins: d2, d3, d4, A0, A1, A2, A3, A4, A5, A6, A7
*/

//================================== LCD =====================================================
// LCD5110
//      SCK  -  5
//      MOSI - 6
//      DC   - 7
//      RST  -  9
//      CS   -   8
#include <LCD5110_Basic.h>
LCD5110 myGLCD(5, 6, 7, 9, 8);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
//extern uint8_t BigNumbers[];

//==================================== SD =====================================================
// SD card attached to SPI bus as follows:
// MOSI - pin 11
// MISO - pin 12
// CLK - pin 13
#include <SPI.h>
#include <SD.h>
#define SD_ss 10
#define SD_fn_log "log.txt"
bool SD_isOk = false;
bool SD_isWriteLog = false;

//=================================================== SYS =====================================
uint32_t SYS_countLogging = 0LL;

void setup() {
  delay(20);
  LCD_init();
  SD_init();
}

void loop() {
  SD_log();

  //myGLCD.disableSleep();
  myGLCD.clrScr();
  LCD_SD_state();
  delay(500);
  //myGLCD.enableSleep(); 
  delay(500);

}
