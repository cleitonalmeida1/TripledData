#include "TData.h"
#include "Pessoa.h"

int main(int argc, char** argv) {

	Pessoa p;
	Animal animal;
	Animal *animal2 = new Animal();
	animal.setIdade(10);
	animal2->setIdade(20);
	TData<Pessoa> dataPessoa;


	p.setAnimal(animal);
	p.setAnimal2(animal2);
	p.setIdade(100);
	dataPessoa.setData(p);

	dataPessoa.getData().setIdade(200);

	cout << "Idade da pessoa = " << dataPessoa.getData().getIdade() << endl;
	cout << "Idade do animal = " << dataPessoa.getData().getAnimal().getIdade()
			<< endl;
	cout << "Idade do animal2 = "
			<< dataPessoa.getData().getAnimal2()->getIdade() << endl;

	dataPessoa.printPessoa();

	//var.setData(88);

	//var = 94 + 6;

	//var.injectFault();

	//cout << "var = " << var << endl;

	//var.print();

	return 0;
}

