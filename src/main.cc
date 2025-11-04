#include <iostream>
#include "sensor.h"
#include "measurement-storage.h"
#include "sensor-manager.h"

void addSensor(SensorManager* manager)
{
  int choice = 0;
  while(choice != 9)
  {
    std::cout << "Add sensor: \n1.TemperatureSensor\n2.HumiditySensor\n\n9. Back" << std::endl;
    std::cin >> choice;
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      system("clear");
      std::cout << "enter 1, 2 or 9" << std::endl;
      continue;
    }
    switch (choice)
    {
      case 1:
      {
        manager->addSensor(Sensor::UNIT::CELSIUS, Sensor::TYPE::TEMPERATURE, "thermometer", MinMax{-273.15f, 4000.f});
        std::cout << "Thermometer added" << std::endl;
      }
      break;
      case 2:
      {
        manager->addSensor(Sensor::UNIT::PERCENTAGE, Sensor::TYPE::HUMIDITY, "hygrometer", MinMax{0, 100});
        std::cout << "Hygrometer added" << std::endl;
      }
      break;
    }
  }
}

void readAndStore(SensorManager* manager)
{
  std::cout << "Wich sensor would you like to read and store from?\n1.Temperature\n2.Humidity" << std::endl;
  int choice = 0;
  while(choice != 9)
  {
    std::cin >> choice;
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      system("clear");
      std::cout << "please enter a valid number" << std::endl;
      continue;
    }

    switch(choice)
    {
      case 1:
      {
        manager->readAndStore(Sensor::TYPE::TEMPERATURE);
      }
      break;
      case 2:
      {
        manager->readAndStore(Sensor::TYPE::HUMIDITY);
      }
      break;
    }
  }
}

void menu(SensorManager* manager)
{
  int choice = 0;
  while(choice != 9)
  {
    std::cout << "1.Add sensor: \n2.Get Reading\n\n9. Back" << std::endl;
    std::cin >> choice;
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
      system("clear");
      std::cout << "enter 1, 2 or 9" << std::endl;
      continue;
    }
    switch (choice)
    {
      case 1:
      {
        addSensor(manager);
      }
      break;
      case 2:
      {
        readAndStore(manager);
      }
      break;
    }
  }
}

int main()
{ 
  std::unique_ptr<SensorManager> manager;
  std::make_unique<SensorManager>(manager);
    menu(manager.get());

  
    return 0;
}