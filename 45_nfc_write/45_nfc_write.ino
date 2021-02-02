/*
MFRC522 RFID Module
==================
Pin  Wiring to Arduino Uno

SDA       Digital 10
SCK       Digital 13
MOSI     Digital 11
MISO     Digital 12
IRQ        unconnected
GND      GND
RST       Digital 9
3.3V      3.3V
*/
#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;

// Create empty byte buffer
byte buffr[] = {0xFF,0xFF,0xFF,0xFF,
                        0xFF,0xFF,0xFF,0xFF,
                        0xFF,0xFF,0xFF,0xFF,
                        0xFF,0xFF,0xFF,0xFF};

void setup() {
    Serial.begin(9600);        // Initialize serial communications with the PC
    SPI.begin();                    // Init SPI bus
    mfrc522.PCD_Init();      // Init MFRC522 card
    Serial.println(F("Write personal data on a MIFARE PICC "));
}

void loop() {
    // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
    for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
    
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
        return;
}

    if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
 }
 
    Serial.setTimeout(20000L);

    // Prepare data and write data to block
    int wert = 12345;
    buffr[0] = highByte(wert);
    buffr[1] = lowByte(wert);
    byte block = 4;
    writeBytesToBlock(block, buffr);  

    Serial.println(" ");
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
}

void writeBytesToBlock(byte block, byte buff[]) {
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else Serial.println(F("PCD_Authenticate() success: "));
    // Write block
    status = mfrc522.MIFARE_Write(block, buff, 16);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Write() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else Serial.println(F("MIFARE_Write() success: "));
}
