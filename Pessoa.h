/*
 * Pessoa.h
 *
 *  Created on: 07/06/2016
 *      Author: Cleiton Gonçalves
 */

#ifndef PESSOA_H_
#define PESSOA_H_

#include "Animal.h"

class Pessoa {
public:

	Pessoa() {
		idade = 0;
		animal2 = NULL;
	}

	void setIdade(unsigned int idade) {
		this->idade = idade;
	}

	unsigned int getIdade() {
		return this->idade;
	}

	virtual ~Pessoa() {

	}
	bool operator==(Pessoa p) {

		if (idade == p.getIdade() && animal == p.getAnimal() && animal2 == p.getAnimal2()) {
				return true;
		}
		return false;
	}

	bool operator!=(Pessoa p) {

		if (idade != p.getIdade()) {
			return true;
		}
		return false;
	}

	Animal& getAnimal() {
		return animal;
	}

	void setAnimal(Animal& animal) {
		this->animal = animal;
	}

	Animal *getAnimal2() {
		return animal2;
	}

	void setAnimal2(Animal *animal2) {
		this->animal2 = animal2;
	}


private:

	unsigned int idade;
	Animal animal;
	Animal* animal2;
};

#endif /* PESSOA_H_ */
