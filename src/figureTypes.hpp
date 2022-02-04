#pragma once
#include "figure.hpp"

class IFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	IFigure(int x, int y, int color);
};

class JFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	JFigure(int x, int y, int color);
};

class LFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	LFigure(int x, int y, int color);
};

class SFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	SFigure(int x, int y, int color);
};

class ZFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	ZFigure(int x, int y, int color);
};

class OFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	OFigure(int x, int y, int color);
};

class TFigure : public Figure {
   protected:
	int** getInitialForm() override;

   public:
	TFigure(int x, int y, int color);
};
