#pragma once

template <typename T>
class Vector {
public:
	Vector() {
		_size = 0;
		_flg = 0;
		data = new T(MAX_SIZE);
	}
	Vector(int size) {
		_size = 0;
		_flg = 0;
		data = new T(size);
	}
	Vector(int size, T filldata) {
		_size = size;
		_flg = _size - 1;
		data = new T(size);
		for (int i = 0; i < _size; i++) {
			data[i] = filldata;
		}
	}
	void push_back(T value) {
		if (_flg == _size) {
			resize();
		}
		data[_flg] = value;
		_flg++;
	}
	T operator[](const int& idx) const {
		return data[idx];
	}

private:
	int MAX_SIZE = 10;
	int _size;
	int _flg;
	T* data;

	void resize() {
		T* tmp = new T(MAX_SIZE * 2);
		for (int i = 0; i < _size; i++) {
			tmp[i] = data[i];
		}
		_flg++;
		delete[] data;
		data = tmp;
		MAX_SIZE *= 2;
	}
};