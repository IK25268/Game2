#pragma once
#include <math.h>

static int SqPos(double pos) { return ((int)(pos / 25))*25; }
static int NextSqPos(double pos) { return ((int)(pos / 25) + 1)*25; }
static int PrevSqPos(double pos) { return ((int)(pos / 25) - 1)*25; }