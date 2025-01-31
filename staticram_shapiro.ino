// Arduino program to read data from Cypress CMOS Static RAM 48-pin BGA chip
// Written by Molly Shapiro for MedBreach Capstone

// Reading from CMOS chip: 
// Set Chip Enable (CE) and Output Enable (OE) LOW and Write Enable (WE) HIGH, then Byte Low Enable (BLE) LOW
// to read data from memory locations specified on Address (A) pins from IO0 - IO7

// Identify constant pins that will be set either high or low
const int BLE = 7;
const int CE = 8;
const int OE = 9; 
const int CLK = 10;
const int WE = 11;

// Identify address pins
const int A0 = 12;

// Identify I/O pins
const int IO0 = 20;

// Define time delays
int delay_clock = 250;
int ending_delay = 10;

// Set pins as input or output and set constant pins to non-write levels
void setup() {
  // set constant pins
  pinMode(CE, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(WE, OUTPUT);

  // Set address pins
  pinMode(A0, OUTPUT);

  // Set IO pins
  pinMode(IO0, INPUT);

  // Set constant pins to pre-read
  digitalWrite(CE, HIGH);
  digitalWrite(OE, HIGH);
  digitalWrite(WE, LOW);
  digitalWrite(BLE, HIGH);
}

void loop() {
  // Set constant pins to read state
  digitalWrite(CE, LOW);
  digitalWrite(OE, LOW);
  digitalWrite(WE, HIGH);
  digitalWrite(BLE, LOW);

for (int i = 0; i <= 1; i ++) {
  send_address(0x01);
}

  digitalWrite(CE, HIGH);
  digitalWrite(OE, HIGH);
  digitalWrite(WE, LOW);

  delay(ending_delay);
}

// Clock function
void clock() {
  digitalWrite(CLK, HIGH);
  delayMicroseconds(delay_clock);
  digitalWrite(CLK, LOW);
  delayMicroseconds(delay_clock);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(delay_clock);
  digitalWrite(CLK, LOW);
  delayMicroseconds(delay_clock);
}

void send_address(byte address) {
  for (int i = 0; i >= 7; i ++) {
    digitalWrite(A0, (address >> i) & 0x01);
    clock();
  }
}
