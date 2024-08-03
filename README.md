# Smart Soil Moisture Monitoring

## Overview

The Smart Soil Moisture Monitoring system is an AVR-based project designed to automate irrigation processes, optimizing water usage for agricultural efficiency and sustainability. The system uses a combination of an LCD, buzzer, ADC, soil moisture sensor, and a water supply mechanism (pipe and tank) to monitor soil moisture levels and control irrigation.

## System Components

1. **Microcontroller**: AVR-based microcontroller (e.g., ATmega32).
2. **Soil Moisture Sensor**: Measures soil moisture content.
3. **ADC**: Converts the analog output from the soil moisture sensor to digital values.
4. **LCD**: Displays real-time soil moisture levels and system status.
5. **Buzzer**: Alerts when water level in tank is below the threshold.
6. **Water Supply Mechanism**:
   - **Pipe**: Delivers water to the soil.
   - **Tank**: Stores water for irrigation.

## System Functionality

1. **Soil Moisture Measurement**:
   - The soil moisture sensor continuously monitors the moisture level of the soil.
   - The ADC converts the sensor's analog output into a digital value for processing.

2. **Display and Alerts**:
   - The LCD displays the current soil moisture level and system status.
   - The buzzer emits an alert sound when the Water level in tank falls below a predefined threshold.

3. **Irrigation Control**:
   - When soil moisture is below the threshold, the system activates the water supply mechanism (pipe and tank) to irrigate the soil.

## Hardware Connections

1. **Soil Moisture Sensor**:
   - Connect to ADC input pins for moisture level measurement.

2. **LCD**:
   - Connect to appropriate GPIO pins for data and control.

3. **Buzzer**:
   - Connect to a GPIO pin for alert signaling.

4. **Water Supply Mechanism**:
   - **Pipe**: Connected to the irrigation system controlled by the microcontroller.
   - **Tank**: Connected to the pipe and provides water for irrigation.

## Software Implementation

1. **ADC Configuration**:
   - Set up ADC to read the soil moisture sensor data.

2. **LCD Display**:
   - Implement functions to display soil moisture levels and system status.

3. **Buzzer Control**:
   - Implement a function to activate the buzzer when water level in tank below 600.

4. **Irrigation Control**:
   - Implement control logic to activate the water supply mechanism based on moisture levels when it greater than 500.

## Getting Started

1. **Hardware Setup**:
   - Connect the soil moisture sensor, LCD, buzzer, and water supply mechanism as per the design.

2. **Software Setup**:
   - Program the microcontroller with the necessary configurations and control logic for ADC, LCD, buzzer, and irrigation control.

3. **Testing**:
   - Verify the soil moisture readings on the LCD.
   - Check the buzzer alert functionality.
   - Ensure the water supply mechanism activates correctly based on soil moisture levels.

