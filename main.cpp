/*
������� 1. ���� ������
��� ����� �������
� ��������� ��� ���������� ��������� ������������� ����� ������: ��� ����� � ��������� ���������� �� ���� � �� �� ����� ������� � ��������. 
����� ������� ����� ���� ��� �������������, ��� � ������������� � �������� ���������� ����� � ��� ������. 
���� ��� ������ �� ������ ����� ������� �������� �� �������, �� �� ������������� (�� ���� ����� � ������� 27 � ��� ����� ����� a, 
����� � ������� 28 � ��� ����� b � ��� �����).
��������, ����� abracadabra ��� ������ �� ������ ������� ����������� � klbkmknklbk. ���� ���������� ���� ���������� ������ ������. 
������� ���� (��������� � ��������) ������ �� �����. �������� ������� encrypt_caesar �� ������ � �����, ������� ���������� �������� ������, 
������������� ������ ������ � ����������, ������ ������� �����. ����� �������� ������� decrypt_caesar, ����������� �������� ��������������. 
�������, ��� ������� ������ ������� ���� �� ���������� ����. ���� ��� ���������� � ������ �������, �� �� ���� ������������.
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