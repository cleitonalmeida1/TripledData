#include "TData.h"
#include "Carro.h"

using namespace std;

int main() {
	//duas saídas

	Carro carro;
	carro.setLocalizacao(100);
	carro.getEmergencia()->setTelefoneHospital(123456);
	TData<Carro> dataCarro(carro);

	TData<int> a(4);
	cout << a << endl;
	a = 8;
	cout << a << endl;
	a = 9;
	cout << a << endl;
	a = 1 + 9;
	cout << a << endl;

	dataCarro.getDataObject()->setLocalizacao(4000);
	cout << dataCarro.getDataObject()->getLocalizacao() << endl;

	dataCarro.injectFault();

	cout << "Localizacao original: " << dataCarro.getData().getLocalizacao()
			<< endl;
	cout << "Telefone do Hospital original: "
			<< dataCarro.getData().getEmergencia()->getTelefoneHospital()
			<< endl;

	dataCarro.print();

}
