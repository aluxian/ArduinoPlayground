const int UNIT = 200;
const int LED = 8;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(5000);
  
  char code[] = ".. / .-.. --- ...- . / -.-- --- ..-";
  int codeLen = strlen(code);
  
  for (int i = 0; i < codeLen; i++) {
    char nextChar = i < codeLen-1 ? code[i+1] : 0;
    switch(code[i]) {
      case '.': dot(nextChar); break;
      case '-': dash(nextChar); break;
      case ' ': space(); break;
      case '/': slash(); break;
    }
  }
}

void dot(char nextChar) {
  digitalWrite(LED, HIGH);
  delay(1 * UNIT);
  digitalWrite(LED, LOW);
  if (nextChar == '.' || nextChar == '-') {
    delay(1 * UNIT);
  }
}

void dash(char nextChar) {
  digitalWrite(LED, HIGH);
  delay(3 * UNIT);
  digitalWrite(LED, LOW);
  if (nextChar == '.' || nextChar == '-') {
    delay(1 * UNIT);
  }
}

void space() {
  delay(3 * UNIT);
}

void slash() {
  delay(7 * UNIT);
}

