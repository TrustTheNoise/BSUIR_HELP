#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>

using namespace std;

enum ServiceType {
    SERVICE_TYPE_1 = 1,
    SERVICE_TYPE_2,
    SERVICE_TYPE_3,
    SERVICE_TYPE_4,
    SERVICE_TYPE_5
};

struct Client {
    int id;
    ServiceType serviceType;

    Client(int id, ServiceType serviceType) : id(id), serviceType(serviceType) {}
};

// Мьютекс для синхронизации доступа к очереди клиентов
mutex queueMutex;

// Условная переменная для оповещения менеджеров о новом клиенте
condition_variable cv;

queue<Client> clientQueue;

void managerWork(int managerId, ServiceType serviceType1, ServiceType serviceType2) {
    while (true) {

        unique_lock<mutex> lock(queueMutex);
        cv.wait(lock, [] { return !clientQueue.empty(); });

        if (!clientQueue.empty()) {
            Client client = clientQueue.front();
            if (client.serviceType == serviceType1 || client.serviceType == serviceType2) {
                clientQueue.pop();
                this_thread::sleep_for(chrono::milliseconds(100));
                lock.unlock();

                cout << "Менеджер " << managerId << " обслуживает клиента " << client.id << " с услугой " << client.serviceType << endl;
                this_thread::sleep_for(chrono::seconds(3));
            }
        }
    }
}

void generateClients() {
    int clientId = 1;
    while (clientId < 30) {
        ServiceType serviceType = static_cast<ServiceType>(rand() % 5 + 1);

        {
            lock_guard<mutex> lock(queueMutex);
            clientQueue.push(Client(clientId, serviceType));
        }


        cout << "Пришел клиент " << clientId << " с услугой " << serviceType << endl;

        // Оповещение менеджеров о новом клиенте
        cv.notify_all();
        
        clientId++;

        this_thread::sleep_for(chrono::milliseconds(600));
    }
}

int main() {
    srand(time(nullptr));
    setlocale(LC_ALL, "rus");

    thread manager1(managerWork, 1, SERVICE_TYPE_1, SERVICE_TYPE_2);
    thread manager2(managerWork, 2, SERVICE_TYPE_3, SERVICE_TYPE_4);
    thread manager3(managerWork, 3, SERVICE_TYPE_4, SERVICE_TYPE_5);

    thread clientGenerator(generateClients);

    // Ожидание завершения работы потоков
    manager1.join();
    manager2.join();
    manager3.join();
    clientGenerator.join();

    return 0;
}