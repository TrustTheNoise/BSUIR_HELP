package laba6;

import java.util.concurrent.BlockingQueue;

class Manager implements Runnable {
    private int id;
    private InsuranceService service1;
    private InsuranceService service2;
    private BlockingQueue<Client> clientQueue;

    public Manager(int id, InsuranceService service1, InsuranceService service2, BlockingQueue<Client> clientQueue) {
        this.id = id;
        this.service1 = service1;
        this.service2 = service2;
        this.clientQueue = clientQueue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Client client = clientQueue.take();
                if(this.service1 != client.getService() && this.service2 != client.getService()) {
                	clientQueue.offer(client);
                	continue;
                }
                System.out.println("Manager " + id + " is processing client " + client.getId() + " for service " + client.getService());
                Thread.sleep(5000);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
