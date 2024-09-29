//SSD1306_SWITCHCAPVCC

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_RESET);
  display.display();
  delay(2000);

  drawMandelbrot();
}

void loop() {
  // No se necesitan acciones adicionales en el bucle
}

void drawMandelbrot() {
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
      float a = map(x, 0, SCREEN_WIDTH, -2.0, 1.0);
      float b = map(y, 0, SCREEN_HEIGHT, -1.0, 1.0);
      int color = mandelbrot(a, b);
      display.drawPixel(x, y, color);
    }
  }
  display.display();  // Actualiza la pantalla una vez después de dibujar todos los píxeles
}

int mandelbrot(float a, float b) {
  float x = 0;
  float y = 0;
  float x2 = 0;
  float y2 = 0;
  int maxIterations = 100;
  int n = 0;

  while (n < maxIterations && (x2 + y2) <= 4.0) {
    y = 2 * x * y + b;
    x = x2 - y2 + a;
    x2 = x * x;
    y2 = y * y;
    n++;
  }

  return n;  // Devuelve el número de iteraciones en lugar de 0 o 1
}
