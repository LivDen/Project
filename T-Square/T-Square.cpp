//Подключение библиотеки GLUT
#include <GL/glut.h> 

void Init(void);
void Display(void);
void DrawTSquare(int xCenter, int yCenter, int lenght, int i);

int main(int argc, char** argv) {
	//Передаём параметры функции main 
	glutInit(&argc, argv);
	//Иницилизируем дисплей с одним буфером(GLUT_SINGLE) в фрмате RGB 24 битный цвет
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Устанавливаем размер окна(1000 на 1000 пикселей)
	glutInitWindowSize(1000, 1000);
	//Расположение окна (x,y)
	glutInitWindowPosition(350, 20);
	//Создание окна; Название окна
	glutCreateWindow("Т-Квадрат");
	Init();
	glutDisplayFunc(Display);
	//Функция, завершающая описание окна
	glutMainLoop();
}

void Init() {
	//Очистка окна в черный цвет
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Настроим 2-х мерный вид
	glMatrixMode(GL_PROJECTION);
	//Текущая матрица сбрасывается на единичную
	glLoadIdentity();
	//Устанавка двумерной орфографической области просмотра
	gluOrtho2D(-400, 400, -400, 400);
}

void Display() {
	//Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT);
	//Установливаем белый цвет
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
