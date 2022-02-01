#pragma once

/*

Класс абстрактной фигуры для тетриса
Не предназначен для создания напрямую

Его следует унаследовать и реализовать конструктор,
устанавливающий форму фигуры

Для вращения и изменения координат следует использовать
функции safeRotate, safeFall, safeLeft и safeRight
Они не позволяют выпасть фигуре за границы экрана или
столнкнуться с уже установленными на поле фигурами.

Также для перемещения фигурки на самый верх экрана
следует использовать фукнцию moveOnTop.

Геттеры позволяют получить значения необходимых
полей фигурки, а также проверить, находится ли она
в состоянии колизии или за пределами экрана.

*/

class Figure {
  private:
    int color;
    int x, y;

    void rotate();
    void undoRotation();

  protected:
    int **form;
    virtual int **getInitialForm() = 0;
    int **createDynamicFormFromStatic(int form[4][4]);
    Figure(int color, int x, int y);

  public:
    ~Figure();

    bool checkCollision(const int **gameField);
    bool isOutOfBounds();

    int getX();
    int getY();
    int getColor();
    const int **getForm();

    bool safeRotate(const int **gameField);
    bool safeFall(const int **gameField);
    bool safeLeft(const int **gameField);
    bool safeRight(const int **gameField);

    void moveOnTop();
};