r thevoid setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Delay Value
  int delVal = 3;

  // Array holding pin states
  int arr[] = {HIGH, LOW, LOW, LOW,
               HIGH, HIGH, LOW, LOW,
               LOW, HIGH, LOW, LOW,
               LOW, HIGH, HIGH, LOW,
               LOW, LOW, HIGH, LOW,
               LOW, LOW, HIGH, HIGH,
               LOW, LOW, LOW, HIGH,
               HIGH, LOW, LOW, HIGH};

 // Set pin states (ON || OFF) based on ARRAY (Refered to Table 3)
 for (int i = 0; i < 32; i=i+4)
 {
  digitalWrite(2, arr[i]);
  digitalWrite(3, arr[i+1]);
  digitalWrite(4, arr[i+2]);
  digitalWrite(5, arr[i+3]);

  delay(delVal);
 }
  

}
