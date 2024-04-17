#pragma once

template <typename T>
class queue {
public:
    queue() {
        _start = _end = _size = 0;
        MAX_SIZE = 10;
        _data = new T[MAX_SIZE];
    }
    ~queue() {
        if (_data) delete[] _data;
    }
    bool empty() {
        return _start == _end;
    }
    int size() {
        return _size;
    }
    void push(T e) {
        _data[_end] = e;
        _size++;
        _end = (_end + 1) % MAX_SIZE;
        if (_end == _start) {
            resize();
        }
    }
    int front() {
        return _data[_start];
    }
    void pop() {
        _start = (_start + 1) % MAX_SIZE;
        _size--;
    }
private:
	int _size;
    int _start;
    int _end;
    int MAX_SIZE;
	T* _data;

    void resize() {
        T* tmp = new T[MAX_SIZE * 2];
        int flg = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            tmp[flg] = _data[(_start + i) % MAX_SIZE];
            flg++;
        }
        delete[] _data;
        _data = tmp;
        _start = 0; _end = flg;
        MAX_SIZE *= 2;
    }
};