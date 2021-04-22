//Подключение библиотеки GLUT
#include <GL/glut.h> 

void Init(void);
void Display(void);
void DrawLevyCurve(int x1, int x2, int y, int y2, int i);

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
	glutCreateWindow("Кривая Леви"); 
	Init();
	//Установка функций, отвечающих за рисование в окне
	glutDisplayFunc(Display); 
	//Перейти в главный цикл GLUT
	glutMainLoop(); 
}

void Init() {
	//Задает значения очистки цветом буфера цвета
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	//Все последующие изменения будут применяться к проекционной матрице
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Устанавка двумерной орфографической области просмотра
	gluOrtho2D(-400, 400, -400, 400);
}

void Display() {
	//Очистка буфера цвета
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	//Рисование линий
	glBegin(GL_LINES); 
	DrawLevyCurve(-200, 0, 200, 0, 14);
	//Закончить рисование
	glEnd(); 
	//Ожидание конца прорисовки
	glFlush();
}

void DrawLevyCurve(int x1, int y1, int x2, int y2, int i) {
	if (i == 0) {
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	}
	else {
		int x = (x1 + x2) / 2 - (y2 - y1) / 2;
		int y = (y1 + y2) / 2 + (x2 - x1) / 2;
		DrawLevyCurve(x1, y1, x, y, i - 1);
		DrawLevyCurve(x, y, x2, y2, i - 1);
	}
}