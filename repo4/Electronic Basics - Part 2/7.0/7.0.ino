void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Delay Value
  int delVal = 5;

  // Arrays holding pin states (refer to Table 3)

  // arr is CW, arr1 is CCW
  int arr[] = {HIGH, LOW, LOW, LOW,
               HIGH, HIGH, LOW, LOW,
               LOW, HIGH, LOW, LOW,
               LOW, HIGH, HIGH, LOW,
               LOW, LOW, HIGH, LOW,
               LOW, LOW, HIGH, HIGH,
               LOW, LOW, LOW, HIGH,
               HIGH, LOW, LOW, HIGH};

  int arr1[] = {HIGH, LOW, LOW, HIGH,
                LOW, LOW, LOW, HIGH,
                LOW, LOW, HIGH, HIGH,
                LOW, LOW, HIGH, LOW,
                LOW, HIGH, HIGH, LOW,
                LOW, HIGH, LOW, LOW,
                HIGH, HIGH, LOW, LOW,
                HIGH, LOW, LOW, LOW};

 // CW
 for (int j = 0; j < 500; ++j)
 {
    for (int i = 0; i < 32; i=i+4)
    {
      digitalWrite(2, arr[i]);
      digitalWrite(3, arr[i+1]);
      digitalWrite(4, arr[i+2]);
      digitalWrite(5, arr[i+3]);

      delay(delVal);
    }
 }

 delay(1000);

 // CCW
 for (int j = 0; j < 500; ++j)
 {
    for (int i = 0; i < 32; i=i+4)
    {
      digitalWrite(2, arr1[i]);
      digitalWrite(3, arr1[i+1]);
      digitalWrite(4, arr1[i+2]);
      digitalWrite(5, arr1[i+3]);

      delay(delVal);
    }
 }

 delay(1000);

  

}
