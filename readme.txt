This is a multisensor program that is built on type tagging instead of inheritance meaning that every Sensor
instance have its own TYPE (enum class).

main.cc                     --> Hardcoded adding of sensors, asks user to set max temperature and then opens the 
                                menu with these options:

                                Print all Measurements
                                Sort by type
                                Erase data (from HEAP and HDD)
                                Get average temperature
                                Get average humidity

measurement-storage.h/cc    --> Adds measurements, stores data to heap and HDD, prints statistics, adds date stamps

measurement.h/cc            --> A simple struct that holds necessary information from a single sensor reading

sensor-manager.h/cc         --> SensorManager coordinates multiple sensors, handles data storage, sorting, printing, 
                                and threshold management for sensor readings. Holds a MeasurementStorage stack pointer.

sensor.h/cc                 --> Sensor distinguish between different sensors with enum, and returns a random generated  min and max value
                                and time stamp to simulate realistic(ish) reading.

utils.h/cc                  --> global helper functions
