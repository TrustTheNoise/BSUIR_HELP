package laba6;

import java.util.Random;
import java.util.concurrent.BlockingQueue;

// создаем класс ClientGenerator, который реализует интерфейс Runnable, 
// что позволяет экземплярам этого класса выполняться в отдельных потоках.
class ClientGenerator implements Runnable {
    private BlockingQueue<Client> clientQueue;

    public ClientGenerator(BlockingQueue<Client> clientQueue) {
        this.clientQueue = clientQueue;
    }

    @Override
    public void run() {
        try {
            Random random = new Random();
            int clientId = 1;
            while (clientId <= 30) {
            	// генерирует случайный тип услуги для клиента, используя метод values()
            	// для получения массива всех значений перечисления InsuranceService, 
            	// а затем random.nextInt() для выбора случайного индекса из этого массива.
                InsuranceService service = InsuranceService.values()[random.nextInt(InsuranceService.values().length)];
                
                Client client = new Client(clientId++, service);
                
                clientQueue.put(client);
                
                System.out.println("Client " + client.getId() + " with service " + client.getService() + " is waiting");
                Thread.sleep(300);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}