import processing.serial.*;

Serial serialPort;
String sentText="";
String pixelArray = "1,0,0";

void setup() {
  size(300,300);
  printArray(Serial.list());
  serialPort = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  background(0);

  if(mousePressed && (mouseButton == LEFT)){
    serialPort.write("1");
    // serialPort.write('1');
  }
  if(mousePressed && (mouseButton == RIGHT)){
   serialPort.write("0");
    // serialPort.write('0');
  }
}

void serialEvent (Serial serialPort){
}

void serialSendArray() {
  // Serial.write(pixelArray);
}