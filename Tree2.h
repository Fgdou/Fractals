#pragma once
#include <SDL.h>

class Tree2 {
public:
    Tree2(SDL_Renderer* renderer, int startX, int startY, int startLength, int iterations, double scale, int n_branches);

    void draw(double number);
private:

    void m_draw(int x, int y, int length, int n, double angle, double number);

    int m_x,m_y,m_length;

    int m_n_branches;
    double m_scale;
    int m_iterations;
    SDL_Renderer* m_renderer;
};
