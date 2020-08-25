#include <iostream>
#include <SDL.h>
#include "Squares.h"
#include "Three.h"

#define HEIGTH 1000
#define WIDTH 1800

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event event;

void three(){
    const double delta = 0.25;

    int length,iterations;
    double scale;

    SDL_Delay(100);
    SDL_ShowWindow(window);

    Three three(renderer, WIDTH/2, HEIGTH*3/4, 300, 10, 0.5);
    double i=0,j=0;
    double dt = 0;
    uint32_t last = SDL_GetTicks();
    uint32_t now = last;

    bool autom = false;

    while(event.type != SDL_QUIT){
        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_UP)
                i += delta*dt;
            if(event.key.keysym.sym == SDLK_DOWN)
                i -= delta*dt;
            if(event.key.keysym.sym == SDLK_LEFT)
                j += delta*dt;
            if(event.key.keysym.sym == SDLK_RIGHT)
                j -= delta*dt;
            if(event.key.keysym.sym == SDLK_PAGEUP)
                three.changeScale(delta*dt);
            if(event.key.keysym.sym == SDLK_PAGEDOWN)
                three.changeScale(-delta*dt);
            if(event.key.keysym.sym == SDLK_EQUALS)
                three.changeStartLength(1);
            if(event.key.keysym.sym == SDLK_RIGHTPAREN)
                three.changeStartLength(-1);
            if(event.key.keysym.sym == SDLK_SPACE)
                autom = !autom;


        }else if(!autom){
            SDL_Delay(10);
            last = SDL_GetTicks();
            continue;
        }
        now = SDL_GetTicks();
        dt = (double)(now-last)/1000;
        last = now;

        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);

        three.draw(-i, -j);

        SDL_RenderPresent(renderer);

        if(autom){
            i -= delta*dt;
            j -= delta*dt / 10.0f;
        }
    }
}

void square(){
    SDL_ShowWindow(window);
    Squares sq(renderer, 6, 1.0/3, WIDTH/2, HEIGTH/2, HEIGTH);

    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    sq.draw();

    SDL_RenderPresent(renderer);

    while(event.type != SDL_QUIT){
        SDL_Delay(100);
        SDL_PollEvent(&event);
    }

}

int main() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGTH, SDL_WINDOW_HIDDEN, &window, &renderer);
    SDL_PollEvent(&event);



    int choice;
    while(choice != 0){
        std::cout << "Select your Fractal :\n";
        std::cout << "0: Exit\n";
        std::cout << "1: Colored Tree\n";
        std::cout << "2: Squares\n";
        std::cout << ">";
        std::cin >> choice;

        SDL_PollEvent(&event);

        if(choice == 1)
            three();
        else if(choice == 2)
            square();
        SDL_HideWindow(window);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
