//Farm.cpp
#include "Farm.h"
#include "Cow.h"

#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>

void Farm::addCow(Cow c) {
	cow[tail++] = c;
}

void Farm::supply(std::string name, int sup) {
	for (int i = 0; i < n; i++)
		if (name == cow[i].name) {
			cow[i].food += sup;
			return;
		}
}

void Farm::startMeal() {
	for (int i = 0, meal; i < n; i++) {
		meal = std::min(cow[i].u, cow[i].food);
		cow[i].meal = meal;
		cow[i].food -= meal;
	}
}

void Farm::produceMilk() {
	for (int i = 0; i < n; i++) {
		if (cow[i].meal > 0) {
			if (cow[i].meal < cow[i].l)
				milk += (double)cow[i].m / 2.0;
			else
				milk += (double)cow[i].m;
		}
	}
}

double Farm::getMilkProduction() {
	return milk;
}