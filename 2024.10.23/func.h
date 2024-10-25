#pragma once

int sum(int a, int b);

static int a = 15; // создание новой переменной

extern int B; // переменная где-то создана, я хочу ей воспользоваться


template <typename ResultType>
ResultType div(double a, double b){
    return a / b;
} // шаблоны нельзя разделить на h & cpp
