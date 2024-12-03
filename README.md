# Fract’ol

![Mandelbrot set colors](https://github.com/roma-sh/fract-ol/blob/master/images/julia_colors.gif)

## Introduction
Fractals are intricate structures that exhibit self-similarity across different scales.
The term "fractal" was first introduced by mathematician Benoit Mandelbrot in 1974, derived from the Latin word *fractus*, meaning "broken" or "fractured".
Fractals can be seen as abstract mathematical objects that manifest in various natural phenomena, such as the mesmerizing patterns of a romanesco cabbage.

![A real fractal image "romanesco cabbage"](https://github.com/roma-sh/fract-ol/blob/master/images/real_fract.jpg)

In this project, we explore the beauty of fractals through computer graphics, using the MLX42 library to render these captivating forms.

## Summary
This project involves creating graphically beautiful fractals, focusing on the Julia set and the Mandelbrot set. Through this endeavor, we'll become familiar with MLX42 library and gain insights into complex numbers and computer graphics optimization.

## Rendering
- This program offer:
  - The **Julia set** and the **Mandelbrot set**.
- Features include:
  - The mouse wheel zooms in and out, almost infinitely (within the limits of the computer), embodying the essence of fractals.
  - Different Julia sets can be created by passing varying parameters to the program.
  - Parameters can be passed on the command line to define which fractal will be displayed. If no or invalid parameters are provided, the program will display a list of available parameters and exit properly.
  -I Used a variety of colors to illustrate the depth of each fractal, enhancing the visual experience with psychedelic effects.

## Graphic Management
- This program can:
  - Display the image in a window using MLX42.
  - Maintain smooth management of the window (including switching to another window, minimizing, etc.).
  - Allow the user to close the window cleanly by pressing **ESC** or clicking the close button on the window's frame.

## Bonus Part
- Additional features were implemented:
  - The zoom follows the actual mouse position.
  - Enable movement of the view using the arrow keys.
  - Shift the color range by pressing the **space** key.

## Installation
Clone the repository:
   ```bash
   git clone https://github.com/roma-sh/fract-ol.git
   cd fractal
   ```

## Usage
   ```bash
   make
   ./fractol <parameters>
   ```

## Command-Line Options
- mandelbrot: Displays the Mandelbrot set.
- julia [real] [imaginary]: Displays the Julia set with the given real and imaginary parts.
  - If no parameters are provided, the program will display a list of available parameters.

## Example
   ```bash
   ./fractol mandelbrot
  ````
   ```bash
   ./fraactol julia -0.8 0.156
   ```

## Control
- Mouse Wheel: Zoom in and out of the fractal.
- Arrow Keys: Move the view left, right, up, or down.
- Space: Shift the color range for visual effects.
- ESC: Close the window and exit the program.
- Close Button: Click the close button on the window's frame to exit cleanly.

![Mandelbrot set](https://github.com/roma-sh/fract-ol/blob/master/images/mandelbrot.png)

![Julia set for fc, c = −0.8 + 0.156i](https://github.com/roma-sh/fract-ol/blob/master/images/julia.png)

![Julia set for fc, c = −0.4 + 0.6i](https://github.com/roma-sh/fract-ol/blob/master/images/julia2.png)
