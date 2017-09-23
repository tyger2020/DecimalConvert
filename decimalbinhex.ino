const char HEXVALUES[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

String decimal_to_bin(int input)
{
String output;
int mask;

for (int i = 31; i >= 0; i--) {
mask = (1<<i);
if (input & mask) {
output += '1';
}
else {
output += '0';
}
}

return output;
}

String decimal_to_hex(int input)
{
String output;
int mask;
int next;
int var;
// Write the hex value of input into
// the string output
mask = 15;


for (int i = 7; i >= 0; i--) {

next = input >> (i*4);

var = next & mask;
output += HEXVALUES[var];





}

return output;

}


String decimal_to_oct(int input)
{
String output;
int next;
int mask;
int var;
int var2;

// Write the octal value of input into
// the string output

next = input >> 30;
mask = 3;
var2 = next & mask;
output += static_cast<char>(var2 + '0');
for (int i = 9; i >= 0; i--) {
mask = 7;
next = input >> (i*3);
var = next & mask;
output += static_cast<char>(var + '0');

}

return output;
}


void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
// put your main code here, to run repeatedly:
if (Serial && (Serial.available() > 0)) {
String input = Serial.readString();
int i_input = input.toInt();

Serial.println("Dec: " + input);
Serial.println("Bin: " + decimal_to_bin(i_input));
Serial.println("Oct: " + decimal_to_oct(i_input));
Serial.println("Hex: " + decimal_to_hex(i_input));
Serial.print("\n");

}
else {
delay(115);
}
}
