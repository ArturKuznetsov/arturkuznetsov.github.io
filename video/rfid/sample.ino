#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define dver 4

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
 int Key;
  int KeyTemp;
void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  pinMode(dver, OUTPUT);

  
}

void loop() {
    if (mfrc522.PICC_IsNewCardPresent()) {// Поиск нового ключа
  if (mfrc522.PICC_ReadCardSerial()) {
  // put your main code here, to run repeatedly:
 
for (byte i = 0; i < mfrc522.uid.size; i++){
KeyTemp = mfrc522.uid.uidByte[i];
    Key = Key * 256 + KeyTemp;}
   
if (Key == 8665) {
  
  Serial.println("Yes");
  digitalWrite(dver, HIGH);
  delay(2000);
  digitalWrite(dver, LOW);
}
else{
  Serial.println("No!!");
}
} }
}
