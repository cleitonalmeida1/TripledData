/*
 * Carro.h
 *
 *  Created on: 07/06/2016
 *      Author: Cleiton Gonçalves
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "Emergencia.h"

class Carro {
public:

	Carro() {
		localizacao = 0;
		emergencia = new Emergencia();
	}

	virtual ~Carro() {

	}

	bool operator==(Carro c) {

		if (localizacao == c.getLocalizacao()
				&& emergencia == c.getEmergencia()) {
			return true;
		}
		return false;
	}

	bool operator!=(Carro c) {

		if (localizacao != c.getLocalizacao()
				&& emergencia
						!= c.getEmergencia()) {
			return true;
		}
		return false;
	}

	void setLocalizacao(unsigned int localizacao) {
		this->localizacao = localizacao;
	}

	unsigned int getLocalizacao() {
		return this->localizacao;
	}

	Emergencia *getEmergencia() {
		return emergencia;
	}

	void setEmergencia(Emergencia *emergencia) {
		this->emergencia = emergencia;
	}

private:
	unsigned int localizacao;
	Emergencia* emergencia;

};

#endif /* CARRO_H_ */
