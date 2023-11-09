# SecureSense: Gas and Environment Monitoring System

## Overview

SecureSense is an ESP32-based gas and environment monitoring system designed to provide real-time data on gas levels, temperature, and humidity. This project utilizes the MQ2 gas sensor and DHT11 temperature/humidity sensor, connecting to the Blynk platform for remote monitoring.

## Features

- **Gas Detection:** MQ2 sensor detects gas levels in the environment.
- **Temperature and Humidity Monitoring:** DHT11 sensor measures temperature and humidity.
- **Remote Monitoring:** Data is sent to the Blynk platform for real-time monitoring and control.

## Hardware Requirements

- ESP32 microcontroller
- MQ2 Gas Sensor
- DHT11 Temperature/Humidity Sensor
- Buzzer
- LED
- Resistors, Breadboard, and Jumper Wires

## Software Requirements

- Arduino IDE
- Blynk App (for remote monitoring)

## Installation and Setup

1. Clone the repository to your local machine.
2. Open the Arduino IDE and install the necessary libraries (Blynk and DHT).
3. Configure your Blynk authentication token, Wi-Fi credentials, and other settings in the code.
4. Connect the sensors and components to the ESP32 according to the wiring diagram.
5. Upload the code to your ESP32.

## Usage

1. Open the Blynk app on your mobile device.
2. Create a new project and obtain the authentication token.
3. Configure the Blynk app with the necessary widgets for temperature, humidity, and gas level display.
4. Run the ESP32 with the uploaded code.
5. Monitor the gas levels, temperature, and humidity in real-time through the Blynk app.

## Wiring Diagram

Will be Uploaded soon

## Troubleshooting

- If you encounter issues with gas readings, check the MQ2 sensor connections.
- For temperature/humidity issues, verify the DHT11 sensor connections.
- Ensure a stable internet connection for Blynk communication.

## Contributing

If you'd like to contribute to the SecureSense project, please fork the repository and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
