// Arduino program to read data from Cypress CMOS Static RAM 48-pin BGA chip
// Written by Molly Shapiro for MedBreach Capstone

// Reading from CMOS chip: 
// Set Chip Enable (CE) and Write Enable (WE) HIGH, then Byte Low Enable (BLE) LOW
// to read data from memory locations specified on Address (A) pins from IO0

// Identify constant pins that will be set either high or low
const int BLE = 53;
const int CE = 47; 
const int WE = 43;

// Identify address pins
const int A = 49;

// Identify I/O pins
const int IO0 = 45;

// Set pins as input or output and set constant pins to non-write levels
void setup() {
  // set constant pins
  pinMode(CE, OUTPUT);
  pinMode(WE, OUTPUT);
  pinMode(BLE, OUTPUT);

  // Set address pins
  pinMode(A, OUTPUT);

  // Set IO pins
  pinMode(IO0, INPUT);

  // Set constant pins to pre-read
  digitalWrite(CE, HIGH);
  digitalWrite(WE, LOW);
  digitalWrite(BLE, HIGH);
}

void loop() {
  // Set constant pins to read state
  digitalWrite(CE, LOW);
  digitalWrite(WE, HIGH);
  digitalWrite(BLE, LOW);

for (int i = 0x00; i <= 0x10000000000; i ++) {
  send_address(i);
}
  digitalRead(IO0);
  digitalWrite(CE, HIGH);
  digitalWrite(WE, LOW);
  digitalWrite(BLE, HIGH);
}

void send_address(byte data) {
  for (int i = 7; i >= 0; i --) {
    digitalWrite(A, (data >> i) & 0x01);
  }
}
