#include "Tree2.h"
#include <math.h>

Tree2::Tree2(SDL_Renderer* renderer, int startX, int startY, int startLength, int iterations, double scale, int n_branches)
        : m_renderer(renderer), m_length(startLength), m_y(startY), m_x(startX),
          m_iterations(iterations), m_scale(scale), m_n_branches(n_branches)
{

}

void Tree2::draw(double number) {
    for(int i=0; i<m_n_branches; i++){
        m_draw(m_x, m_y, m_length, m_iterations, number / (i*2 + 1), number);
    }
}

void Tree2::m_draw(int x, int y, int length, int n, double angle, double number) {
    if(n == 0)
        return;

    int x2 = x,y2 = y;

    x2 += sin(angle)*length;
    y2 += -cos(angle)*length;

    SDL_SetRenderDrawColor(m_renderer, 255,255,255,255);
    SDL_RenderDrawLine(m_renderer, x, y, x2, y2);

    for(int i=0; i<m_n_branches; i++)
        m_draw(x2, y2, length*m_scale, n-1, angle + (number/(i*2+1)), number);
}