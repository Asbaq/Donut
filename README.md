# 📜 Game Documentation: Donut 🎮

## 📌 Game Title: Donut  
![Donut](https://github.com/Asbaq/Donut/assets/62818241/3474d09a-cbb9-453e-b6c3-c87613c170e0)

## 🎨 Art Style
The game features a **text-based ASCII art style**, rendering a rotating **3D torus (donut)** in the terminal. The visuals are created using mathematical calculations to project the 3D shape onto a 2D text-based display. The shading is achieved using ASCII characters, giving the illusion of depth and rotation.

---

## 📖 Game Overview
**Donut** is a **terminal-based ASCII graphics demo** that simulates a rotating 3D donut using mathematical transformations. It continuously updates and redraws the torus using trigonometric functions to create an animated effect.

### 🎯 Objectives
- Display a **rotating 3D donut** using ASCII characters.
- Implement **real-time shading** based on depth calculations.
- Utilize **trigonometric functions** to achieve realistic rotation effects.

---

## 🎮 Game Mechanics

### 🖼️ ASCII Rendering
- The donut is generated using **sine and cosine functions** to simulate 3D rotation.
- A **depth buffer** is used to determine which parts of the donut are visible.
- ASCII characters (`.,-~:;=!*#$@`) are used to represent different shading levels.

### 🎮 Animation Loop
- The torus continuously **rotates** along the X and Z axes.
- The frame updates dynamically by clearing the screen and redrawing the donut.
- **Frame delay** (`usleep(50000)`) creates a smooth animation effect.

---

## 🛠️ Script Documentation

### 🎮 **Donut.c**
The main program file that generates the **rotating 3D donut**.

```c
#include<stdio.h>
#include <math.h>
#include <unistd.h>

int main() {
    // Initializing Variables
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];

    for(;;) {
        // Setting default values in buffers
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        // Looping through angles to generate 3D effect
        for(j=0; j < 6.28; j += 0.07) {
            for(i=0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;

                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        // Printing donut in loop
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        usleep(50000); // Delay to control animation speed
    }
    return 0;
}
```

---

## 🏗️ Features & Future Improvements

✅ **ASCII-based 3D rendering**  
✅ **Real-time shading with depth buffer**  
✅ **Smooth rotation using trigonometric calculations**  
🔜 **Customizable ASCII characters for enhanced visual effects**  
🔜 **User input for rotation speed and angle adjustments**  
🔜 **Multi-threading support for optimized performance**  

---

## 📌 Conclusion
**Donut** is a fun and mesmerizing **ASCII animation** that showcases the power of mathematical transformations to simulate 3D objects in a text-based environment. Using **trigonometry, depth buffers, and ASCII shading**, the program creates an engaging visual effect of a continuously rotating torus. Future updates may bring **customization options, user controls, and performance improvements**. 🚀🎮


