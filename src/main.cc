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
    std::cout << amountOfSensors + 1 << ".Print all measurements\n" << std::endl;
    std::cout << amountOfSensors + 2 << ".Sort by type" << std::endl;
    std::cout << amountOfSensors + 3 << ".Erase data from HDD" << std::endl;
    std::cout << amountOfSensors + 4 << ".Get average temperature" << std::endl;
    std::cout << amountOfSensors + 5 << ".Get average humidity" << std::endl;
    std::cout << "0.Exit" << std::endl;
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
    else if (choice == amountOfSensors + 3)
    {
      storage.eraseData();
    }
    else if (choice == amountOfSensors + 4)
    {
      std::cout << storage.average(Sensor::TYPE::TEMPERATURE) << std::endl;
    }
    else if (choice == amountOfSensors + 5)
    {
      std::cout << storage.average(Sensor::TYPE::HUMIDITY) << std::endl;
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