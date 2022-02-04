#include "figure.hpp"

#include <math.h>

#include <iostream>
#include <vector>

#include "defines.hpp"

Figure::Figure(int color, int x, int y) {
	this->color = color;
	this->x = x;
	this->y = y;
}

int** Figure::createDynamicFormFromStatic(int form[4][4]) {
	int** new_form = new int*[4];
	for (int i = 0; i < 4; i++)
		new_form[i] = new int[4];

	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			new_form[n][m] = form[n][m];
		}
	}
	return new_form;
}

void Figure::rotate() {
	int buf[4][4];

	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			buf[n][m] = this->form[m][3 - n];
		}
	}

	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			this->form[n][m] = buf[n][m];
		}
	}
}

bool Figure::checkCollision(const int** gameField) {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			if (!this->form[n][m])
				continue;

			if (x + m < 0 || x + m >= GAME_FIELD_WIDHT || y + n < 0 ||
				y + n >= GAME_FIELD_HEIGHT)
				continue;

			int field_x = x + m;
			int field_y = y + n;

			if (gameField[field_y][field_x])
				return true;
		}
	}
	return false;
}

bool Figure::isOutOfBounds() {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			if (!form[n][m])
				continue;
			if (x + m < 0 || x + m >= GAME_FIELD_WIDHT || y + n < 0 ||
				y + n >= GAME_FIELD_HEIGHT) {
				return true;
			}
		}
	}
	return false;
}

void Figure::undoRotation() {
	this->rotate();
	this->rotate();
	this->rotate();
}

int Figure::getX() {
	return this->x;
}

int Figure::getY() {
	return this->y;
}

int Figure::getColor() {
	return this->color;
}

const int** Figure::getForm() {
	return (const int**)this->form;
}

bool Figure::safeRotate(const int** gameField) {
	this->rotate();
	if (this->isOutOfBounds() || this->checkCollision(gameField)) {
		this->undoRotation();
		return false;
	}
	return true;
}

bool Figure::safeFall(const int** gameField) {
	y--;
	if (this->isOutOfBounds() || this->checkCollision(gameField)) {
		y++;
		return false;
	}
	return true;
}

bool Figure::safeLeft(const int** gameField) {
	x--;
	if (this->isOutOfBounds() || this->checkCollision(gameField)) {
		x++;
		return false;
	}
	return true;
}

bool Figure::safeRight(const int** gameField) {
	x++;
	if (this->isOutOfBounds() || this->checkCollision(gameField)) {
		x--;
		return false;
	}
	return true;
}

void Figure::moveOnTop() {
	if (this->isOutOfBounds())
		return;

	while (!this->isOutOfBounds())
		y++;

	y--;
	return;
}

Figure::~Figure() {
	for (int i = 0; i < 4; i++) {
		delete form[i];
	}
	delete form;
}