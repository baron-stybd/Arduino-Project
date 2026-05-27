#include <LiquidCrystal.h>

// Konfigurasi pin LCD
const int rs = 10, en = 9, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ldrRaw;
int ldrPersen;

void setup() {
  Serial.begin(9600);
  
  // Inisialisasi LCD 16x2
  lcd.begin(16, 2);
  
  // Menampilkan layar pembuka
  lcd.setCursor(0, 0);
  lcd.print("Lux Meter");
  lcd.setCursor(0, 1);
  lcd.print("Prototype");
  
  delay(2000);
  lcd.clear();
  
  // Menyiapkan teks statis
  lcd.setCursor(0, 0);
  lcd.print("Persentase LDR:");
}

void loop() {
  // Membaca nilai analog dari LDR
  ldrRaw = analogRead(A0);
  
  // Menampilkan nilai mentah ke Serial Monitor
  Serial.print("Nilai Mentah LDR: ");
  Serial.println(ldrRaw);
  
  // Mengonversi nilai mentah menjadi persentase (0-100%)
  ldrPersen = map(ldrRaw, 12, 600, 0, 100);
  
  // Membatasi nilai persentase agar tidak di luar rentang 0-100
  ldrPersen = constrain(ldrPersen, 0, 100);
  
  // Menampilkan hasil pada LCD
  lcd.setCursor(0, 1);
  lcd.print(ldrPersen);
  lcd.print("%   "); // Spasi tambahan untuk menimpa karakter sisa jika angka turun dari 3 digit ke 2 digit
  
  delay(100); // Sedikit jeda untuk kestabilan pembacaan
}
