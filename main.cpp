#include <SDL.h>
#include <stdio.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


bool loadMedia(){
    bool success=true;
    gHelloWorld = SDL_LoadBMP("assets/faces.png" );
    if(gHelloWorld == NULL){
        printf("UNABLE TO LOAD PICTURE");
        success=false;
    }
    return success;
}
int main( int argc, char* args[] ) {

    //Starts up SDL and creates window
    bool init();
    //Loads media
    bool loadMedia();

    //Frees media and shuts down SDL
    void close();



    //The window we'll be rendering to
    SDL_Window* window = NULL;
    // The surface contained by the window
    SDL_Surface* screenSurface = NULL; //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else { //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else { //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
            //Fill the surface white

            if(!loadMedia()){
                printf("couldnt load media");
                return -1;
            }
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            //Update the surface

            SDL_UpdateWindowSurface( window );
            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }
    //Destroy window
    SDL_DestroyWindow( window );
    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}