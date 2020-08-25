#pragma once
#include <SDL.h>

class Squares {
public:
    Squares(SDL_Renderer* renderer, int iterations, double scale, int x, int y, int size);

    void draw();

private:

    void square(int x, int y, int n, double size);

    SDL_Renderer* m_renderer;
    int m_x, m_y, m_iterations;
    double m_scale, m_size;
};