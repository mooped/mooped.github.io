#include <stdio.h>
#include <wiringPi.h>

#define ON_BUTTON	6
#define OFF_BUTTON	4
#define ONE_SWITCH	11
#define TWO_SWITCH	10
#define THREE_SWITCH	5

void remoteInitPin(int pin)
{
  digitalWrite(pin, HIGH);
  pinMode(pin, OUTPUT);
}

void remoteWrite(int pin, int out)
{
  digitalWrite(pin, out?HIGH:LOW);
}

void remoteInit()
{
  wiringPiSetup();
  remoteInitPin(ON_BUTTON);
  remoteInitPin(OFF_BUTTON);
  remoteInitPin(ONE_SWITCH);
  remoteInitPin(TWO_SWITCH);
  remoteInitPin(THREE_SWITCH);
}

void remoteSwitchDevice(int device, int bOn)
{
  switch (device)
  {
    case 0: remoteWrite(ONE_SWITCH, 0); break;
    case 1: remoteWrite(TWO_SWITCH, 0); break;
    case 2: remoteWrite(THREE_SWITCH, 0); break;
  }
  remoteWrite(bOn?ON_BUTTON:OFF_BUTTON, 0);
  delay(100);
  remoteWrite(bOn?ON_BUTTON:OFF_BUTTON, 1);
  switch (device)
  {
    case 0: remoteWrite(ONE_SWITCH, 1); break;
    case 1: remoteWrite(TWO_SWITCH, 1); break;
    case 2: remoteWrite(THREE_SWITCH, 1); break;
  }
}

int main(int argc, char **argv)
{
  remoteInit();
  remoteSwitchDevice(0, 1);
  delay(5000);
  remoteSwitchDevice(0, 0);
}
