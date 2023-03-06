#include <Arduino.h>

#include "Homespan.h"
#include "Doorbell.h"

int doorbellPin = 15;

void setup()
{
  Serial.begin(115200);
  homeSpan.begin(Category::ProgrammableSwitches, "Doorbell");
  homeSpan.enableWebLog();

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Doorbell(doorbellPin);
}

void loop()
{
  homeSpan.poll();
}
