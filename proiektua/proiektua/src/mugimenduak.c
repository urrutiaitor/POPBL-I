#include"mugimenduak.h"

C actualizaControles ( C controls ) {
	if( SDL_PollEvent( &event ) ) {
		if ( event.type == SDL_KEYUP ) {
			if ( event.key.keysym.sym == SDLK_UP ) {
				controls.keyboard.Uarrow = FALSE;
			}
			if ( event.key.keysym.sym == SDLK_DOWN ) {
				controls.keyboard.Darrow = FALSE;
			}
			if ( event.key.keysym.sym == SDLK_LEFT ) {
				controls.keyboard.Larrow = FALSE;
			}
			if ( event.key.keysym.sym == SDLK_RIGHT ) {
				controls.keyboard.Rarrow = FALSE;
			}
			if ( event.key.keysym.sym == W ) {
				controls.keyboard.w = FALSE;
			}
			if ( event.key.keysym.sym == A ) {
				controls.keyboard.a = FALSE;
			}
			if ( event.key.keysym.sym == S ) {
				controls.keyboard.s = FALSE;
			}
			if ( event.key.keysym.sym == D ) {
				controls.keyboard.d = FALSE;
			}
			if ( event.key.keysym.sym == ENTER ) {
				controls.keyboard.intro = FALSE;
			}
		}
		if ( event.type == SDL_KEYDOWN ) {
			if ( event.key.keysym.sym == SDLK_UP ) {
				controls.keyboard.Uarrow = TRUE;
			}
			if ( event.key.keysym.sym == SDLK_DOWN ) {
				controls.keyboard.Darrow = TRUE;
			}
			if ( event.key.keysym.sym == SDLK_LEFT ) {
				controls.keyboard.Larrow = TRUE;
			}
			if ( event.key.keysym.sym == SDLK_RIGHT ) {
				controls.keyboard.Rarrow = TRUE;
			}
			if ( event.key.keysym.sym == W ) {
				controls.keyboard.w = TRUE;
			}
			if ( event.key.keysym.sym == A ) {
				controls.keyboard.a = TRUE;
			}
			if ( event.key.keysym.sym == S ) {
				controls.keyboard.s = TRUE;
			}
			if ( event.key.keysym.sym == D ) {
				controls.keyboard.d = TRUE;
			}
			if ( event.key.keysym.sym == ENTER ) {
				controls.keyboard.intro = TRUE;
			}
		}
	}
	return controls;
}

void kontrolakBistaratu ( C controls ) {
		system("cls");
		printf("Flecha arriba --> %i\n", controls.keyboard.Uarrow);
		printf("Flecha abajo --> %i\n", controls.keyboard.Darrow);
		printf("Flecha izquierda --> %i\n", controls.keyboard.Larrow);
		printf("Flecha derecha --> %i\n", controls.keyboard.Rarrow);
		printf("W --> %i\n", controls.keyboard.w);
		printf("A --> %i\n", controls.keyboard.a);
		printf("S --> %i\n", controls.keyboard.s);
		printf("D --> %i\n", controls.keyboard.d);
		printf("Enter --> %i\n", controls.keyboard.intro);
}