#include <iostream>
#include "Emergencia.h"
using namespace std;

template<class T>
class TData {
public:

	TData(T t) {
		setData(t);
	}

	TData(T *t) {
		setData(t);
	}

	T getData();

	T* getDataObject();

	void injectFault();

	void setData(T data);
	void setData(T *data);

	TData& operator=(T data) {
		setData(data);
		return *this;
	}
	TData& operator=(TData& obj) {
		setData(obj.getData());
		return *this;
	}

	operator T() {
		return getData();
	}

	void print() {
		cout << "localizacao 1: " << d1.getLocalizacao() << endl;
		cout << "localizacao 2: " << d2.getLocalizacao() << endl;
		cout << "localizacao 3: " << d3.getLocalizacao() << endl;

		cout << "Telefone do Hospital 1: "
				<< d1.getEmergencia()->getTelefoneHospital() << endl;
		cout << "Telefone do Hospital 2: "
				<< d2.getEmergencia()->getTelefoneHospital() << endl;
		cout << "Telefone do Hospital 3: "
				<< d3.getEmergencia()->getTelefoneHospital() << endl;
	}

private:

	T d1;
	T d2;
	T d3;
	T dataObject;

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
template<typename T>
T TData<T>::getData() {
	return getByVotting();
}

template<class T>
T* TData<T>::getDataObject() {
	d1 = dataObject;
	d2 = dataObject;
	d3 = dataObject;
	dataObject = getByVotting();
	return &dataObject;
}

template<typename T>
void TData<T>::setData(T data) {
	d1 = data;
	d2 = data;
	d3 = data;
	dataObject = data;
}
template<typename T>
void TData<T>::setData(T *data) {
	d1 = *data;
	d2 = *data;
	d3 = *data;
	dataObject = *data;
}

template<class T>
void TData<T>::injectFault() {
	Emergencia* e = new Emergencia();
	d1.setEmergencia(e);
	d1.setLocalizacao(200);
}

