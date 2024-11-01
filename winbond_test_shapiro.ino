// Written based off the data sheet for the Winbond test chip as described in the MiniMed 530G Progress Report 2
// Written with Tom Claflin at the Leahy Center

const int CS = 8;
const int DO = 9; 
const int CLK = 10;
const int DI = 11;

int delay = 250

int ending_delay = 10;

void setup() {
  pinMode(CS, OUTPUT);
  delayMicroseconds(delay);
  pinMode(DO, INPUT);
  delayMicroseconds(delay);
  pinMode(CLK, OUTPUT);
  delayMicroseconds(delay);
  pinMode(DI, OUTPUT);
  delayMicroseconds(delay);

  digitalWrite(CS, HIGH);
}

void loop() {
  digitalWrite(CS, LOW);

  send_command(0x9F);
  send_command(0x00);
  send_command(0x00);
  send_command(0x00);

  digitalWrite(CS, HIGH);

  delay(ending_delay);
}

void clock {
  digitalWrite(CLK, HIGH);
  digitalWrite(CLK, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(CLK, LOW);
}

void send_command(data) {
  for (int i = 7, i >= 0; i --) {
    digitalWrite(DI, (data >> i), 0x01);
    clock();
  }
}
