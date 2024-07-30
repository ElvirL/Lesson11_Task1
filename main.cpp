/*
Задание 1. Шифр Цезаря
Что нужно сделать
В древности для шифрования сообщений использовался такой способ: все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. 
Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра — его ключом. 
Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 — это снова буква a, 
буква с номером 28 — это буква b и так далее).
Например, слово abracadabra при сдвиге на десять позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. 
Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, 
зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, выполняющую обратное преобразование. 
Считаем, что входные строки состоят лишь из английских букв. Если там содержатся и другие символы, то их надо игнорировать.
*/

#include <iostream>
#include <string>

using namespace std;

string encrypt_caesar(string text, int n){
    string encrypt_text = "";
    char start_symbol = 'a';
    char end_symbol = 'z';

    for (char c: text){
        if (c >= 'a' && c <= 'z'){
            start_symbol = 'a';
            end_symbol = 'z';
        }
        else if (c>= 'A' && c <='Z'){
            start_symbol = 'A';
            end_symbol = 'Z';
        } 
        else {
            encrypt_text+=c;
            continue;
        }
        char temp_c = c - start_symbol;
        temp_c+=n;
        temp_c%= 26;
        if (temp_c < 0){
            temp_c = end_symbol + temp_c + 1 - start_symbol;
        }
        temp_c+= start_symbol;
        encrypt_text+=temp_c;
    }
    return encrypt_text;
}

string decrypt_caesar(string text, int n){
    return encrypt_caesar(text, -n);
}

int main(){
    cout << encrypt_caesar("abcd", 2) << endl;
    cout << decrypt_caesar(encrypt_caesar("abcd", 2), 2);

}