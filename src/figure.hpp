#pragma once

class Figure {
 private:
  int color;
  int x, y;

  void rotate();
  void undoRotation();

 protected:
  int** form;
  virtual int** getInitialForm() = 0;
  int** createDynamicFormFromStatic(int form[4][4]);
  Figure(int color, int x, int y);

 public:
  ~Figure();

  bool checkCollision(const int** gameField);
  bool isOutOfBounds();

  int getX();
  int getY();
  int getColor();
  const int** getForm();

  bool safeRotate(const int** gameField);
  bool safeFall(const int** gameField);
  bool safeLeft(const int** gameField);
  bool safeRight(const int** gameField);

  void moveOnTop();
};
