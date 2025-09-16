// تعريف نوع الاتصال بـ RemoteXY وهو الاتصال التسلسلي
#define REMOTEXY_MODE__HARDSERIAL
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600

// تعريف أرجل حساس الموجات فوق الصوتية
#define trigPin 9
#define echoPin 10
long duration, mesafe;

#include <RemoteXY.h> // مكتبة التحكم من خلال تطبيق RemoteXY

// إعداد واجهة التطبيق (مُولدة تلقائيًا من RemoteXY)
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = { 
  // هذا الجزء مُولد تلقائيًا من موقع RemoteXY
  // لا تعدل عليه يدويًا
  255,3,0,40,0,168,0,19,0,0,0,0,31,1,106,200,1,1,15,0,
  ...
};
#pragma pack(pop)

// هيكل البيانات اللي فيه متغيرات الإدخال والإخراج للتحكم
struct {
  // عناصر إدخال من الواجهة
  int8_t slider_01; // سلايدر (من 0 إلى 100)
  int8_t joystick_01_x; // حركة أفقية (من -100 إلى 100)
  int8_t joystick_01_y; // حركة رأسية (من -100 إلى 100)

  // عناصر إخراج إلى الواجهة
  int8_t level_temp_up;
  int8_t level_temp_down;
  int8_t level_hum;
  char text_temp[11]; // لعرض درجة الحرارة
  char text_hum[11];  // لعرض الرطوبة
  int16_t sound_01;
  int16_t sound_02;
  char value_01[11]; // لعرض المسافة
  uint8_t connect_flag;
} RemoteXY;

// مكتبة حساس DHT11 لقراءة الحرارة والرطوبة
#include "DHT.h"
#define DHTPIN 2
DHT dht(DHTPIN, DHT11); // تهيئة الحساس

// مكتبة السيرفو موتور
#include <Servo.h>
Servo myservo; // إنشاء كائن للسيرفو

// تعريف أرجل المحركات
#define PIN_MOTOR_RIGHT_UP 7
#define PIN_MOTOR_RIGHT_DN 6
#define PIN_MOTOR_RIGHT_SPEED 11

#define PIN_MOTOR_LEFT_UP 5
#define PIN_MOTOR_LEFT_DN 4
#define PIN_MOTOR_LEFT_SPEED 3

// تحديد أرجُل كل موتور في مصفوفات
unsigned char RightMotor[3] = {PIN_MOTOR_RIGHT_UP, PIN_MOTOR_RIGHT_DN, PIN_MOTOR_RIGHT_SPEED};
unsigned char LeftMotor[3] = {PIN_MOTOR_LEFT_UP, PIN_MOTOR_LEFT_DN, PIN_MOTOR_LEFT_SPEED};

// دالة للتحكم في حركة كل موتور
void Wheel (unsigned char * motor, int v) {
  if (v > 100) v = 100;
  if (v < -100) v = -100;

  if (v > 0) {
    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], v * 2.55); // تحويل من 0-100 إلى 0-255
  } 
  else if (v < 0) {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    analogWrite(motor[2], (-v) * 2.55);
  } 
  else {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
    analogWrite(motor[2], 0);
  }
}

void setup() {
  RemoteXY_Init(); // تهيئة الاتصال مع التطبيق
  myservo.attach(12); // توصيل السيرفو بالرجل رقم 12
  RemoteXY.slider_01 = 50; // ضبط السلايدر على القيمة المبدئية 50

  // تهيئة الحساسات والمخارج كمخارج أو مداخل
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(PIN_MOTOR_RIGHT_UP, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_DN, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_UP, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_DN, OUTPUT);
}

void loop() {
  RemoteXY_Handler(); // تحديث الاتصال مع تطبيق RemoteXY

  // قراءة درجة الحرارة والرطوبة
  float temp = dht.readTemperature();   
  float hum = dht.readHumidity(); 

  // تحويل القيم إلى نصوص لعرضها في التطبيق
  dtostrf(temp, 0, 1, RemoteXY.text_temp); 
  dtostrf(hum, 0, 1, RemoteXY.text_hum); 

  // تحديث مؤشرات الحرارة في التطبيق
  if (temp < 0) { 
    RemoteXY.level_temp_up = 0; 
    RemoteXY.level_temp_down = min(-temp * 2, 100); 
  } 
  else if (temp > 0) { 
    RemoteXY.level_temp_up = min(temp * 2, 100); 
    RemoteXY.level_temp_down = 0; 
  } 
  else {
    RemoteXY.level_temp_up = 0;
    RemoteXY.level_temp_down = 0;
  }

  // مؤشر الرطوبة
  RemoteXY.level_hum = hum;

  // إشارات للصوت حسب قراءة A0 و A1
  if (digitalRead(A0) == HIGH) {   
    RemoteXY.sound_01 = 0;
  } else {
    RemoteXY.sound_01 = 1001; // تشغيل صوت معين
  }

  if (digitalRead(A1) == HIGH) {   
    RemoteXY.sound_02 = 0;
  } else {
    RemoteXY.sound_02 = 1001;
  }

  // قراءة المسافة باستخدام الحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 100000); // قياس مدة النبضة
  mesafe = (duration / 2) / 29.1; // تحويل إلى سنتيمتر

  // عرض المسافة على التطبيق
  if (mesafe < 2 || mesafe > 300)
    strcpy(RemoteXY.value_01, "Out Range");
  else
    itoa(mesafe, RemoteXY.value_01, 10);

  delay(100); // تأخير بسيط

  // تحكم في زاوية السيرفو بناءً على السلايدر
  int ms = RemoteXY.slider_01 * 20 + 500; // تحويل السلايدر إلى Microseconds
  myservo.writeMicroseconds(ms);

  // تحكم في حركة المحركات حسب الجويستيك
  Wheel(RightMotor, RemoteXY.joystick_01_y - RemoteXY.joystick_01_x);
  Wheel(LeftMotor, RemoteXY.joystick_01_y + RemoteXY.joystick_01_x);
}
