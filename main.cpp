#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include<string.h>
int score=0;
GLsizei wh=500,ww=500;
int flag=0;

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
int allowed[25][25];

char quote[8][8];

//int allowed[25][25];
//int ax[25]={0,5,10,15,20,0,5,10,15,20,0,5,10,15,20,0,5,10,15,20,0,5,10,15,20};
//int ay[25]={0,0,0,0,0,5,5,5,5,5,10,10,10,10,10,15,15,15,15,15,20,20,20,20,20};
int ax[25]= {0,8,16,24,32,0,8,16,24,32,0,8,16,24,32,0,8,16,24,32,0,8,16,24,32};
int ay[25]= {0,0,0,0,0,8,8,8,8,8,16,16,16,16,16,24,24,24,24,24,32,32,32,32,32};

void text(float x,float y,char *st)
{
	int l,i;
	l=strlen(st);
	glRasterPos2f(x,y);
	for(i=0;i<l;i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
}
void Sprinti( float x, float y,int st)
{
    char ch='0';
    glRasterPos2d(x, y);
    switch(st)
    {

    case 1:
        ch='1';
        break;
    case 2:
        ch='2';
        break;
    case 3:
        ch='3';
        break;
    case 4:
        ch='4';
        break;
    case 5:
        ch='5';
        break;
    case 6:
        ch='6';
        break;
    case 7:
        ch='7';
        break;
    case 8:
        ch='8';
        break;
    case 9:
        ch='9';
        break;
    case 10:
        ch='10';
        break;
	case 11:
        ch='11';
        break;
    case 12:
        ch='12';
        break;
    case 13:
        ch='13';
        break;
    case 14:
        ch='14';
        break;
    case 15:
        ch='15';
        break;
    case 16:
        ch='16';
        break;
    case 17:
        ch='17';
        break;
    case 18:
        ch='18';
        break;
    case 19:
        ch='19';
        break;
    case 20:
        ch='20';
        break;
 	case 21:
        ch='21';
        break;
    case 22:
        ch='22';
        break;
    case 23:
        ch='23';
        break;
    case 24:
        ch='24';
        break;
    }
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch);
}
void border()
{

    for(int i=0; i<25; i++)
    {
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(ax[i],ay[i]);
        glVertex2i(ax[i]+8,ay[i]);
        glVertex2i(ax[i]+8,ay[i]+8);
        glVertex2i(ax[i],ay[i]+8);
        glEnd();
    }
    /*for(int i=0;i<25;i++)

    	{
    	glColor3f(0.0,0.0,0.0);
    	glBegin(GL_LINES);
    	glVertex2i(ax[i]+10,ay[i]);
    	glVertex2i(ax[i]+10,ay[i]+10);
    	glEnd();
    }*/
    glFlush();
}

int findblock(int x, int y)
{

    x=(x/10)-4;
    y=45-(y/10);
    printf(" x= %d , y=%d \n",x,y);
    for(int i=0; i<25; i++)
    {
        if(((x-ax[i]) < 8) && ((y-ay[i])< 8))
            return i;
    }

}

void hideblock(int cur)
{

    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
    glVertex2d(ax[cur],ay[cur]);
    glVertex2d(ax[cur]+8,ay[cur]);
    glVertex2d(ax[cur]+8,ay[cur]+8);
    glVertex2d(ax[cur],ay[cur]+8);
    glEnd();
    border();
}

void displayblock(int i)
{
    border();


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
    glVertex2d(ax[i],ay[i]);
    glVertex2d(ax[i]+8,ay[i]);
    glVertex2d(ax[i]+8,ay[i]+8);
    glVertex2d(ax[i],ay[i]+8);

    glEnd();
    glFlush();

    border();
}


int num=1;
//int score=0;
int cur;
int count=0;
void myMouse(int b,int s,int x,int y)
{
    int j;
    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
    {
        if(count==0)
        {
            cur=findblock(x,y);
            displayblock(cur);
            hideblock(cur);
			text(30.0,41.0,"Score :");
			
		 //   Sprinti(x,y,num);
            score=1;
            printf("Score :%d\n",score);
		//	display();
			Sprinti(37.0,41.0,score);
        //    display();    
			//glColor3f(0.5,0.7,0.3);
            count=-1;
            for(int m=0; m<25; m++)
                allowed[m][cur]=-1;
        }
        else
        {
		//	Sprinti(37.0,41.0,' ');
	/*		glColor3f(0.2,0.4,0.7);
			glBegin(GL_POLYGON);
            glVertex2d(36.0,43.0);
            glVertex2d(36.0,40.0);
            glVertex2d(38.0,40.0);
            glVertex2d(38.0,43.0);
            glEnd();*/
            int	i=findblock(x,y);
            printf("findblock return %d\n",i);
            if (allowed[cur][i]==-1)
                glutIdleFunc(NULL);
            else
            {
                if(allowed[cur][i]==1)
                {
                    score+=1;
					//display();
                    printf("%d\n",score);
					
			Sprinti(37.0,41.0,score);
		//	display();
		//	glColor3f(0.5,0.7,0.3);
                    printf("allowed[%d][%d]\n",cur,i);
                    printf("findblock return %d\n",i);
                    displayblock(i);
                }
                hideblock(cur);
                allowed[cur][i]=-1;
                cur=i;
                for(int m=0; m<25; m++)
                    allowed[m][cur]=-1;
            }
        }
    if(score==25)
    {
        text(30.0,41.0,"You Won !!!");
        glColor3f(0.5,0.7,0.3);
    }
    }
    glFlush();
}


