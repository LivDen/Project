//Подключение библиотеки GLUT
#include <GL/glut.h> 

void Initialization(void);
void Display(void);
void DrawMandelbrot(int iterations);

int main(int argc, char** argv) {
	//Передаём параметры функции main 
	glutInit(&argc, argv);
	/*Режим отображения информации.
	SINGLE: Вывод в окно осуществляется с использованием 1 буфера.
	RGB: Для отображения графической информации используются 3 компоненты цвета RGB*/
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Размеры окна
	glutInitWindowSize(1000, 1000);
	//Расположение окна (x,y)
	glutInitWindowPosition(350, 20);
	//Создание окна
	glutCreateWindow("Множество Мандельброта");
	Initialization();
	//Установка функций, отвечающих за рисование в окне
	glutDisplayFunc(Display);
	//Перейти в главный цикл GLUT
	glutMainLoop();
}

void Initialization() {
	//Очистка окна в белый цвет
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//Настроим 2-х мерный вид
	glMatrixMode(GL_PROJECTION);
	//Текущая матрица сбрасывается на единичную
	glLoadIdentity();
	//Устанавка двумерной орфографической области просмотра
	gluOrtho2D(-2, 2, -2, 2);
}

void Display() {
	//Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT);
	//Установливаем белый цвет
	glColor3f(1.0, 1.0, 1.0);
	//Количество итераций рисования
	DrawMandelbrot(500);
	//Ожидание конца прорисовки
	glFlush();
}

void DrawMandelbrot(int i) {
	double t1, t2;
	double x, y;
	//Размер точки на экране
	glPointSize(1.0);
	//Цвет точки
	glColor3f(0, 0, 0);
	//Рисование точек
	glBegin(GL_POINTS);
	for (double a = -2; a < 2; a += 0.001) {
		for (double b = -2; b < 2; b += 0.001) {
			x = a,
				y = b;
			int cnt = 0;
			while (cnt < i && x * x + y * y < 4) {
				t1 = x * x - y * y + a;
				t2 = 2 * x * y + b;
				x = t1;
				y = t2;
				cnt++;
			}
			if (cnt == i)
				glVertex2d(a, b);
		}
	}
	//Закончить рисование
	glEnd();
}
