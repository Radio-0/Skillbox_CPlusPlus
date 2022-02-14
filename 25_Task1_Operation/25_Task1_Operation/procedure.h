#pragma once
#include <iostream>

struct coordinadets {
    double x;
    double y;
};

void scalpel(coordinadets arr[2]) {
    std::cout << "Ñut between points\n";
}
void hemostat(double x, double y) {
    std::cout << "Ñlip made hemostat\n";
}
void tweezers(double x, double y) {
    std::cout << "Ñlip made tweezers\n";
}
void suture(coordinadets arr[2]) {
    std::cout << "Seam made\n";
}
bool compare(coordinadets arr_cut[2], coordinadets arr_sut[2]) {
    bool check = true;
    for (int i = 0; i < 2; i++) {
        if ((arr_cut[i].x != arr_sut[i].x) && (arr_cut[i].y != arr_sut[i].y)) {
            check = false;
            break;
        }
    }
    return check;
}