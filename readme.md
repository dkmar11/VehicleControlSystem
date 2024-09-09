# Vehicle Control System with ESP32 and Bluetooth

This project demonstrates a Bluetooth-based control system for various vehicle functions, such as controlling lights, window lifters, indicators, and other outputs, using the ESP32 microcontroller. The system communicates via Bluetooth using simple commands to control physical and virtual outputs.

## Project Overview

The primary goal of this project is to control multiple vehicle functions wirelessly. It allows control over the following components:
- Window lifters (via a demultiplexer)
- High and low beams
- Turn signals (left and right)
- Parking lights
- Engine ignition
- Central locking system

### Features:
- Bluetooth communication via `BluetoothSerial` for wireless control.
- Authentication using a pre-defined password.
- Support for controlling up to 4 window lifters using a demultiplexer.
- Control of various vehicle outputs (lights, ignition, locks).
- Simple, efficient binary control logic for digital outputs.

### Hardware Used:
- **ESP32**: The core of the project, handling Bluetooth communication and output control.
- **Demultiplexer (DEMUX)**: To manage multiple outputs with fewer GPIO pins.

## Commands

The following commands are sent via Bluetooth to control the vehicle’s components:

- **Window Lifter Control**:
  - `V1U`, `V2U`, `V3U`, `V4U`: Raise windows 1 to 4.
  - `V1D`, `V2D`, `V3D`, `V4D`: Lower windows 1 to 4.
  
- **Lighting Control**:
  - `LA`: High beam lights toggle.
  - `LM`: Low beam lights toggle.
  - `LI`: Left indicator toggle.
  - `LD`: Right indicator toggle.
  - `PA`: Parking lights toggle.

- **Other Controls**:
  - `CO`: Toggle engine ignition.
  - `PUE`: Control the central locking system.
  - `AR`: Engine start.
  - `OFF`: Turn off all controlled components.
  
### Password Authentication

The system includes a basic password authentication feature. The default password is `"ESP32test"`. Once authenticated, the user can send commands to control the vehicle’s outputs.

## Setup Instructions

1. **Hardware Setup**:
   - Connect the ESP32 to the vehicle's electronic components (e.g., window motors, lights, indicators) as per the pin assignments in the code.
   - Make sure the DEMUX and all other components are properly wired.

2. **Software Setup**:
   - Use the Arduino IDE to upload the provided code to the ESP32.
   - Ensure that Bluetooth is enabled on the ESP32.
   - Pair your device with the ESP32 module via Bluetooth (name: `ESP32test`).

3. **Control**:
   - After pairing, send commands via a Bluetooth terminal app (e.g., Serial Bluetooth Terminal) to control the vehicle components.

## Dependencies

- ESP32 board support package (install via Arduino IDE Board Manager).
- BluetoothSerial library for ESP32.
- Arduino IDE 1.8+ or PlatformIO for code upload.

## Notes

- This project is for demonstration purposes and is not intended for direct use in production vehicles.
- The system could be expanded with additional sensors and safety features for better integration into real-world automotive applications.

## License

This project is licensed under the MIT License. See the LICENSE file for more information.
