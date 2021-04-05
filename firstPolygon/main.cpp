#include <SDL.h>
#include <SDL_opengl.h>
#include <FreeImage.h>
#include <iostream>
#include <GL/glu.h>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "There was an error\n";
		exit(1);
	}

	SDL_Window* win = SDL_CreateWindow("firstPolygon",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN  );
	SDL_GLContext context = SDL_GL_CreateContext(win);

	glClearColor(0.0, 0.0, 0.0, 1);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 640 / 480, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);

	SDL_Event event;

	do {
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		gluLookAt(0, 0, 6, 0, 0, 0, 0, 1, 0);


		glBegin(GL_TRIANGLES); // ------------------
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1.5,1,-6);
		glVertex3f(-2.5,-1,-6);
		glVertex3f(-0.5,-1,-6);
		glEnd(); // --------------------------------

		glBegin(GL_QUADS); // ------------------
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5,1,-6);
		glVertex3f(2.5,1,-6);
		glVertex3f(2.5,-1,-6);
		glVertex3f(0.5,-1,-6);
		glEnd(); // ----------------------------

		/* Luego de la translación de matriz el triángulo queda superpuesto */

		glTranslatef(-1.5, 0, -6);

		glBegin(GL_TRIANGLES); // ------------------
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0,1,0);
		glVertex3f(-1,-1,0);
		glVertex3f(1,-1,0);
		glEnd(); // --------------------------------

		/* Luego de la translación de matriz el cuadrado queda superpuesto */

		glTranslatef(3, 0, 0);

		glBegin(GL_QUADS); // ------------------
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(-1,1,0);
		glVertex3f(1,1,0);
		glVertex3f(1,-1,0);
		glVertex3f(-1,-1,0);
		glEnd(); // ----------------------------


		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				return 0;
			}
		}
		SDL_GL_SwapWindow(win);
	} while (true);

	return 0;

}

