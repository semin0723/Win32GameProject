#pragma once

template <typename T>
class Vector {
public:
	Vector() {
		_size = 0;
		_flg = 0;
		_data = new T[MAX_SIZE];
	}
	Vector(int size) {
		_size = 0;
		_flg = 0;
		_data = new T[size];
	}
	Vector(int size, const T& filldata) {
		_size = size;
		_flg = _size - 1;
		_data = new T[size];
		for (int i = 0; i < _size; i++) {
			_data[i] = filldata;
		}
	}
	~Vector() {
		delete[] _data;
	}

	void push_back(const T& value) {
		if (_flg == _size) {
			resize();
		}
		_data[_flg] = value;
		_size++;
		_flg++;
	}
	const T& operator[](int idx) const {
		return _data[idx];
	}
	T& operator[](int idx) {
		return _data[idx];
	}
	int size() {
		return _size;
	}

private:
	int MAX_SIZE = 10;
	int _size;
	int _flg;
	T* _data;

	void resize() {
		T* tmp = new T[MAX_SIZE * 2];
		for (int i = 0; i < _size; i++) {
			tmp[i] = _data[i];
		}
		_flg++;
		delete[] _data;
		_data = tmp;
		MAX_SIZE *= 2;
	}
};