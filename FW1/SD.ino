void SD_init() {
  if (SD.begin(SD_ss)) {
    SD_isOk = true;
  } else {
    SD_isOk = false;
  }
  delay(20);
}

void SD_log() {
  if (SD_isOk) {
    File dataFile = SD.open(SD_fn_log, FILE_WRITE);
    if (dataFile) {
      dataFile.println("name;Bob;");
      dataFile.close();
      SD_isWriteLog = true;
      SYS_countLogging++;
    } else {
      SD_isWriteLog = false;
    }
  }
}


