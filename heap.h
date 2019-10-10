//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
template <typename T>
class heap {

public:
    heap() {
        heapSort(datos);
    }
    void heapify(heap <T> &v, int n, int i) {
        int largo = i;
        int izquierda = 2 * i + 1;
        int derecha = 2 * i + 2;
        if ((izquierda < n) and (v[izquierda] > v[largo])) {
            largo = izquierda;
        }
        if ((derecha < n) and (v[derecha] > v[largo])) {
            largo = derecha;
        }
        if (largo != i) {
            swap(v[i], v[largo]);
            heapify(v, n, largo);
        }
    }
    void heapSort(heap <T> &v) {
        int n = v.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(v, n, i);
        }
        for (int j = n - 1; j >= 0; --j) {
            swap(v[0], v[j]);
            heapify(v, j, 0);
        }
    }
    vector<T> datos;
    T get_max() {
        auto max = 0;
        for (auto it = begin(datos); it < end(datos); it++) {
            if (max < *it)
                max = *it;
        };
        return max;
    }
    void insert(T item) {
        ofstream file;
        file.open("data.txt", ios_base::app);
        file << item;
        file << endl;
        file.close();
        datos.push_back(item);
    }
    friend std::ostream &operator<<(std::ostream &out, const heap<T> heap) {
        for (auto it = begin(heap.datos); it < end(heap.datos); it++) {
            out << *it << " ";
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, const heap <T> heap) {

        return in;
    }
};
template<typename T>
void load_from(const string &file_name, heap<T> &hp) {
    ifstream file;
    string data;
    hp.datos.clear();
    file.open(file_name, ios_base::in);
    while (!file.eof()) {
        getline(file, data);
        hp.datos.push_back(stoi(data));
    }
    file.close();
}
template <typename T,typename...Args>
void insert(heap<T>& hp,T first, Args...items){

}
#endif //CS1103_P C2_201902_HEAP_H
