#include <iostream>
#include <exception>
#include <string>
//#include <chrono>

using namespace std;
//using namespace chrono;

/*
string AskTimeServer() {
    system_clock::now();
    /* ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� �������:
       * ���������� ������� ���������� ��������
       * ������ ���������� system_error
       * ������ ������� ���������� � ����������.
    
}
*/

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            return last_fetched_time = AskTimeServer();
        }
        catch (system_error&){
            return last_fetched_time;
        }        
        /* ���������� ���� �����:
            * ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
            * ���� AskTimeServer() ������� ���������� system_error, ������� ������� ��������
            ���� last_fetched_time
            * ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}