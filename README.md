*This project has been created as part of the 42 curriculum by naratass*

## Description
Fract-ol is graphic project. Main objective is to render a fractol image on a screen by usgin graphic library via minilibx. This project require knowledge about fractol formula and optimization

## Instruction

### List of command in program:

Makefile command:

```bash
make        # compile a program
make clean  # remove all object file (.o)
make fclean # remove all object file and executable file.
make re     # re-compile a program
```

### Quick start

This project offer you 2 types of fractol-mandelbrot set and julia set.

To run a program, after clone the project, go inside and make program. Run command below

#### Option 1:

`./fractol julia # To render julia set`

#### Option 2:

`./fractol mandelbrot # To render mandelbrot set`

## Resource and others

### About fractol and Minilibx
- https://harm-smits.github.io/42docs/libs/minilibx
- https://complex-analysis.com/content/mandelbrot_set.html
- https://mandelbrot.site/
### Reference repository
- https://github.com/leogaudin/fract-ol

## Optimization
For this project, I use 2 technique to help my code render faster.
1. Hard code color -  Instead of calculate gradiant of color for each iterative. I store color in array and call it when need to color a pixel. *Credit to https://github.com/wxsonz
2. Low-resolution pass via successive refinement. Instead of calculate every pixel. I calculate one pixel and next n pixel will have the same value. First I start from scale 16x16 pixel render and reduce to 8x8, 4x4, 2x2, and 1x1. This technique create illusion that make user feel like program run faster. 
- https://stackoverflow.com/questions/13693514/how-would-you-continuously-improve-the-mandelbrot-fractal

## Ai usage
Ai was use to help debugging and give me an idea for optimization
