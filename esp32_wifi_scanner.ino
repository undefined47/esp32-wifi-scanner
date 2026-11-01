#include <WiFi.h>

const unsigned long SCAN_INTERVAL = 5000;

const char* getSecurityType(wifi_auth_mode_t mode) {
  switch (mode) {
    case WIFI_AUTH_OPEN:
      return "Open";
    case WIFI_AUTH_WEP:
      return "WEP";
    case WIFI_AUTH_WPA_PSK:
      return "WPA";
    case WIFI_AUTH_WPA2_PSK:
      return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA/WPA2";
    case WIFI_AUTH_WPA2_ENTERPRISE:
      return "WPA2 Enterprise";
    case WIFI_AUTH_WPA3_PSK:
      return "WPA3";
    case WIFI_AUTH_WPA2_WPA3_PSK:
      return "WPA2/WPA3";
    default:
      return "Unknown";
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println("      ESP32 Wi-Fi Scanner");
  Serial.println("==============================");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(100);
}

void loop() {
  Serial.println("\nScanning nearby Wi-Fi networks...");

  int networks = WiFi.scanNetworks(false, true);

  if (networks == WIFI_SCAN_FAILED) {
    Serial.println("Scan failed.");
  } else if (networks == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.printf("\n%d network(s) found:\n\n", networks);

    Serial.println(
      "---------------------------------------------------------------"
    );

    Serial.printf(
      "%-3s | %-30s | %-8s | %-7s | %s\n",
      "#", "SSID", "RSSI", "Channel", "Security"
    );

    Serial.println(
      "---------------------------------------------------------------"
    );

    for (int i = 0; i < networks; i++) {
      String ssid = WiFi.SSID(i);

      if (ssid.length() == 0) {
        ssid = "<hidden>";
      }

      Serial.printf(
        "%-3d | %-30.30s | %4d dBm | %-7d | %s\n",
        i + 1,
        ssid.c_str(),
        WiFi.RSSI(i),
        WiFi.channel(i),
        getSecurityType(WiFi.encryptionType(i))
      );
    }

    Serial.println(
      "---------------------------------------------------------------"
    );
  }

  WiFi.scanDelete();

  delay(SCAN_INTERVAL);
}
