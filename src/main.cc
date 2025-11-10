#include <iostream>
#include "sensor.h"
#include "measurement-storage.h"
#include "sensor-manager.h"

void setThreshold(Sensor::TYPE TYPE, SensorManager& manager)
{
  std::string type;
  if (TYPE == Sensor::TYPE::HUMIDITY) {type = "humidity";}
  if (TYPE == Sensor::TYPE::TEMPERATURE) {type = "temperature";}
  float threshold;
  while(true)
  {
    std::cout << "Set" << type <<  " threshold:" << std::endl;
    std::cin >> threshold;
    system("clear");
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Please enter a numeric value" << std::endl;
      continue;
    }
    else if(TYPE == Sensor::TYPE::HUMIDITY && (threshold > 100 || threshold < 1))
    {
      std::cout << "Humidity threshold must be set between 1 and 100" << std::endl;
      continue;
    }
    if(TYPE == Sensor::TYPE::HUMIDITY) {manager.setHumidityThreshold(threshold);}
    if(TYPE == Sensor::TYPE::TEMPERATURE) {manager.setTemperatureThreshold(threshold);}
    std::cout << "Threshold set" << std::endl;
    break;
  }

}

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
    std::cout << amountOfSensors + 3 << ".Erase data" << std::endl;
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
  setThreshold(Sensor::TYPE::HUMIDITY, manager);
  setThreshold(Sensor::TYPE::TEMPERATURE, manager);
  manager.addSensor(Sensor::UNIT::PERCENTAGE, Sensor::TYPE::HUMIDITY, MinMax{0.f, 100.f});
  manager.addSensor(Sensor::UNIT::CELSIUS, Sensor::TYPE::TEMPERATURE, MinMax{-50.f, 150.f});
  storage.loadFromHDD();
  menu(manager, storage);

  storage.saveAlltoHDD();
  return 0;
}