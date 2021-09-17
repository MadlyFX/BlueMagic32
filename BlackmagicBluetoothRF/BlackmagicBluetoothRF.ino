#include <BlueMagic32.h>

char *parsedValues[10];

void setup()
{

  Serial.begin(115200);
  pinMode(2, OUTPUT);
  //BMDConnection.begin("Reality Field");
  //BMDConnection.clearPairing();
  //BMDConnection.scan(false, 5);
  //BMDControl = BMDConnection.connect();


}

void loop()
{

  while (Serial.available()) {
    String buffer1 = Serial.readString();
    parseSerial(buffer1);
    String strPar = parsedValues[0];
    if (strPar == "bm") { //Valid command
      String strPar2 = parsedValues[1];//Starts BLE and reports status
      if (strPar2.indexOf("begin") + 1) {
        BMDConnection.begin("Reality Field");
      }
      if (strPar2.indexOf("scan") + 1) {//Scans BLE and reports blackmagic devices and their index
        BMDConnection.scan(true, 5);
      }
      if (strPar2.indexOf("connect") + 1) {//Connects to device at index
        String strPar3 = parsedValues[2];
        BMDControl = BMDConnection.connect(strPar3.toInt());
        digitalWrite(2, LOW);
      }
      if (strPar2.indexOf("clear") + 1) {//Clears pairing
        digitalWrite(2, HIGH);
        Serial.println("Clearing");
        BMDConnection.clearPairing();

      }
    }
  }

  if (BMDConnection.available()) {
    if (BMDControl->wbchanged()) {
      Serial.print("bm,whitebalance,");
      Serial.println(BMDControl->getWhiteBalance());
    }
    if (BMDControl->tintchanged()) {
      Serial.print("bm,tint,");
      Serial.println(BMDControl->getTint());
    }
    if (BMDControl->isochanged()) {
      Serial.print("bm,iso,");
      Serial.println(BMDControl->getIso());
    }
    if (BMDControl->shutterchanged()) {
      Serial.print("bm,shutter,");
      Serial.println(BMDControl->getShutter());
    }
    if (BMDControl->zoomchanged()) {
      Serial.print("bm,zoom,");
      Serial.println(BMDControl->getZoom());
    }
    if (BMDControl->focuschanged()) {
      Serial.print("bm,focus,");
      Serial.println(BMDControl->getFocus());
    }
    if (BMDControl->aperturechanged()) {
      Serial.print("bm,aperture,");
      Serial.println(BMDControl->getAperture());
    }
  }



}


void parseSerial(String serialData) {
  char buffer[64];
  int i = 0;
  strcpy(buffer, serialData.c_str());

  char* stringPtr;
  stringPtr = strtok(buffer, ",");
  while (stringPtr != NULL)
  {

    parsedValues[i] = stringPtr;
    stringPtr = strtok(NULL, ",");
    i++;
  }
}
