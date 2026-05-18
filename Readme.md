# Arduino TMP36 Temperature Sensor & LED Indicator 🌡️💡

Proyek ini adalah sistem pembacaan suhu *real-time* menggunakan sensor TMP36 berbasis Arduino. Sistem ini dilengkapi dengan fitur aktuator berupa lampu LED yang diprogram untuk menyala secara otomatis ketika ambang batas suhu melebihi 50°C. 

## Komponen yang Dibutuhkan

* 1x Mikrokontroler Arduino Uno R3
* 1x Sensor Suhu TMP36
* 1x LED (Warna bebas)
* 1x Resistor 220 Ohm
* Kabel Jumper secukupnya
* Papan *Breadboard* (Opsional)

## Skema Rangkaian (Wiring)

Pastikan koneksi pin terpasang dengan presisi agar sensor mendapatkan daya yang stabil dan tidak menghasilkan nilai *floating*.

**Sensor Suhu (TMP36):**
* Kaki Kiri (VCC) $\rightarrow$ Pin **5V** Arduino
* Kaki Tengah (VOUT) $\rightarrow$ Pin **A0** Arduino
* Kaki Kanan (GND) $\rightarrow$ Pin **GND** Arduino

**Indikator Lampu (LED):**
* Kaki *Anode* (Positif) $\rightarrow$ Pin **13** Arduino
* Kaki *Cathode* (Negatif) $\rightarrow$ Dihubungkan ke Resistor
* Sisi lain Resistor $\rightarrow$ Pin **GND** Arduino

## Kode Program (Source Code)

Kode ini dirancang dengan tingkat akurasi tinggi. Output pada *Serial Monitor* telah dikonfigurasi untuk menampilkan hasil perhitungan menggunakan presisi 4 angka di belakang koma.

```cpp
const int ledPin = 13; // Definisi pin aktuator LED

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);      // Konfigurasi pin sensor sebagai INPUT
  pinMode(ledPin, OUTPUT); // Konfigurasi pin LED sebagai OUTPUT
}

void loop() {
  // Membaca sinyal analog dari sensor TMP36 (rentang 0 - 1023)
  int sensorVal = analogRead(A0);
  
  // Mengonversi nilai analog menjadi tegangan referensi (Volt)
  float voltage = (sensorVal / 1024.0) * 5.0;
  
  // Mengonversi tegangan menjadi suhu dalam skala Celcius
  float temp = (voltage - 0.5) * 100.0;
  
  // Menampilkan hasil komputasi dengan format 4 desimal
  Serial.print("Suhu Terukur: ");
  Serial.print(temp, 4);
  Serial.println(" C");

  // Logika kontrol aktuator
  if (temp > 50.0) {
    digitalWrite(ledPin, HIGH); // Aktifkan LED jika suhu > 50 C
  } else {
    digitalWrite(ledPin, LOW);  // Nonaktifkan LED jika suhu <= 50 C
  }

  delay(2
