#include "HomeSpan.h"

// https://github.com/HomeSpan/HomeSpan/blob/master/examples/16-ProgrammableSwitches/16-ProgrammableSwitches.ino
struct Doorbell : Service::Doorbell // StatelessProgrammableSwitch
{
  SpanCharacteristic *switchEvent;

  Doorbell(int doorbellPin) : Service::Doorbell() // StatelessProgrammableSwitch
  {
    switchEvent = new Characteristic::ProgrammableSwitchEvent();

    new SpanButton(doorbellPin, 2000, 5, 200, SpanButton::TRIGGER_ON_HIGH);
  }

  void button(int pin, int pressType) override
  {

    switchEvent->setVal(pressType);
  }
};
