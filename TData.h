#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

template<class T>
class TData {
public:

	TData() {
	}

	T getData();

	void setData(T data);
	void setData(T *data);

	void print();

	void printPessoa();

	void injectFault();

	void injectPessoa();
	void injectAnimal();
	void injectAnimal2();

	TData& operator=(T data) {
		setData(data);
		return *this;
	}

	TData& operator=(TData& rhs) {
		setData(rhs.getData());
		return *this;
	}

	operator T() {
		return getData();
	}

private:

	T d1, d2, d3;

	T getByVotting();
};

template<class T>
T TData<T>::getByVotting() {

	if (d1 == d2) {
		if (d1 != d3) {
			d3 = d1;
			//memcpy(&d3, &d1, sizeof(T));
		}
	} else if (d1 == d3)
		d2 = d1;
	//memcpy(&d2, &d1, sizeof(T));
	else if (d2 == d3)
		d1 = d2;
	//memcpy(&d1, &d2, sizeof(T));
	else {
		cout << "throws exception" << endl;
	}

	return d1;
}

template<class T>
T TData<T>::getData() {
	return getByVotting();
}

template<class T>
void TData<T>::setData(T data) {
	d1 = data;
	d2 = data;
	d3 = data;
}

template<class T>
void TData<T>::setData(T *data) {
	d1 = *data;
	d2 = *data;
	d3 = *data;
}

template<class T>
void TData<T>::print() {
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	cout << "d3 = " << d3 << endl;
}

template<class T>
void TData<T>::printPessoa() {
	cout << "d1 = " << d1.getIdade() << endl;
	cout << "d2 = " << d2.getIdade() << endl;
	cout << "d3 = " << d3.getIdade() << endl;
}

template<class T>
void TData<T>::injectFault() {
	d1 = 66;
}

template<class T>
void TData<T>::injectPessoa() {
	d1.setIdade(12);
}

template<class T>
void TData<T>::injectAnimal() {
	d1.getAnimal().setIdade(2);
}

template<class T>
void TData<T>::injectAnimal2() {
	d2.setAnimal2(NULL);
}

