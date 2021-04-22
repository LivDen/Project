//Подключение библиотеки GLUT
#include <GL/glut.h> 

void Init(void);
void Display(void);
void DrawTSquare(int xCenter, int yCenter, int lenght, int i);

int main(int argc, char** argv) {
	//Иницилизация GLUT
	glutInit(&argc, argv);
	/*Режим отображения информации.
	SINGLE: Вывод в окно осуществляется с использованием 1 буфера.
	RGB: Для отображения графической информации используются 3 компоненты цвета RGB*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Размеры окна
	glutInitWindowSize(1000, 1000);
	//Положение создаваемого окна относительно верхнего левого угла экрана
	glutInitWindowPosition(350, 20);
	//Создание окна
	glutCreateWindow("Т-Квадрат");
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();
}

void Init() {
	//Задает значения очистки цветом буфера цвета
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Все последующие изменения будут применяться к проекционной матрице
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Устанавка двумерной орфографической области просмотра
	gluOrtho2D(-400, 400, -400, 400);
}

void Display() {
	//Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	//Рисование квадратов
	glBegin(GL_QUADS);
	DrawTSquare(0, 0, 400, 12);
	//Закончить рисование
	glEnd();
	//Ожидание конца прорисовки
	glFlush();
}

void DrawTSquare(int xCenter, int yCenter, int lenght, int i) {
	int x1 = xCenter - lenght / 2;
	int x2 = xCenter + lenght / 2;
	int y1 = yCenter - lenght / 2;
	int y2 = yCenter + lenght / 2;
	glVertex2i(x1, y1);
	glVertex2i(x1, y2);
	glVertex2i(x2, y2);
	glVertex2i(x2, y1);
	if (i > 1) {
		DrawTSquare(x1, y1, lenght / 2, i - 1);
		DrawTSquare(x1, y2, lenght / 2, i - 1);
		DrawTSquare(x2, y2, lenght / 2, i - 1);
		DrawTSquare(x2, y1, lenght / 2, i - 1);
	}
}