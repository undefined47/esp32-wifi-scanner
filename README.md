
# ESP32 Wi-Fi Scanner

A beginner-friendly Wi-Fi scanner built using the ESP32 DevKit V1 and Arduino IDE.

The project scans nearby 2.4 GHz wireless networks and displays their SSID, signal strength, channel, and security type through the Serial Monitor.

## Features

- Scan nearby Wi-Fi networks
- Display network names (SSID)
- Show signal strength in dBm
- Display Wi-Fi channels
- Identify advertised security types
- Detect hidden networks when advertised
- Automatically scan every 5 seconds
- No additional hardware required

## Hardware Requirements

- ESP32 DevKit V1
- USB data cable
- Computer with Arduino IDE

## Software Requirements

- Arduino IDE 2.x
- ESP32 board support package by Espressif Systems

## Installation

1. Install Arduino IDE.
2. Open Boards Manager.
3. Search for `esp32`.
4. Install ESP32 by Espressif Systems.
5. Connect your ESP32 using USB.
6. Select `ESP32 Dev Module` under Tools > Board.
7. Select the correct port under Tools > Port.
8. Open `esp32_wifi_scanner.ino`.
9. Upload the code.
10. Open Serial Monitor at 115200 baud.

## Example Output

```text
ESP32 Wi-Fi Scanner

Scanning nearby Wi-Fi networks...

3 network(s) found:

#   | SSID          | RSSI     | Channel | Security
1   | My_Phone      | -42 dBm  | 6       | WPA2
2   | Home_WiFi     | -68 dBm  | 11      | WPA2/WPA3
3   | Guest_Network | -81 dBm  | 1       | Open
```

Actual results depend on your environment.

## Understanding RSSI

RSSI measures received signal strength.

| RSSI | Approximate Signal |
|---|---|
| -30 to -50 dBm | Very strong |
| -51 to -65 dBm | Strong |
| -66 to -75 dBm | Moderate |
| -76 to -90 dBm | Weak |

## Troubleshooting

### Hard resetting via RTS pin

This is usually normal after uploading. Open Serial Monitor at 115200 baud.

### No networks found

- Ensure nearby Wi-Fi networks are active.
- Remember that the ESP32 DevKit V1 scans 2.4 GHz Wi-Fi, not 5 GHz.
- Move closer to the access point.

### Unreadable Serial Monitor output

Set the baud rate to 115200.

## Future Improvements

- Live web dashboard
- Signal strength visualization
- Scan history
- Channel distribution chart
- OLED display support

## License

MIT License
