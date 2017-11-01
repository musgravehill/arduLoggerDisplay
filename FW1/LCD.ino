void LCD_init() {
  myGLCD.InitLCD();
  delay(20);
}

void LCD_SD_state() {
  myGLCD.setFont(SmallFont);
  if (SD_isOk) {
    myGLCD.print("SDOK", 0, 0);
  } else {
    myGLCD.print("SDFAIL", 0, 0);
  }
  if (SD_isWriteLog) {
    myGLCD.print("LOGOK", 42, 0);
  } else {
    myGLCD.print("LOGFAIL", 42, 0);
  }
  
  myGLCD.setFont(MediumNumbers);
  myGLCD.printNumI(SYS_countLogging, 0 , 9);
}
