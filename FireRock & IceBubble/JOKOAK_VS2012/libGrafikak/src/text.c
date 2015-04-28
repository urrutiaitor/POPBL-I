#include "SDL_TTF.h"
#include "SDL.h"

//includes de la libreria
#include "NewTypes.h"
#include "graphics.h"
#include "imagen.h"

TTF_Font *font;

void initText(){
	font = TTF_OpenFontIndex("C:\\WINDOWS\\Fonts\\ARIAL.TTF", 16, 0);
	if (!font) {
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
}

void escribirTexto(int x, int y, char *str)
{
	SDL_Color color = { 200, 200, 200 };
	SDL_Surface *text_surface;
	SDL_Rect rect;
	if (!font) {
		printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
		// handle error
	}
	if (!(text_surface = TTF_RenderText_Solid(font, str, color))) {
		printf("Error al renderText\n.");
		//handle error here, perhaps print TTF_GetError at least
	}
	else {
		rect.x = x;
		rect.y = y;
		//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		SDL_BlitSurface(text_surface, NULL, screen, &rect);
		//perhaps we can reuse it, but I assume not for simplicity.
		SDL_FreeSurface(text_surface);

	}
}