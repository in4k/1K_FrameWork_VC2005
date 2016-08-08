/*
	Re-use granted as long as long as you give credit in
	either your demo or accompanying files please...(auld)

	Thanks go to Icehawk for WS_MAXIMIZE optimisation and the idea
	how to get rid of Peekmessage
	The following code sets up an Opengl window under win32
	It is double buffered, hides the mouse, has 32 bits of depth/Z.
	The main loop includes a clear for depth and color bits and 
	a swapbuffers call for drawing.
	It exits when escape is pressed...
	Tested under XP.
*/

/*
	Visual C++ 2005 Express project version
				by rbraz - 2006

	[16/12/2007] Updated by AxON:
	-Removed "msvcrt" library dependency
	-Added new mode to initialize pixel format descriptor
	-New com dropper config:
		dropper /o2 /c3 /n /m1 /p1 Tiny_OGL.exe
	
	Final file compress to 396 bytes
*/

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

//extern "C" unsigned int _fltused=0; // turn on, when use float

//----------------------------------------------------------------

//PIXELFORMATDESCRIPTOR pfd={sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0}; // right way to init pfd
PIXELFORMATDESCRIPTOR pfd={0, 0, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // wrong way ;)

//----------------------------------------------------------------

void WinMainCRTStartup()
{              
	// create window	
	HDC hDC = GetDC(CreateWindow("edit", 0, WS_POPUP | WS_VISIBLE | WS_MAXIMIZE, 0, 0, 0, 0, 0, 0, 0, 0));         
	ShowCursor(false);

	// init OpenGL
	SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);
	wglMakeCurrent(hDC, wglCreateContext(hDC));

	// main loop
	do {
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		// render intro here

		SwapBuffers(hDC); 		
	} while (!GetAsyncKeyState(VK_ESCAPE));
}
