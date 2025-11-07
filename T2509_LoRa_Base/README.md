/******************************************************************************
T2509_LoRa_Base

https://github.com/infrapale/T2509_LoRa_Base
*******************************************************************************
Related Applications:
  Sensor with LoRa interface (TelaBeach)
    https://github.com/infrapale/T2509_LoRa_Sensor

  Base Application, Arduino temporaty for testing only 
    https://github.com/infrapale/T2509_TFT18_Base 
  
  Cloud Gatway
    Still work in progress

*******************************************************************************

Required non-arduino Libraries:
  https://github.com/infrapale/T2409_atask

*******************************************************************************



-------------       --------------       --------------       --------------
| LoRa      |       |  LoRa      |       |  Base      |       |  Cloud     |
| TelaBeach |       |  Base      |       |  Localr    |       |  Gateway   |
| Sensor    |       |  RFM       |       |  Client    |       |            |
-------------       --------------       --------------       --------------
      |                   |                    |                    |
      | <sensor LoRa msg> |                    |                    |
      |- - - - - - - - - >|                    |                    |
      |                   | <base_sensor_msg>  |                    |
      |                   |------------------->|                    |
      |                   |       <base_sensor_msg>  (Serial2)      |
      |                   |---------------------------------------->|
      |                   |                    |                    |
     
    <sensor LoRa msg> and <base_sensor_msg>: 
      <0;3;S5;T24.9;H51;C95;#21>
       | |  |  |     |   |   |
       | |  |  |     |   |   ----- Checksum  TBD  '#'
       | |  |  |     |   --------- sensor message counter 'C'
       | |  |  |     ------------- sensor value H = Humidity
       | |  |  ------------------- sensor value T = Temperature
       | |  ---------------------- sensor type 'S'
       | ------------------------- from node > 0
       --------------------------- target node == 0 

    Sensor Type:
      SENSOR_TYPE_UNDEFINED   = 0,
      SENSOR_TYPE_BMP180      = 1
      SENSOR_TYPE_BMP280      = 2
      SENSOR_TYPE_BME680      = 3
      SENSOR_TYPE_AHT20       = 4 
      SENSOR_TYPE_SHT21       = 5
      SENSOR_TYPE_DS18B20     = 6
      SENSOR_TYPE_PIR         = 7

    Field Tag
      S   Sensor type
      C   Message counter (sensor specific)
      #   Checksum
      T   Temperature
      H   Humidity
      P   Pressure
      N   Counter/amount  (eg. PIR counter)

*******************************************************************************