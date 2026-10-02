#include "WiFi.h"  // Incluye la biblioteca WiFi para manejar la conectividad Wi-Fi

void setup()
{
    Serial.begin(115200);          // Iniciar comunicación serial
    WiFi.mode(WIFI_STA);           // Configura el ESP32 en modo estación (cliente) y desconecta de una AP si estaba previamente conectado
    WiFi.disconnect();
    delay(100);                    // Espera 100 ms para asegurar que la desconexión esté completa
    Serial.println("Setup done");
}

void loop()
{
    Serial.println("scan start");  // Iniciando escaneo de redes
    int n = WiFi.scanNetworks();   // Obtener número de redes encontradas
    Serial.println("scan done");
    
    if (n == 0) {                  // Indicar si no se encontró ninguna red
        Serial.println("no networks found");
    } else {
        Serial.print(n);           // Caso contrario indicar el número de redes encontrados
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) { // E imprimir el índice / intensidad de señal (SSID) de cada red
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));  // SSID de la red
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));  // Intensidad de la señal en dBm
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");  // Indica si la red está abierta o cifrada
            delay(10);             // Pequeña pausa para no saturar el monitor serie
        }
    }
    Serial.println("");

    delay(5000); // Con intención de evitar saturación
}
