/*
MFRC522 RFID Module
==================

Pin  Wiring to Arduino Uno
SDA     Digital 10
SCK     Digital 13
MOSI   Digital 11
MISO   Digital 12
IRQ      unconnected
GND    GND
RST     Digital 9
3.3V    3.3V
*/

#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

void setup() {
    Serial.begin(9600);              //  Initialize serial communications with the PC
    SPI.begin();                           //  Init SPI bus
    mfrc522.PCD_Init();             //  Init MFRC522 card
    Serial.println(F("Read personal data on a MIFARE PICC:"));    //shows in serial that it is ready to read
}

void loop() {
// Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
    byte block;
    byte len;

// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    
// Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    Serial.println(F("**Card Detected:**"));
    byte buffer1[18];
    block = 4;
    len = 18;
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Authentication failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    status = mfrc522.MIFARE_Read(block, buffer1, &len);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Reading failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    // here we take two bytes from buffer and assemble them into int
    //Serial.println(buffer1[0]);
    //Serial.println(buffer1[1]);
    int wert = buffer1[0] << 8 | buffer1[1];
    Serial.print("NFC-Wert: ");
    Serial.println(wert);
    Serial.println(F("**End Reading**\n"));
    //
    delay(1000);
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}
