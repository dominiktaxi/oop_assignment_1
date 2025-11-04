#include <iostream>
#include "sensor.h"
#include "measurement-storage.h"
int main()
{
  Sensor sensor(Sensor::UNIT::CELSIUS, Sensor::TYPE::TEMPERATURE, "temperatureSensor", MinMax{2, 8});
  Sensor sensor2(Sensor::UNIT::PERCENTAGE, Sensor::TYPE::HUMIDITY, "humiditySensor", MinMax{0, 100});
  MeasurementStorage storage;
  storage.addMeasurement(sensor.read());
  storage.addMeasurement(sensor.read());
  storage.addMeasurement(sensor.read());
  storage.addMeasurement(sensor2.read());
  storage.addMeasurement(sensor2.read());
  storage.addMeasurement(sensor2.read());
  storage.printAll();
  return 0;
}