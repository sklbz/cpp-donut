#include <cmath>
#include <cstdio>
#include <cstring>

int k;
double sin(), cos();
int main() {
  float A = 0, B = 0, i, j, z[1760], size = 2, t_modifier = 1;
  char b[1760];
  printf("\x1b[2J");
  while (1) {
    memset(b, 32, 1760);
    memset(z, 0, 7040);
    for (j = 0; 6.28 > j; j += 0.07) {
      for (i = 0; 6.28 > i; i += 0.02) {
        float sini = sin(i), cosj = cos(j), sinA = sin(A), sinj = sin(j),
              cosA = cos(A), cosj2 = cosj + 2,
              mess = size / (sini * cosj2 * sinA + sinj * cosA + 5),
              cosi = cos(i), cosB = cos(B), sinB = sin(B),
              t = (sini * cosj2 * cosA - sinj * sinA) * t_modifier;
        int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB),
            y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
            o = x + 80 * y,
            N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB -
                     sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);
        if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o]) {
          z[o] = mess;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
      }
    }
    printf("\x1b[d");
    for (k = 0; 1761 > k; k++)
      putchar(k % 80 ? b[k] : 10);
    A += 0.04;
    B += 0.02;
  }
  return 0;
}
