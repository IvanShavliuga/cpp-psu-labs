
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include "SeeWar.h"
#include <win\mmsystem.h>
//����������� ����������
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glu32.lib")
//����������� ���������� ��� ������ � OpenGL
HDC hDC = NULL;                 // ������� �������� ���������� GDI
HGLRC hRC = NULL;               // ���������� �������������� ���������
HWND hwnd = NULL;               // ������ ���� ����� ����
HINSTANCE hInstance;            // ������ ������ ����������

BOOL g_fKeys[256];              // ������ �������������� ��� ��������� ���������
BOOL g_fActive = TRUE;          // �������� ���� ���� ������������� � ������ �� ���������

GLfloat z = -10.0f;             // Depth Into The Screen

GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLuint filter;                  // ����� ������, ����� ������������
GLuint texture[3];              // �������� ��� 3 �������
GLuint object = 1;              // ����� ������ ������ ������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   // ��������� ������ Windows
//���������� ��� "�������� ���"
int Player1[10][10],Player2[10][10];//������������ �������� � �� ���������
/*0 -������� (� ��� �� ��������
  1 -������� (����� �������) ��������������
  10 - ������������� �������
  11 - ������������ �������
*/
int X,Y; //���������� �������� (� ������ ���� ��������?)
int player; //����� ����� ������ ������
char password1[10],password2[10]; //������ �������
char buffer[10];	//��� �����
int DeathP1,DeathP2; //���-�� ������ � ������� � ������� ������
int HodP1,HodP2;//��������� ��� �������, � ��� ���

//������� ��������������� ��� �������� ���
void ClearBoards(); //������� ����� �������
void Feur();        //�������
void CreateBoards();//�������������� �������� ����� �������

static AUX_RGBImageRec *LoadBMP(char *Filename)
{
    if (Filename)  //���� ��� ����� ��������
    {
        FILE *fp = fopen(Filename, "r");
        if (fp) //���� ���� ����������
        {
            fclose(fp); //��������� �����������
            return auxDIBImageLoad(Filename);
        }
    }

    return NULL;
}


static BOOL LoadGLTextures(void)
{
    BOOL fStatus = FALSE;
    
    AUX_RGBImageRec *TextureImage[1];


    memset(TextureImage, 0, sizeof(void *)*1);

    // ��������� ��������� �����������, 
	// ���������� �� ������� ������, 
	//���� ��������� ����������� �� ������������ �����
    if ((TextureImage[0] == LoadBMP("background.bmp")))
    {
        fStatus = TRUE;

        // �������� �������
        glGenTextures(3, &texture[0]);
		//����������� ��������
        //�������� ��������� ��������������� �������� 
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

        // �������� �������� ��������������� ��������
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);

        
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
    }

    if (TextureImage[0])
    {
        if (TextureImage[0]->data)
            free(TextureImage[0]->data);

        free(TextureImage[0]);
    }

    return fStatus;
}

//�������� ������� ����
static GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
	//��������� ����
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // ��������� ��������� ��������� ����� � ������ ����
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//������������� ����
static int InitGL(GLvoid)
{
    if (!LoadGLTextures())  //������� ��� -- �����
        return FALSE;

    glEnable(GL_TEXTURE_2D); //��������� ��������� ��������
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);   
    glClearDepth(1.0f);                                     // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                                // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                                 // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);      // Really Nice Perspective Calculations

    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);         // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);         // Setup The Diffuse Light
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);        // Position The Light
    glEnable(GL_LIGHT1);                                    // Enable Light One

    
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);    // Set The Texture Generation Mode For S To Sphere Mapping (NEW)
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);    // Set The Texture Generation Mode For T To Sphere Mapping (NEW)

    return TRUE;
}

//������� ��������� �������� ����
static GLvoid glDrawBoard(void)
{  
	int x,y;
	glPushMatrix();
    glBegin(GL_QUADS);
    glNormal3f(0.0f,0.0f,1.0f);   	 
	//��������� ���� ������� ������ 			
	for(y=0; y<10; y++)
	{
		for(x=0; x<10; x++)
		{
			switch(Player1[x][y])
			{
				case 0://�����
					glColor3f(0.1f,0.1f,0.7f);
					break;
				case 1://����� �������
					if(player==1) glColor3f(0.8f,0.9f,0.7f);
					else          glColor3f(0.1f,0.1f,0.7f);
					break;
				case 10://����
					glColor3f(0.5f,0.50f,1.0f);
					break;
				case 11://������
					glColor3f(1.0f,0.0f,0.0f);
					break;
			}
			glVertex3f(-0.25f-(9-x+1)*0.5,  0.25f+(y-2)*0.5,  0.0f);
    	    glVertex3f(-0.25f-(9-x+1)*0.5, -0.25f+(y-2)*0.5,  0.0f);
  		    glVertex3f( 0.25f-(9-x+1)*0.5, -0.25f+(y-2)*0.5,  0.0f);
  		  	glVertex3f( 0.25f-(9-x+1)*0.5,  0.25f+(y-2)*0.5,  0.0f);
    		
    
		}
    }
	glEnd();
	//��������� ���� ������� ������
	glBegin(GL_QUADS);
    glNormal3f(0.0f,0.0f,1.0f);   	  			
	for(y=0; y<10; y++)
	{
		for(x=0; x<10; x++)
		{
			switch(Player2[x][y])
			{
				case 0:
					glColor3f(0.1f,0.1f,0.7f);
					break;
				case 1:
					if(player==2) glColor3f(0.8f,0.9f,0.7f);
					else          glColor3f(0.1f,0.1f,0.7f);
					break;
				case 10:
					glColor3f(0.5f,0.5f,1.0f);
					break;
				case 11:
					glColor3f(1.0f,0.0f,0.0f);
					break;
			}
			glVertex3f(-0.25f+(x+1)*0.5,  0.25f+(y-2)*0.5,  0.0f);
    	    glVertex3f(-0.25f+(x+1)*0.5, -0.25f+(y-2)*0.5,  0.0f);
  		    glVertex3f( 0.25f+(x+1)*0.5, -0.25f+(y-2)*0.5,  0.0f);
  		  	glVertex3f( 0.25f+(x+1)*0.5,  0.25f+(y-2)*0.5,  0.0f);
    		
    
		}
    }
	glEnd();
	glPopMatrix();
	//�������
	if(player==2)
	{
		glColor3f(0.0f,1.0f,0.0f);
		glBegin(GL_QUADS);
    	glNormal3f(0.0f,0.0f,1.0f);
		glVertex3f(-0.25f-(9-X+1)*0.5,  0.25f+(Y-2)*0.5,  0.0f);
    	glVertex3f(-0.25f-(9-X+1)*0.5, -0.25f+(Y-2)*0.5,  0.0f);
  		glVertex3f( 0.25f-(9-X+1)*0.5, -0.25f+(Y-2)*0.5,  0.0f);
  		glVertex3f( 0.25f-(9-X+1)*0.5,  0.25f+(Y-2)*0.5,  0.0f);
    	glEnd();
		
	}
	if(player==1)
	{
		glColor3f(0.0f,1.0f,0.0f);
		glBegin(GL_QUADS);
    	glNormal3f(0.0f,0.0f,1.0f);
		glVertex3f(-0.25f+(X+1)*0.5,  0.25f+(Y-2)*0.5,  0.0f);
    	glVertex3f(-0.25f+(X+1)*0.5, -0.25f+(Y-2)*0.5,  0.0f);
  		glVertex3f( 0.25f+(X+1)*0.5, -0.25f+(Y-2)*0.5,  0.0f);
  		glVertex3f( 0.25f+(X+1)*0.5,  0.25f+(Y-2)*0.5,  0.0f);
    	glEnd();
		
	}
}

//��������� � OpenGL
static int DrawGLScene(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, z);
  	 

	glDrawBoard();

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

    glBindTexture(GL_TEXTURE_2D, texture[0]);            // This Will Select The BG Maps...
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -24.0f);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-13.3f, -10.0f,  10.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 13.3f, -10.0f,  10.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 13.3f,  10.0f,  10.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-13.3f,  10.0f,  10.0f);
    glEnd();
    glPopMatrix();
	return TRUE;  
}
//����������� OpenGl ����
static GLvoid KillGLWindow(GLvoid)
{
    
    if (hRC)
    {
        if (!wglMakeCurrent(NULL, NULL))
            MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK|MB_ICONINFORMATION);

        if (!wglDeleteContext(hRC))
            MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK|MB_ICONINFORMATION);

        hRC = NULL;
    }

    if (hDC && !ReleaseDC(hwnd, hDC))
    {
        MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK|MB_ICONINFORMATION);
        hDC = NULL;
    }

    if (hwnd && !DestroyWindow(hwnd))
    {
        MessageBox(NULL, "Could Not Release hwnd.", "SHUTDOWN ERROR", MB_OK|MB_ICONINFORMATION);
        hwnd = NULL;
    }

    if (!UnregisterClass("OpenGL", hInstance))
    {
        MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK|MB_ICONINFORMATION);
        hInstance = NULL;
    }
}

//�������� ����     � ����������  ,  �������    �������   ????        ������ �������
BOOL CreateGLWindow(char* title, int width, int height, int bits, BOOL fullscreenflag)
{
    static PIXELFORMATDESCRIPTOR pfd = {0};
    GLuint PixelFormat;     // Holds The Results After Searching For A Match
    WNDCLASS wc;            // Windows Class Structure
    DWORD dwExStyle;        // Window Extended Style
    DWORD dwStyle;          // Window Style
    RECT rcWindow;
	//������ ����� rcWindow	
    SetRect(&rcWindow, 0, 0, width, height);

    //���������� ��� ������� � Windows
    hInstance = GetModuleHandle(NULL);
	//����� ����
    wc.style = CS_HREDRAW|CS_VREDRAW|CS_OWNDC;
	//����������� ������� ��������� ������ Windows
    wc.lpfnWndProc  = (WNDPROC)WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
	//������ � ����
    wc.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(MAINICON));   
	//������ � ���� IDC_ARROW -- �������
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName = NULL;
	//��� ������
    wc.lpszClassName = "OpenGL";

    // ������������ ��, ��� ���������� �����
    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }
	
 	   
    dwExStyle = WS_EX_APPWINDOW|WS_EX_WINDOWEDGE;
    dwStyle = WS_OVERLAPPEDWINDOW;
    

    // Adjust Window To True Requested Size.
    AdjustWindowRectEx(&rcWindow, dwStyle, FALSE, dwExStyle);

    // ������ ����� ������� ����.
    if (!(hwnd = CreateWindowEx(dwExStyle, "OpenGL", title, dwStyle|WS_CLIPSIBLINGS|WS_CLIPCHILDREN,
        0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top, NULL, NULL, hInstance, NULL)))
    {
        KillGLWindow();  // ������� ����
        MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = bits;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    if (!(hDC = GetDC(hwnd)))  /* Did We Get A Device Context? */
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))  /* Did Windows Find A Matching Pixel Format? */
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    if(!SetPixelFormat(hDC,PixelFormat,&pfd))  /* Are We Able To Set The Pixel Format? */
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    if (!(hRC = wglCreateContext(hDC)))  /* Are We Able To Get A Rendering Context? */
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    if(!wglMakeCurrent(hDC,hRC))  /* Try To Activate The Rendering Context */
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    ShowWindow(hwnd, SW_SHOW);
    SetForegroundWindow(hwnd);      // Slightly Higher Priority
    SetFocus(hwnd);                 // Sets Keyboard Focus To The Window
    ReSizeGLScene(width, height);   // Set Up Our Perspective GL Screen

    // ������������� OpenGL
    if (!InitGL())
    {
        KillGLWindow();  // Reset The Display
        MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK|MB_ICONEXCLAMATION);
        return FALSE;
    }

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_ACTIVATE:  /* �������� ����? */
        {
            g_fActive = !HIWORD(wParam);

            if(player==1)
				SetDlgItemText(hwnd,LABEL,"������ �����, ������� ������");
			else
				SetDlgItemText(hwnd,LABEL,"������ �����, ������� ������");
	
			return 0;
        }

        case WM_SYSCOMMAND:  /* Intercept System Commands */
        {
            switch (wParam)  /* Check System Calls */
            {
                case SC_SCREENSAVE:     // Screensaver Trying To Start?
                case SC_MONITORPOWER:   // Monitor Trying To Enter Powersave?
                return 0;               // Prevent From Happening
            }
            break;
        }
		case WM_COMMAND:
            switch (GET_WM_COMMAND_ID(wParam, lParam))
            {
                case IDOK://������ ������ "��"
					//������ �������� ������ � �������� � password
					GetDlgItemText(hwnd,EDITBOX,buffer,10);
					//������� ���������� ����
            		EndDialog(hwnd, TRUE);
					return TRUE;
            }
            break;

        case WM_CLOSE:  /* Did We Receive A Close Message? */
        {
                PostQuitMessage(0);
                EndDialog(hwnd, TRUE);
                return 0;
        }

        case WM_KEYDOWN:  /* Is A Key Being Held Down? */
        {
                g_fKeys[wParam] = TRUE;
                return 0;
        }

        case WM_KEYUP:  /* Has A Key Been Released? */
        {
                g_fKeys[wParam] = FALSE;
                return 0;
        }

        case WM_SIZE:  /* Resize The OpenGL Window */
        {
            ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
            return 0;
        }
    }

    // Pass All Unhandled Messages To DefWindowProc.
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
void ClearBoards()
{
	int x, y;
	for(y=0; y<10; y++)
	{
		for(x=0; x<10; x++)
		{
			Player1[x][y]=0;
			Player2[x][y]=0;
		}
	}
	
	HodP1=HodP2=X=Y=DeathP1=DeathP2=player=0;
}
void Feur()
{
	//������ ����� �������� �� �������� �������
	// PlaySound(MAKEINTRESOURCE(IDR_WAV_DING),hInstance,SND_RESOURCE|SND_ASYNC);
	if(player==1) 
	{
		if(Player2[X][Y]<10) Player2[X][Y]+=10;
		if(Player2[X][Y]==11) 
		{	//������ ����
			// PlaySound(MAKEINTRESOURCE(IDR_WAV_DING),hInstance, SND_RESOURCE|SND_ASYNC);
			DeathP2++;
		}
	}
	else
	{
		if(Player1[X][Y]<10) Player1[X][Y]+=10;
		if(Player1[X][Y]==11)
		{
			// PlaySound(MAKEINTRESOURCE(IDR_WAV_DING),hInstance,SND_RESOURCE|SND_ASYNC);
			DeathP1++;
			
		}
	}
	
}
int Proverka(int x, int y)
{
	int f=1;
	if(player==1)
	{
		if(Player1[x][y]!=1)
		{
			if(x>0&&y>0)
				if(Player1[x-1][y-1]!=1&&Player1[x-1][y]!=1&&
					Player1[x][y-1]!=1&&Player1[x+1][y-1]!=1&&
					Player1[x+1][y]!=1&&Player1[x-1][y+1]!=1&&
					Player1[x][y+1]!=1&&Player1[x+1][y+1]!=1)
					f=0;
			if(x==0&&y>0)
				if( Player1[x][y-1]!=1&&Player1[x+1][y-1]!=1&&
					Player1[x+1][y]!=1&&Player1[x][y+1]!=1&&
					Player1[x+1][y+1]!=1)
					f=0;
			if(x==9&&y>0)
				if(Player1[x-1][y-1]!=1&&Player1[x-1][y]!=1&&
					Player1[x][y-1]!=1&&Player1[x-1][y+1]!=1&&
					Player1[x][y+1]!=1)
					f=0;
			if(x>0&&y==0)
				if(Player1[x-1][y]!=1&&Player1[x+1][y]!=1&&
					Player1[x-1][y+1]!=1&&Player1[x][y+1]!=1&&
					Player1[x+1][y+1]!=1)
					f=0;
			if(x>0&&y==9)
				if(Player1[x-1][y-1]!=1&&Player1[x-1][y]!=1&&
					Player1[x][y-1]!=1&&Player1[x+1][y-1]!=1&&
					Player1[x+1][y]!=1)
					f=0;
		}//if
	}//if player==1
	if(player==2)
	{
		if(Player2[x][y]!=1)
		{
			if(x>0&&y>0)
				if(Player2[x-1][y-1]!=1&&Player2[x-1][y]!=1&&
					Player2[x][y-1]!=1&&Player2[x+1][y-1]!=1&&
					Player2[x+1][y]!=1&&Player2[x-1][y+1]!=1&&
					Player2[x][y+1]!=1&&Player2[x+1][y+1]!=1)
					f=0;
			if(x==0&&y>0)
				if( Player2[x][y-1]!=1&&Player2[x+1][y-1]!=1&&
					Player2[x+1][y]!=1&&Player2[x][y+1]!=1&&
					Player2[x+1][y+1]!=1)
					f=0;
			if(x==9&&y>0)
				if(Player2[x-1][y-1]!=1&&Player2[x-1][y]!=1&&
					Player2[x][y-1]!=1&&Player2[x-1][y+1]!=1&&
					Player2[x][y+1]!=1)
					f=0;
			if(x>0&&y==0)
				if(Player2[x-1][y]!=1&&Player2[x+1][y]!=1&&
					Player2[x-1][y+1]!=1&&Player2[x][y+1]!=1&&
					Player2[x+1][y+1]!=1)
					f=0;
			if(x>0&&y==9)
				if(Player2[x-1][y-1]!=1&&Player2[x-1][y]!=1&&
					Player2[x][y-1]!=1&&Player2[x+1][y-1]!=1&&
					Player2[x+1][y]!=1)
					f=0;
		}//if
	}//if player==2
	return f;
}
void CreateBoards()
{
	int x,y,i,j,f,status;
	//������������
	for(i=0; i<4; i++)
	{
		f=1;
		while(f)
		{	
			x=rand()%10; 
			y=rand()%10;
			f=Proverka(x,y);
			if(!f) 
			{
				if(player==1) Player1[x][y]=1;
				if(player==2) Player2[x][y]=1;
			}
		}//while f==1
		
	}//for
	//�����������
	for(i=0; i<3; i++)
	{
		f=1;
		while(f)
		{	
			status=rand()%2;//0-��������� 1-�����������
			if(!status) //���������
			{
				x=rand()%10; //����������
				y=rand()%9;
			}
			else //�����������
			{
				x=rand()%9;
				y=rand()%10;
			}
			if(!status) //���������
				if(Proverka(x,y)==0&&Proverka(x,y+1)==0)
				{
					if(player==1) Player1[x][y]=Player1[x][y+1]=1;
					if(player==2) Player2[x][y]=Player2[x][y+1]=1;
					f=0;
				}		
			if(status) //�����������
				if(Proverka(x,y)==0&&Proverka(x+1,y)==0)
				{
					if(player==1) Player1[x][y]=Player1[x+1][y]=1;
					if(player==2) Player2[x][y]=Player2[x+1][y]=1;
					f=0;
				}
		}//while f==1
		
	}//for
	//������������
	for(i=0; i<2; i++)
	{
		f=1;
		while(f)
		{	
			status=rand()%2;//0-��������� 1-�����������
			if(!status) //���������
			{
				x=rand()%10; //����������
				y=rand()%8;
			}
			else //�����������
			{
				x=rand()%8;
				y=rand()%10;
			}
			if(!status) //���������
				if(Proverka(x,y)==0&&Proverka(x,y+1)==0&&
					Proverka(x,y+2)==0)
				{
					if(player==1) Player1[x][y]=Player1[x][y+1]=Player1[x][y+2]=1;
					if(player==2) Player2[x][y]=Player2[x][y+1]=Player2[x][y+2]=1;
					f=0;
				}		
			if(status) //�����������
				if(Proverka(x,y)==0&&Proverka(x+1,y)==0&&
					Proverka(x+2,y)==0)
				{
					if(player==1) Player1[x][y]=Player1[x+1][y]=Player1[x+2][y]=1;
					if(player==2) Player2[x][y]=Player2[x+1][y]=Player2[x+2][y]=1;
					f=0;
				}
		}//while f==1
		
	}//for
	f=1;
	while(f)
	{	
		status=rand()%2;//0-��������� 1-�����������
		if(!status) //���������
		{
			x=rand()%10; //����������
			y=rand()%7;
		}
		else //�����������
		{
			x=rand()%7;
			y=rand()%10;
		}
		if(!status) //���������
			if(Proverka(x,y)==0&&Proverka(x,y+1)==0&&
				Proverka(x,y+2)==0&&Proverka(x,y+3)==0)
			{
				if(player==1) Player1[x][y]=Player1[x][y+1]=Player1[x][y+2]=Player1[x][y+3]=1;
				if(player==2) Player2[x][y]=Player2[x][y+1]=Player2[x][y+2]=Player2[x][y+3]=1;
				f=0;
			}		
		if(status) //�����������
			if(Proverka(x,y)==0&&Proverka(x+1,y)==0&&
				Proverka(x+2,y)==0&&Proverka(x+3,y)==0)
			{
				if(player==1) Player1[x][y]=Player1[x+1][y]=Player1[x+2][y]=Player1[x+3][y]=1;
				if(player==2) Player2[x][y]=Player2[x+1][y]=Player2[x+2][y]=Player2[x+3][y]=1;
				f=0;
			}
	}//while f==1
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    BOOL fDone = FALSE;
    MSG msg;

    // Create Our OpenGL Window.
    if (!CreateGLWindow("������� ���", 640, 480, 16, FALSE))
        return 0;
	ClearBoards();
	player=1;
	DialogBox(hInstance, MAKEINTRESOURCE(INPUTBOX), NULL, (DLGPROC)WndProc);
	CreateBoards();
	strcpy(password1,buffer);
	player=2;
	DialogBox(hInstance, MAKEINTRESOURCE(INPUTBOX), NULL, (DLGPROC)WndProc);
	CreateBoards();
	strcpy(password2,buffer);
	player=1;	
    while (!fDone)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))  /* Is There A Message Waiting? */
        {
            if (msg.message == WM_QUIT)  /* Have We Received A Quit Message? */
            {
                fDone = TRUE;
            }
            else  /* If Not, Deal With Window Messages */
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else  /* If There Are No Messages */
        {
            // Draw The Scene. Watch For ESC Key And Quit Messages From DrawGLScene()
            if ((g_fActive && !DrawGLScene()) || g_fKeys[VK_ESCAPE])  /* Active?  Was There A Quit Received? */
            {
                fDone = TRUE;
            }
            else  /* Not Time To Quit, Update Screen */
            {
                SwapBuffers(hDC);  // Swap Buffers (Double Buffering)

                
                if (g_fKeys[' '])
                {
                    Feur();
					X=Y=0;
					g_fKeys[' ']=FALSE;
					if(player==1) 
					{
						player=2;
						do{
							DialogBox(hInstance, MAKEINTRESOURCE(INPUTBOX), NULL, (DLGPROC)WndProc);
							if(strcmp(buffer,password2)!=0)
								MessageBox(0,"������ �� �����","������",MB_OK);
						}while(strcmp(buffer,password2)!=0);
						HodP1++;
					}
					else 
					{
						 player=1;
						 do{
							DialogBox(hInstance, MAKEINTRESOURCE(INPUTBOX), NULL, (DLGPROC)WndProc);
							if(strcmp(buffer,password1)!=0)
								MessageBox(0,"������ �� �����","������",MB_OK);
						}while(strcmp(buffer,password1)!=0);
				         HodP2++;
					}
					if(HodP1==HodP2&&HodP1==1)
					{
						if(DeathP1==4*1+3*2+2*3+4*1&&DeathP2!=18)
						{
							MessageBox(0,"������ ����� �������","������� ���",MB_ICONINFORMATION );
							ClearBoards();
							player=1;
							CreateBoards();
							player=2;
							CreateBoards();
							player=1;
						}
						if(DeathP2==4*1+3*2+2*3+4*1&&DeathP1!=18)
						{
							MessageBox(0,"������ ����� �������","������� ���",MB_ICONINFORMATION );
							ClearBoards();
							player=1;
							CreateBoards();
							player=2;
							CreateBoards();
							player=2;
						}
						if(DeathP2==4*1+3*2+2*3+4*1&&DeathP1==18)
						{
							MessageBox(0,"�����","������� ���",MB_ICONINFORMATION );
							ClearBoards();
							player=1;
							CreateBoards();
							player=2;
							CreateBoards();
							player=2;
						}
						HodP2=HodP1=0;
					}
                }
                
                if (g_fKeys[VK_UP])
				{
					if(Y<9) Y++;
					g_fKeys[VK_UP]=FALSE;
				}
				if (g_fKeys[VK_DOWN])
				{
                    if(Y>0) Y--;
					g_fKeys[VK_DOWN]=FALSE;
				}
                if (g_fKeys[VK_RIGHT])
				{
                    if(X<9) X++;
					g_fKeys[VK_RIGHT]=FALSE;
				}
                if (g_fKeys[VK_LEFT])
				{
                    if(X>0) X--;
					g_fKeys[VK_LEFT]=FALSE;
				}
            }
        }
    }

    // Shutdown
    KillGLWindow();  // Kill The Window
    return msg.wParam;
}