void resizeHandler( int w, int h )
{

    if( h==0 ) h=1;
    float aspecRatio = (float)w / (float)h;
    glViewport( 0, 0, w, h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(30.0, aspecRatio, 3.0, 8888.0 );
    gluLookAt( 0.0, 0.0, 100.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0 );
//glutPostRedisplay();
//ww=w; wh=h;
    return;
}

void demo_menu(int id)
{
 switch(id)
 {
  /*case 1:printf("Restart\n");
	     break;*/
  case 1:exit(0);
	     break;
}
//glutPostRedisplay();
}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(-20.0,-20.0,10.0);
	text(15.0,41.0,"Knight Move");
    text(24.0,-2.5,"By- Ashwini, Advait");
	text(1.0,-2.5,"(Right Click to exit)");
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<25; j++)
        {
            if(((i+j)%2)==0)
                glColor3f(1.0,1.0,1.0);
            else glColor3f(0.0,0.0,0.0);
            glBegin(GL_POLYGON);
            glVertex2i(ax[i],ay[i]);
            glVertex2i(ax[i]+8,ay[i]);
            glVertex2i(ax[i]+8,ay[i]+8);
            glVertex2i(ax[i],ay[i]+8);
            glEnd();
        }
    }
    border();
	//printf("score123=%d",score);
//	Sprinti(37.0,41.0,score);
    glFlush();
}

void a()
{
    for(int a=0; a<=24; a++)
        for(int b=0; b<=24; b++)
            allowed[a][b]=-1;
    allowed[0][7]=1;
    allowed[0][11]=1;
    allowed[1][8]=1;
    allowed[1][10]=1;
    allowed[1][12]=1;
    allowed[2][5]=1;
    allowed[2][9]=1;
    allowed[2][11]=1;
    allowed[2][13]=1;
    allowed[3][6]=1;
    allowed[3][12]=1;
    allowed[3][14]=1;
    allowed[4][7]=1;
    allowed[4][13]=1;
    allowed[5][2]=1;
    allowed[5][12]=1;
    allowed[5][16]=1;
    allowed[6][3]=1;
    allowed[6][13]=1;
    allowed[6][15]=1;
    allowed[6][17]=1;
    allowed[7][0]=1;
    allowed[7][4]=1;
    allowed[7][10]=1;
    allowed[7][14]=1;
    allowed[7][16]=1;
    allowed[7][18]=1;
    allowed[8][1]=1;
    allowed[8][11]=1;
    allowed[8][17]=1;
    allowed[8][19]=1;
    // allowed[9][3]=1;
    allowed[9][12]=1;
    allowed[9][18]=1;
    allowed[10][1]=1;
    allowed[10][7]=1;
    allowed[10][17]=1;
    allowed[10][21]=1;
    allowed[11][0]=1;
    allowed[11][2]=1;
    allowed[11][8]=1;
    allowed[11][18]=1;
    allowed[11][20]=1;
    allowed[11][22]=1;
    allowed[12][1]=1;
    allowed[12][3]=1;
    allowed[12][5]=1;
    allowed[12][9]=1;
    allowed[12][15]=1;
    allowed[12][19]=1;
    allowed[12][21]=1;
    allowed[12][23]=1;
    allowed[13][2]=1;
    allowed[13][4]=1;
    allowed[13][6]=1;
    allowed[13][16]=1;
    allowed[13][22]=1;
    allowed[13][24]=1;
    allowed[14][3]=1;
    allowed[14][7]=1;
    allowed[14][17]=1;
    allowed[14][23]=1;
    allowed[15][6]=1;
    allowed[15][12]=1;
    allowed[15][22]=1;
    allowed[16][5]=1;
    allowed[16][7]=1;
    allowed[16][13]=1;
    allowed[16][23]=1;
    allowed[17][6]=1;
    allowed[17][8]=1;
    allowed[17][10]=1;
    allowed[17][14]=1;
    allowed[17][20]=1;
    allowed[17][24]=1;
    allowed[18][7]=1;
    allowed[18][9]=1;
    allowed[18][11]=1;
    allowed[18][21]=1;
    allowed[19][8]=1;
    allowed[19][12]=1;
    allowed[19][22]=1;
    allowed[20][11]=1;
    allowed[20][17]=1;
    allowed[21][10]=1;
    allowed[21][12]=1;
    allowed[21][18]=1;
    allowed[22][11]=1;
    allowed[22][13]=1;
    allowed[22][15]=1;
    allowed[22][19]=1;
    allowed[23][12]=1;
    allowed[23][14]=1;
    allowed[23][16]=1;
    allowed[24][13]=1;
    allowed[24][17]=1;

}

void myinit()
{
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 20.0, 0.0, 20.0);
    glClearColor (0.2,0.4,0.7,0.8);
    glColor3f(0.0,0.0,0.0);
}


int main(int argc, char **argv)
{
    /*for(int i=0;i<25;i++)
    	for(int j=0;j<25;j++)
    		 allowed[i][j]=1;*/

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(400,100);
	glutCreateWindow("Knight Move");
	glutCreateMenu(demo_menu);
    //glutAddMenuEntry("Restart",1);
	glutAddMenuEntry("Exit",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutReshapeFunc(resizeHandler);
//    glutIdleFunc(spinDisplay);
    glutMouseFunc(myMouse);
    myinit();
    a();
    glutMainLoop();
}
