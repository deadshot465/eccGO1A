package com.ecc.gkgo1a;

class K08_1Sub {
    static int GetMaxValue(int v1, int v2, int v3) {
        int temp = v1 >= v2 ? v1 : v2;
        temp = temp >= v3 ? temp : v3;
        return temp;
    }

    static int GetMinValue(int v1, int v2, int v3) {
        int temp = v1 < v2 ? v1 : v2;
        temp = temp < v3 ? temp : v3;
        return temp;
    }
}
