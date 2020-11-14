#ifndef GRAPHICS_H
#define GRAPHICS_H

#include<map>
#include<string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();

    /*SDL_Surface* loadImage
    * Loads the sprite png in our map if it doesn't exists. It then returns a pointer 
    * to this sprite from the map
    */
    SDL_Surface* loadImage(const std::string &filePath);

    /*! void blitSurface()
     * Draws texture over a part of the screen*/
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRect, SDL_Rect* targetRect);

    /* void flip
     * Renders Everything to Screen*/
    void flip();

    /*!void clear
     * Clears Screen*/
    void clear();

    //Basic getter for renderer
    SDL_Renderer* getRenderer();
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif