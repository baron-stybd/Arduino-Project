# Arduino LDR Lux Meter Prototype

Proyek ini adalah simulasi pembacaan intensitas cahaya menggunakan sensor LDR (Light Dependent Resistor) dengan mikrokontroler Arduino Uno. Hasil pembacaan sensor dalam bentuk persentase (0% - 100%) ditampilkan melalui layar LCD 16x2 dan dipantau melalui *Serial Monitor*. Simulasi ini dirancang menggunakan Tinkercad.

## 🔌 Skema Rangkaian (Wiring)

Berikut adalah visualisasi grafis dari rangkaian komponen yang digunakan dalam proyek ini:

![Skema Rangkaian](src/Cuplikanlayar2026-05-26194716.png)

### Konfigurasi Pin

| Komponen | Pin / Koneksi | Pin Arduino |
| :--- | :--- | :--- |
| **LDR** | Titik tengah (*Voltage Divider*) | Analog `A0` |
| **LCD 16x2** | `RS` | Digital `10` |
| | `EN` | Digital `9` |
| | `D4` | Digital `5` |
| | `D5` | Digital `6` |
| | `D6` | Digital `7` |
| | `D7` | Digital `8` |

> **Catatan:** Pin VCC dan GND pada semua komponen dihubungkan ke jalur 5V dan GND pada Arduino.

## 💻 Cara Kerja Program
1. Arduino membaca nilai tegangan analog dari sensor LDR melalui pin `A0` menggunakan fungsi `analogRead()`.
2. Nilai mentah (ADC) tersebut dikonversi menjadi rentang persentase menggunakan fungsi `map()`.
3. Fungsi `constrain()` digunakan untuk memastikan nilai persentase tidak melebihi batas 100% atau kurang dari 0%.
4. Hasil akhir dikirim ke LCD 16x2 untuk ditampilkan secara *real-time*.

## 👨‍💻 Penulis
**JockerOldmoney** - Politeknik Perkapalan Negeri Surabaya (PPNS)
