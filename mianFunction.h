#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "admin.h"
#include "teacher.h"
using namespace std;

void adminMenu(Identity* admin);
void LogIn(string idengtityFile, int type);
void printMessage(const string& s);