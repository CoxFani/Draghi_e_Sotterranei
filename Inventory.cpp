//
// Created by alpacox on 04/12/21.
//

#include "precompiler.h"
#include "Inventory.h"


Inventory::Inventory(unsigned capacity) {

    this->capacity = capacity;
    this->initialize();
    this->nullify();
}

Inventory::~Inventory() {

    this->freeMemory();
}

void Inventory::initialize() {

    this->itemQuantity = 0;
    this->itemArray = new Item*[this->capacity];

}


void Inventory::nullify(const unsigned int from) {

    for(size_t i = from; i < this->capacity; i++){

        this->itemArray[i] = nullptr;
    }
}

void Inventory::freeMemory() {

    for(size_t i = 0; i < this->itemQuantity; i++){

        delete this->itemArray[i];
    }

    delete[] this->itemArray;
}

const unsigned &Inventory::size()  const{

    return this->itemQuantity;
}

const unsigned &Inventory::maxSize() const{

    return this->capacity;
}

void Inventory::clear() {

    for(size_t i = 0; i < this->itemQuantity; i++){

        delete this->itemArray[i];
    }

    this->itemQuantity = 0;

    this->nullify();
}

const bool Inventory::empty() const {

    return this->itemQuantity == 0;
}

const bool Inventory::addItem(Item *item) {

    if(this->itemQuantity <= this->capacity){

        this->itemArray[this->itemQuantity++] = item->clone();

        return true;
    }

    return false;
}

const bool Inventory::removeItem(const unsigned int index) {

    if( this->itemQuantity > 0){

        if(index <0 || index >= this->capacity)
            return false;

        delete this->itemArray[index];
        this->itemArray[index] = nullptr;
        --this->itemQuantity;

        return true;
    }

    return false;
}

const bool Inventory::saveToFile(const std::string fileName) {
    return 0;
}

const bool Inventory::loadFromFile(const std::string fileName) {
    return 0;
}






