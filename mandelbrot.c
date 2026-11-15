#include <stdio.h>

// Hard Mode: Terminal-based Mandelbrot Fractal Renderer
#define WIDTH 120
#define HEIGHT 45
#define MAX_ITER 120

int main() {
    // Complex plane ke boundaries
    double minX = -2.05;
    double maxX = 0.55;
    double minY = -1.15;
    double maxY = 1.15;

    printf("\x1b[2J\x1b[H"); // Terminal screen clear karna

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Pixel ko complex number c = c_re + i*c_im mein map karna
            double c_re = minX + (x / (double)WIDTH) * (maxX - minX);
            double c_im = minY + (y / (double)HEIGHT) * (maxY - minY);

            double z_re = 0.0;
            double z_im = 0.0;
            int iter = 0;

            // Mandelbrot iteration formula: z = z^2 + c
            while (z_re * z_re + z_im * z_im <= 4.0 && iter < MAX_ITER) {
                double z_re_new = z_re * z_re - z_im * z_im + c_re;
                z_im = 2.0 * z_re * z_im + c_im;
                z_re = z_re_new;
                iter++;
            }

            if (iter == MAX_ITER) {
                // Set ke andar ka hissa (Black/Deep space)
                printf("\x1b[40m  \x1b[0m");
            } else {
                // Iterations ke hisab se dynamic ANSI truecolor generate karna
                int r = (iter * 7) % 256;
                int g = (iter * 3) % 256;
                int b = (iter * 13) % 256;
                printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", r, g, b);
            }
        }
        printf("\n");
    }

    return 0;
}
