//
// Created by fgdou on 14/07/2020.
//

#include "Squares.h"

Squares::Squares(SDL_Renderer* renderer, int iterations, double scale, int x, int y, int size)
    : m_renderer(renderer), m_size(size), m_x(x), m_y(y), m_iterations(iterations), m_scale(scale)
{

}

void Squares::square(int x, int y, int n, double size) {
    if(n == 0)
        return;

    int d = size*1.0/6;

    SDL_Rect black = {
            x-d, y-d,
            d*2, d*2
    };

    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);
    SDL_RenderFillRect(m_renderer, &black);

    square(x-2*d, y-2*d, n-1, size*m_scale);
    square(x-2*d, y, n-1, size*m_scale);
    square(x-2*d, y+2*d, n-1, size*m_scale);
    square(x, y-2*d, n-1, size*m_scale);
    square(x, y+2*d, n-1, size*m_scale);
    square(x+2*d, y-2*d, n-1, size*m_scale);
    square(x+2*d, y, n-1, size*m_scale);
    square(x+2*d, y+2*d, n-1, size*m_scale);
}

void Squares::draw() {
    int x = m_x;
    int y = m_y;
    double size = m_size;
    int n = m_iterations;

    SDL_Rect white = {
            (int)(x-size/2),
            (int)(y-size/2),
            (int)(size),
            (int)(size)
    };
    SDL_SetRenderDrawColor(m_renderer, 255,0,0,255);
    SDL_RenderFillRect(m_renderer, &white);

    square(x,y,n,size);
}
