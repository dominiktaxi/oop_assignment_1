#include <iostream>
#include "sensor.h"
#include "measurement-storage.h"
#include "sensor-manager.h"

void menu(SensorManager& sensorManager, MeasurementStorage& storage)
{
  int choice = -1;
  int amountOfSensors = sensorManager.sensors().size();
  while(choice != 0)
  {
    
    std::cout << "Choose wich sensor to read and collect data from\n" << std::endl;
    sensorManager.printAll();
    std::cout << amountOfSensors + 1 << "Print all measurements\n0.Exit" << std::endl;
    std::cout << amountOfSensors + 2 << "Sort by type" << std::endl;
    std::cin >> choice;
    system("clear");
    if(std::cin.fail())
    {
      std::cout << "Please enter a numeric value" << std::endl;
      std::cin.clear();
      std::cin.ignore();
      continue;
    }
    else if(choice > 0 && choice <= amountOfSensors)
    {
    sensorManager.store(choice);
    }
    else if ( choice == amountOfSensors + 1)
    {
      sensorManager.printAllMeasurements();
    }
    else if (choice == amountOfSensors + 2)
    {
      sensorManager.sortByType();
    }
  }
  
}

int main()
{ 
  MeasurementStorage storage;
  SensorManager manager(&storage);
  manager.addSensor(Sensor::UNIT::PERCENTAGE, Sensor::TYPE::HUMIDITY, MinMax{0, 100});
  manager.addSensor(Sensor::UNIT::CELSIUS, Sensor::TYPE::TEMPERATURE, MinMax{0, 4000});
  storage.loadFromHDD();
  menu(manager, storage);

  storage.saveAlltoHDD();
  return 0;
}