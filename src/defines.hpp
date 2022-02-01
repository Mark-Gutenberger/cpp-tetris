#pragma once

// Ширина игрового поля (кубиков)
#define GAME_FIELD_WIDHT 10

// Высота игрового поля (кубиков)
#define GAME_FIELD_HEIGHT 20

// Длина одного тика (в тысячных миллисекунды)
#define TICK_LEN 1000

// Награда за зачистку одной строки кубиков
#define ROW_REWARD 10

// Раз во сколько очков повышается сложность
// (должно быть кратно ROW_REWARD)
#define LEVEL_COST 50

// Ускорение падения фигурок каждый уровень
#define SPEEDUP_PER_LEVEL 1.5

// Раз в какое количество тиков на 0 уровне должен
// падать кубик вниз.
#define DEFAULT_FALL_DELAY 250