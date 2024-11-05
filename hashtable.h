#pragma once
#include <iostream> 
#include <fstream> 
 
template <typename Key, typename Value> 
struct HNode { 
    Key key; 
    Value value; 
    HNode* next; 
 
    HNode(const Key& _key, const Value& _value) : key(_key), value(_value), next(nullptr) {} 
}; 
 
template <typename Key, typename Value> 
struct HashTable { 
    HNode<Key, Value>** table; 
    int size; 
 
    HashTable(int _size) : size(_size) { 
        table = new HNode<Key, Value>*[size]; 
        for (int i = 0; i < size; i++) { 
            table[i] = nullptr; 
        } 
    } 
 
    // Хеш-функция (простая для демонстрации) 
    int hash(const Key& key) { 
        return stoi(key) % size; 
    } 
 
    // Добавление элемента 
    void HINSERT(const Key& key, const Value& value) { 
        int index = hash(key); 
        HNode<Key, Value>* newNode = new HNode<Key, Value>(key, value); 
        newNode->next = table[index]; 
        table[index] = newNode; 
    } 
 
    // Получение значения по ключу 
    Value HGET(const Key& key) { 
        int index = hash(key); 
        HNode<Key, Value>* current = table[index]; 
        while (current != nullptr) { 
            if (current->key == key) { 
                return current->value; 
            } 
            current = current->next; 
        } 
        throw std::runtime_error("Key not found"); // Можно бросить исключение, если ключ не найден 
    } 
 
    // Удаление элемента по ключу 
    void HREMOVE(const Key& key) { 
        int index = hash(key); 
        HNode<Key, Value>* current = table[index]; 
        HNode<Key, Value>* previous = nullptr; 
 
        while (current != nullptr) { 
            if (current->key == key) { 
                if (previous == nullptr) { 
                    table[index] = current->next; 
                } else { 
                    previous->next = current->next; 
                } 
                delete current; 
                return; 
            } 
            previous = current; 
            current = current->next; 
        } 
        throw std::runtime_error("Key not found"); // Можно бросить исключение, если ключ не найден 
    } 
 
    // Запись в файл 
    void saveToFile(const std::string& filename) { 
        std::ofstream file(filename); 
        if (!file.is_open()) { 
            throw std::runtime_error("Cannot open file for writing"); 
        } 
        file << size << std::endl; // Записываем размер таблицы 
        for (int i = 0; i < size; i++) { 
            HNode<Key, Value>* current = table[i]; 
            while (current != nullptr) { 
                file << current->key << " " << current->value << std::endl; 
                current = current->next; 
            } 
        } 
        file.close(); 
    } 
 
    // Чтение из файла 
    void loadFromFile(const std::string& filename) { 
        std::ifstream file(filename); 
        if (!file.is_open()) { 
            throw std::runtime_error("Cannot open file for reading"); 
        } 
        int _size; 
        file >> _size; // Читаем размер таблицы 
        if (_size != size) { 
            throw std::runtime_error("Table size mismatch"); 
        } 
        // Очищаем таблицу 
        for (int i = 0; i < size; i++) { 
            delete table[i]; 
            table[i] = nullptr; 
        } 
 
        Key key; 
        Value value; 
        while (file >> key >> value) { 
            HINSERT(key, value); 
        } 
        file.close(); 
    } 
};