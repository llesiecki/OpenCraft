#include "stdafx.h"
#include "game.h"

void SetupGLUT(int &argc, char** argv);

Game game;//global because of "C" compatibility for GLUT

int main(int argc, char* argv[])
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	SetupGLUT(argc, argv);
	return 0;
}

void OnTimerCallback(int id)
{
	glutTimerFunc(17, OnTimerCallback, 0);
	game.OnTimer(id);
}

void OnRenderCallback()
{
	game.OnRender();
}

void OnReshapeCallback(int width, int height)
{
	game.OnReshape(width, height);
}

void CursorPosUpdateCallback(int x, int y)
{
	game.CursorPosUpdate(x, y);
}

void MouseCallback(int button, int state, int x, int y)
{
	game.Mouse(button, state, x, y);
}

void SetupGLUT(int &argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(game.window_width, game.window_height);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(GAME_NAME);
	game.setHgameWindow(FindWindow(NULL, LGAME_NAME));
	glutWarpPointer(game.window_width >> 1, game.window_height >> 1);
	glutDisplayFunc(OnRenderCallback);
	glutReshapeFunc(OnReshapeCallback);
	glutPassiveMotionFunc(CursorPosUpdateCallback);
	glutTimerFunc(17, OnTimerCallback, 0);
	glutMouseFunc(MouseCallback);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LINE_SMOOTH);
	glShadeModel(GL_SMOOTH);
	glLineWidth(1.0f);
	glutMainLoop();
}