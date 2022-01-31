#include "figure.hpp"
#include "figureTypes.hpp"

int** IFigure::getInitialForm() {
  int form[4][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

IFigure::IFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** JFigure::getInitialForm() {
  int form[4][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

JFigure::JFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** LFigure::getInitialForm() {
  int form[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

LFigure::LFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** SFigure::getInitialForm() {
  int form[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 1, 1},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

SFigure::SFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** ZFigure::getInitialForm() {
  int form[4][4] = 
  {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

ZFigure::ZFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** OFigure::getInitialForm() {
  int form[4][4] = 
  {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

OFigure::OFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}

int** TFigure::getInitialForm() {
  int form[4][4] = 
  {
    {0, 0, 0, 0},
    {0, 1, 1, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
  };

  return this->createDynamicFormFromStatic(form);
}

TFigure::TFigure(int x, int y, int color): Figure(x, y, color) {
  this->form = getInitialForm();
}