#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0; // Rotation angles
    float i, j; // Loop variables
    int k; // Loop variable
    float z[1760]; // Depth buffer
    char b[1760]; // Frame buffer
    printf("\x1b[2J"); // Clear the console
    for(;;) { // Infinite loop for animation
        memset(b, 32, 1760); // Clear frame buffer with spaces
        memset(z, 0, 7040); // Clear depth buffer with zeros
        for(j = 0; j < 6.28; j += 0.07) { // Loop through angles
            for(i = 0; i < 6.28; i += 0.02) { // Loop through angles
                float c = sin(i); // Precompute sine
                float d = cos(j); // Precompute cosine
                float e = sin(A); // Precompute sine of rotation angle A
                float f = sin(j); // Precompute sine
                float g = cos(A); // Precompute cosine of rotation angle A
                float h = d + 2; // Precompute depth factor
                float D = 1 / (c * h * e + f * g + 5); // Precompute projection factor
                float l = cos(i); // Precompute cosine
                float m = cos(B); // Precompute cosine of rotation angle B
                float n = sin(B); // Precompute sine of rotation angle B
                float t = c * h * g - f * e; // Precompute depth factor
                int x = 40 + 30 * D * (l * h * m - t * n); // Calculate screen coordinates
                int y = 12 + 15 * D * (l * h * n + t * m); // Calculate screen coordinates
                int o = x + 80 * y; // Calculate index in frame buffer
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n); // Calculate shading index
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) { // Check if pixel is visible
                    z[o] = D; // Update depth buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0]; // Update frame buffer with shading character
                }
            }
        }
        printf("\x1b[H"); // Move cursor to home position
        for(k = 0; k < 1761; k++) { // Loop through frame buffer
            putchar(k % 80 ? b[k] : 10); // Output character to console
            A += 0.00004; // Increment rotation angle A
            B += 0.00002; // Increment rotation angle B
        }
        usleep(30000); // Pause for smooth animation
    }
    return 0; // Return success
}
